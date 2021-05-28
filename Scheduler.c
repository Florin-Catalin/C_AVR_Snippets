/*
 * Scheduler.c
 *
 * Created: 4/23/2019 2:11:16 PM
 *  Author: raul.acu
 */ 
#include "Scheduler.h"

static const float Scheduler__cfMS_PER_CYCLE = (TIMER_OVERFLOW / ((FOSC/CLOCK_PRESCALER) / 1000));
static volatile float Scheduler__fMilliseconds = 0;

static volatile Scheduler_ptstTask Scheduler__ptstAllTasks[SCHEDULER_MAX_TASKS];
static volatile uint8_t Scheduler__u8AllTasks_Quota;

static volatile Scheduler_ptstTask Scheduler__ptstQueuedTasks[SCHEDULER_MAX_QUEUE];
static volatile uint8_t Scheduler__u8QueuedTasks_Quota;

float Scheduler_fGetMilliseconds()
{
	/*
	* Disable interrupts in order to avoid unexpected behavior and interferences, store the milliseconds count to a local variable and return it.
	*/
	cli();
	float fMillisecondsLocal = Scheduler__fMilliseconds;
	sei();
	
	return fMillisecondsLocal;
}

Scheduler_tenSTATUS Scheduler_tenInit(void)
{
	/* 
	* Set the Timer/Counter Control Register B`s Clock Select bits based on the chosen prescaler.
	*/
	#if CLOCK_PRESCALER == 8
		TCCR0B &= ~(1<<CS02);
		TCCR0B |= (1<<CS01);
		TCCR0B &= ~(1<<CS00);
	#elif CLOCK_PRESCALER == 64
		TCCR0B &= ~(1<<CS02);
		TCCR0B |= (1<<CS01) | (1<<CS00);
		/*
		* Set the counter start value, in order to count exactly 250 cycles(1ms)
		*/
		TCNT0 = 6;
	#elif CLOCK_PRESCALER == 256
		TCCR0B |= (1<<CS02);
		TCCR0B &= ~(1<<CS01);
		TCCR0B &= ~(1<<CS00);
	#elif CLOCK_PRESCALER == 1024
		TCCR0B |= (1<<CS02) | (1<<CS00);
		TCCR0B &= ~(1<<CS01);
	#else
		return STATUS_PRESCALER_UNDEFINED;
	#endif
	
	/* 
	* Enables timer counter overflow interrupt
	*/
	TIMSK0 |= (1<<TOIE0);
	
	Scheduler__fMilliseconds = 0;
	
	return STATUS_SUCCESS;
}

Scheduler_tenSTATUS Scheduler_tenCreateTask(Scheduler_ptstTask ptstTask, const Scheduler_ptvFunctionPointer ptvFunction, const float fExecutionDelay, const Scheduler_tenTaskType tenTaskType)
{
	/*
	* If the maximum number of tasks has been reached, return with specific status error code.
	*/
	if(Scheduler__u8AllTasks_Quota < SCHEDULER_MAX_TASKS)
	{
		ptstTask->u8TaskId = Scheduler__u8AllTasks_Quota;
	}
	else
	{
		return STATUS_ARRAY_BOUNDS_EXCEEDED;
	}
	/*
	* Verify that the received pointer is valid, otherwise return error code.
	*/
	if(ptvFunction != NULL)
	{
		ptstTask->ptvFunction = ptvFunction;
	}
	else
	{
		return STATUS_NULL_POINTER;	
	}
	
	/*
	* Set the corresponding structure fields as defaults, respectively received as parameters
	*/
	ptstTask->tenTaskType = tenTaskType;
	ptstTask->tenTaskStatus = TASK_WAITING;
	ptstTask->fExecutionDelay = fExecutionDelay;
	ptstTask->fCreationTime = Scheduler_fGetMilliseconds();
	ptstTask->u8QueueIndex = SCHEDULER_MAX_QUEUE + 1;
	
	/*
	* Add the pointer of the structure to the all tasks list.
	*/
	Scheduler__ptstAllTasks[Scheduler__u8AllTasks_Quota] = ptstTask;
	Scheduler__u8AllTasks_Quota++;
	
	return STATUS_SUCCESS;
		
}

Scheduler_tenSTATUS Scheduler_tenEnqueueTask(Scheduler_ptstTask ptstTask)
{
	/*
	* Validate the input parameter`s pointer, task status and add it to the queued tasks list marking it as ready to execute.
	*/
	if(ptstTask != NULL)
	{
		/* 
		* Avoid re-queuing single occurrence tasks
		*/
		if(ptstTask->tenTaskStatus != TASK_TERMINATED)
		{
			ptstTask->u8QueueIndex = Scheduler__u8QueuedTasks_Quota;
			ptstTask->tenTaskStatus = TASK_READY;
			Scheduler__ptstQueuedTasks[Scheduler__u8QueuedTasks_Quota] = ptstTask;
			Scheduler__u8QueuedTasks_Quota++;
		}
		else
		{
			return STATUS_TASK_TERMINATED;
		}
	}
	else
	{
		return STATUS_NULL_POINTER;
	}
	
	return STATUS_SUCCESS;
}

Scheduler_tenSTATUS Scheduler_tenDequeueTask(Scheduler_ptstTask ptstTask)
{
	/*
	* Validate the input parameter`s pointer, task status and marks the task as terminated, removing it from the queue.
	*/
	if(ptstTask != NULL)
	{
		/*
		* Shift the remaining tasks of the queue to fill the gap created by removing the task from the list.
		*/
			for(uint8_t u8Index = ptstTask->u8QueueIndex; u8Index < Scheduler__u8QueuedTasks_Quota - 1 ; u8Index++)
			{
				Scheduler__ptstQueuedTasks[u8Index + 1]->u8QueueIndex--;
				Scheduler__ptstQueuedTasks[u8Index] = Scheduler__ptstQueuedTasks[u8Index + 1];
			}
			
			ptstTask->u8QueueIndex = SCHEDULER_MAX_QUEUE + 1;
			Scheduler__u8QueuedTasks_Quota--;
			
			/*
			* Reset the creation time for recurring tasks.
			*/
			if(ptstTask->tenTaskType == RECURRING_TASK)
			{
				ptstTask->fCreationTime = Scheduler_fGetMilliseconds();
				ptstTask->tenTaskStatus = TASK_WAITING;
			}
			else
			{
				ptstTask->tenTaskStatus = TASK_TERMINATED;
			}
	}
	else
	{
		return STATUS_NULL_POINTER;
	}
	
	return STATUS_SUCCESS;
}

static inline void Scheduler__vEnqueueWaitingTasks()
{
	/*
	* Iterate the tasks list and enqueues tasks, marking them as ready to execute when the millisecond counter reaches the required value.
	*/
	for(uint8_t u8Index = 0; u8Index < Scheduler__u8AllTasks_Quota; u8Index++)
	{
		if(Scheduler__ptstAllTasks[u8Index]->tenTaskStatus == TASK_WAITING)
		{
			if(Scheduler_fGetMilliseconds() - Scheduler__ptstAllTasks[u8Index]->fCreationTime >= Scheduler__ptstAllTasks[u8Index]->fExecutionDelay)
				Scheduler_tenEnqueueTask(Scheduler__ptstAllTasks[u8Index]);
		}
	}
}

static inline void Scheduler__vExecuteReadyTasks()
{
	/*
	* Execute the function assigned to the task, if in queue.
	*/
	for(uint8_t u8Index; u8Index < Scheduler__u8QueuedTasks_Quota; u8Index++)
	{
		Scheduler__ptstQueuedTasks[u8Index]->ptvFunction();
		Scheduler_tenDequeueTask(Scheduler__ptstQueuedTasks[u8Index]);
	}
}

ISR(TIMER0_OVF_vect)
{
	/*
	* For clock prescaler of 64, count exactly 250 cycles in a millisecond.
	* Otherwise, use the formula.
	*/
	#if CLOCK_PRESCALER == 64
		Scheduler__fMilliseconds += 1.00;
		TCNT0					  = 6;
	#else
		Scheduler__fMilliseconds += Scheduler__cfMS_PER_CYCLE;
	#endif

	Scheduler__vEnqueueWaitingTasks();
	Scheduler__vExecuteReadyTasks();
	
}

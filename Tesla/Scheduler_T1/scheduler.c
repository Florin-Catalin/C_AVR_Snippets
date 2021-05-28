
/*
 * OS.c
 *
 * Created: 5/5/2021 11:51:37 PM
 *  Author: florin.ungureanu
 */ 
#include "scheduler.h"


static Scheduler_tstTask    Scheduler_taskArray[Scheduler_MAX_TASK_NUM];    /**< Variables and information for every single task. */
static uint8_t      Scheduler_u8TaskNumber = 0u;               /**< Number of the registered tasks. */


/**
 * @brief   This function registers the tasks.
 *          At the beginning there is an error check for registration.
 *          If everything is good, the input values are saved.
 * @param   function: The task we want to call periodically.
 * @param   default_time_burst: The time it gets called periodically.
 * @param   default_state: The state it starts (recommended state: BLOCKED).
 * @return  null
 */
void Scheduler_vTaskCreate(Scheduler_ptvFunctionPointer ptvFunction, uint8_t u8DefaultTimeBurst, Scheduler_tenTaskState tenDefaultState)
{
        Scheduler_taskArray[Scheduler_u8TaskNumber].ptvFunction = ptvFunction;
        Scheduler_taskArray[Scheduler_u8TaskNumber].u8TimeBurst = u8DefaultTimeBurst;
        Scheduler_taskArray[Scheduler_u8TaskNumber].tenState = tenDefaultState;
        Scheduler_taskArray[Scheduler_u8TaskNumber].u8TimeCount = 1u;
        Scheduler_u8TaskNumber++;
    
}

/**
 * @brief   This function keeps track of the tasks' time and puts them into READY state.
 *          This function SHALL be called in a timer interrupt.
 * @param   void
 * @return  void
 */
 void Scheduler_vTaskTimer(void)
{
	TCNT5 = 63974;
    for (uint8_t i = 0u; i < Scheduler_u8TaskNumber; i++)
    {
        /* Ignore SUSPENDED tasks. */
        if (SUSPENDED != Scheduler_taskArray[i].tenState)
        {
            /* Put it into READY state. */
            if (Scheduler_taskArray[i].u8TimeBurst <= Scheduler_taskArray[i].u8TimeCount)
            {
                Scheduler_taskArray[i].u8TimeCount = 1u;
                Scheduler_taskArray[i].tenState	= READY;
            }
            /* Or keep counting. */
            else
            {
                Scheduler_taskArray[i].u8TimeCount++;
            }
        }
    }
}

void Scheduler_vTimerInit(void)
{	/* Set the timer interrupt to fire every 1 sec. */
	TCCR5B = (1 << CS52);
	//TCCR5B = (1 << CS50) | ( 1 << CS52);
	//TCCR5B = (1 << CS51);
	TIMSK5 = (1 << TOIE5);
	sei();

	
}
/**
 * @brief   This function calls the READY tasks and then puts them back into BLOCKED state.
 *          This function SHALL be called in the infinite loop.
 * @param   void
 * @return  void
 */
void Scheduler_vTaskExecution(void)
{
  
  for(;;)
    for (uint8_t i = 0u; i < Scheduler_u8TaskNumber; i++)
    { 
        /* If it is ready, then call it.*/
        if (READY == Scheduler_taskArray[i].tenState)
        {
            Scheduler_taskArray[i].ptvFunction();
			
            Scheduler_taskArray[i].tenState = BLOCKED;
        }
	}
}


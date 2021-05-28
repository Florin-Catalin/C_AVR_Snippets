/*
 * Scheduler.h
 *
 * Created: 4/23/2019 2:11:03 PM
 *  Author: raul.acu
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint-gcc.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef FOSC
#define FOSC 16000000
#endif

#ifndef CLOCK_PRESCALER
#define CLOCK_PRESCALER 64
#endif
#define TIMER_OVERFLOW 256

#define SCHEDULER_MAX_TASKS 255
#define SCHEDULER_MAX_QUEUE 25

typedef void (*Scheduler_ptvFunctionPointer)(void);

typedef enum _Scheduler_tenSTATUS
{
	STATUS_SUCCESS,
	STATUS_UNSUCCESSFUL,
	STATUS_NULL_POINTER,
	STATUS_ARRAY_BOUNDS_EXCEEDED,
	STATUS_TASK_NOT_READY,
	STATUS_TASK_TERMINATED,
	STATUS_PRESCALER_UNDEFINED
}Scheduler_tenSTATUS;

typedef enum _Scheduler_tenTaskStatus
{
	TASK_READY,
	TASK_WAITING,
	TASK_TERMINATED
}Scheduler_tenTaskStatus;

typedef enum _Scheduler_tenTaskType
{
	SINGLE_OCCURRENCE_TASK,
	RECURRING_TASK
}Scheduler_tenTaskType;

typedef struct _Scheduler_tstTask
{
	uint8_t	u8TaskId;
	uint8_t u8QueueIndex;
	Scheduler_ptvFunctionPointer ptvFunction;
	float fExecutionDelay;
	float fCreationTime;
	Scheduler_tenTaskType tenTaskType;
	Scheduler_tenTaskStatus tenTaskStatus;
}Scheduler_tstTask, *Scheduler_ptstTask;

float Scheduler_fGetMilliseconds();
Scheduler_tenSTATUS Scheduler_tenInit(void);
Scheduler_tenSTATUS Scheduler_tenCreateTask(Scheduler_ptstTask ptstTask, Scheduler_ptvFunctionPointer ptvFunction, float fExecutionDelay, Scheduler_tenTaskType tenTaskType);
Scheduler_tenSTATUS Scheduler_tenEnqueueTask(Scheduler_ptstTask ptstTask);
Scheduler_tenSTATUS Scheduler_tenDequeueTask(Scheduler_ptstTask ptstTask);

#endif /* SCHEDULER_H_ */
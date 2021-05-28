
/*
 * OS.h
 *
 * Created: 5/5/2021 11:50:28 PM
 *  Author: florin.ungureanu
 */ 
#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>

#define Scheduler_MAX_TASK_NUM ((uint8_t)10u)  /**< Maximal task number that can be registered. */
typedef void (*Scheduler_ptvFunctionPointer)(void);           /**< Function pointer for registering tasks. */

/**
 * States of the tasks.
 */
typedef enum
{
    BLOCKED ,                        /**< In the BLOCKED state the task waits for the timer to put it into READY state. */
    READY,                              /**< In the READY state the task is ready to be called and executed in the main function. */
    SUSPENDED                           /**< In the SUSPENDED state the task is ignored by the timer and executer. */
} Scheduler_tenTaskState;

/**
 * Variables of the tasks.
 */
typedef struct
{
    Scheduler_ptvFunctionPointer      ptvFunction;               /**< This is the task that gets called periodically. */
    uint8_t     u8TimeBurst;             /**< The period we want to call it. */
    uint8_t     u8TimeCount;               /**< Counter, if it reaches the time_burst, then the timer puts it into READY state. */
    Scheduler_tenTaskState    tenState;                  /**< The current state of the task. */
} Scheduler_tstTask;




/**
 * Functions.
 */
void Scheduler_vTimerInit();
void Scheduler_vTaskCreate(Scheduler_ptvFunctionPointer ptvTask, uint8_t u8DefaultTimeBurst, Scheduler_tenTaskState tenDefaultState);
 void Scheduler_vTaskTimer(void);
void Scheduler_vTaskExecution(void);


#endif /* SCHEDULER_H_ */
/*
 * ultrasonic.h
 *
 * Created: 4/23/2021 2:59:44 PM
 *  Author: florin.ungureanu
 */ 

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/*  HC_SR04 ULTRASONIC SENSOR using Atmega2560
 *  Trigger pin = PC4 / Digital pin 33
 *  Echo pin    = ICP4 / Digital pin 49
 */

#include <avr/delay.h>
#include <avr/interrupt.h>
#include "../GPIO_T1/gpio.h"





/*
 the sensor gives accurate and reliable results between 3-70 cm. therefore larger or smaller values are unusable
*/
#define Ultrasonic_SENSOR_UPPER_BOUND 70
#define Ultrasonic_SENSOR_LOWER_BOUND 3
#define Ultrasonic_SENSOR_OUT_OF_BOUNDS 0 

#define Ultrasonic_HIGH 1
#define Ultrasonic_LOW 0

#define Ultrasonic_INPUT 0
#define Ultrasonic_OUTPUT 1

#define Ultrasonic_Trigger_Period 10
/*
1/58 = 0.034/2 cm/µs  =~  0.017
*/
#define Ultrasonic_SPEED_OF_SOUND_DIVIDED_BY_TWO_INVERSED 58

#define Ultrasonic_TRIGGER_DDR			DDRC
#define Ultrasonic_ECHO_DDR			DDRL
#define Ultrasonic_TRIGGER				PINC4
#define Ultrasonic_TRIGGER_PIN 33
#define Ultrasonic_ECHO				PINL0
#define Ultrasonic_ECHO_PIN 49
#define Ultrasonic_TRIGGER_PORT		PORTC

/*
 16MHz / 64 = 160 000 000 / 64 = 250 000 counts/second => 1 000 000 us /250 000 counts  = 4 us/count
*/
#define Ultrasonic_MICROSEC_PER_TICK 4

#define   Ultrasonic_NEXT_TIME_DETECT_FALLING_EDGE TCCR4B &= ~(1<<ICES4)
#define   Ultrasonic_NEXT_TIME_DETECT_RISING_EDGE  TCCR4B |= (1<<ICES4)
/*
TIMER INIT MACROS
*/
 /* ICP4 (Input Capture Interrupt) , DIGITAL PIN 49
   *   ISR(TIMER4_CAPT_vect) when the signal on the ICP pin goes from 0 to 1 (raising edge).
   *   The method contains a if statement to see if it was called during a raising edge or falling edge.
   *   On a raising edge it switches the ICP to falling edge detection and then stores the start time.
   *   On a falling edge it switches the ICP to raising edge detection and gets the end time to calculate the distance in cm
   */
	 /**
   the noise canceler introduces additional four system clock cycles of delay from a change applied to the input,
    to the update of the ICRn Register. The noise canceler uses the system clock and is therefore not affected by the prescaler
   */
#define Ultrasonic_SET_INPUT_CAPTURE_NOISE_CANCELER        TCCR4B |= (1 << WGM42) | (1 << ICNC4)
/*
 prescaler 64 Clock/64
  https://bennthomsen.files.wordpress.com/2011/12/clockselecttable1.png
*/
#define Ultrasonic_SET_PRESCALAR_64					  TCCR4B |= 1 << CS41 | 1 << CS40

 /*
   *  ICIE: Input Capture Interrupt Enable
      When this bit is written to '1', and the I-flag in the Status Register is set (interrupts globally enabled), the
      Timer/Counter1 Input Capture interrupt is enabled. The corresponding Interrupt Vector is executed when
      the ICF Flag, located in TIFR1, is set.
      When a capture is triggered according to the ICESn setting, the counter value is copied into the Input Capture Register
      (ICRn). The event will also set the Input Capture Flag (ICFn), and this can be used to cause an Input Capture
      Interrupt, if this interrupt is enabled.
      When the ICRn is used as TOP value (see description of the WGMn3:0 bits located in the TCCRnA and the
      TCCRnB Register), the ICPn is disconnected and consequently the input capture function is disabled.
   */
 
#define Ultrasonic_SET_INPUT_CAPTURE_INTERRUPT_ENABLE    TIMSK4 |= 1 << OCIE4A | 1 << ICIE4
#define Ultrasonic_SET_GLOBAL_INTERRUPTS              sei()

#define  Ultrasonic_SET_INPUT_CAPTURE_ON_RISING_EDGE   TCCR4B |= 1 << ICES4
 /**
   * This bit selects which edge on the Input Capture pin (ICP1) that is used to trigger a capture event. When
    the ICES1 bit is written to zero, a falling (negative) edge is used as trigger, and when the ICES1 bit is
    written to '1', a rising (positive) edge will trigger the capture.
    When a capture is triggered according to the ICES1 setting, the counter value is copied into the Input
    Capture Register (ICR1). The event will also set the Input Capture Flag (ICF1), and this can be used to
    cause an Input Capture Interrupt, if this interrupt is enabled.
    When the ICR1 is used as TOP value (see description of the WGM1[3:0] bits located in the TCCR1A and
    the TCCR1B Register), the ICP1 is disconnected and consequently the Input Capture function is
    disabled.
   */
/*  Input Capture Unit
   * https://www.electronicwings.com/avr-atmega/atmega1632-timer-input-capture-mode
   */
#define Ultrasonic_DETECTED_RISING_EDGE TCCR4B & (1<<ICES4)
 //the value stored is continuously compared with the counter value
 //(TCNTn). A match can be used to generate an Output Compare interrupt, or to generate a waveform output on the
 // OCnx pin
 //http://www.avrbeginners.net/architecture/timers/timers.html
#define Ultrasonic_SET_OUTPUT_COMPARE_REGISTER   OCR4A = 17500
#define Ultrasonic_SAVE_CURRENT_COUNT(X) ( X = ICR4)
/*
 * Function: Ultrasonic_u32GetDistance
 * ----------------------------
    a getter function for the global variable distance that stores the distance and filter the unreliable values
 
 *   has no parameters
 *
 *   returns:  0 if the value is unusable or a value between the defined bounds ( default : 3 and 70 cm ) 
 */
uint32_t Ultrasonic_u32GetDistance();

/*
 * Function: Ultrasonic_vTimerInit
 * ----------------------------
   setup for the 4th timer, as a plus it also sets the global interrupts 
 
 *   has no parameters
 *
 *   returns: null
 */
void Ultrasonic_vTimerInit();
/*
 * Function: Ultrasonic_vSetPins
 * ----------------------------
    setup function that set the echo pin as input and trigger as output
 *   has no parameters
 *
 *   returns: null 
 */
void Ultrasonic_vSetPins();

#endif //ULTRASONIC_H_
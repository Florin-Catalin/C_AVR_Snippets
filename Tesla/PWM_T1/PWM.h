/*
 * PWM.h
 *
 * Created: 4/14/2021 1:54:52 PM
 *  Author: adrian.marginean
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

typedef uint8_t u8PinNumber;
typedef uint16_t u16Duty;

/*
  This function set the register for a specific pin, set the registers for that pin in PWM fast mode with a 256 prescaler
  uint8_t u8PinNumber -input- represent the pin number
  -the function type is void (don't return something)
*/
void PWM_vSetup(u8PinNumber);

/*
  This function calculate the duty cycle and put the result on a pin
  uint8_t u8PinNumber -input- represent the pin number
  uint16_t u16Duty -input- represent the percentage of duty from 0 to 100.
  -the function type is void (don't return something)
*/
void PWM_vSetPWMDuty(u8PinNumber,u16Duty);


#endif /* PWM_H_ */
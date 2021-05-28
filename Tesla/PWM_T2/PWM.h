/*
 * PWM.h
 *
 * Created: 4/16/2021 4:16:33 AM
 *  Author: raul.garbou
 */ 

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

void PWM_init(uint8_t u8Pin);
void PWM_Duty_Cycle(uint8_t u8Pin, uint16_t u16Value);
#endif
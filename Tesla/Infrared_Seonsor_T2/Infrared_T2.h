/*
 * Infrared_T2.h
 *
 * Created: 4/20/2021 1:36:42 PM
 *  Author: raul.garbou
 */ 

#ifndef Infrared_T2_H_
#define Infrared_T2_H_

#include <avr/io.h>
#include "gpio.h"

#define u8MaxDistance (uint8_t) 80
#define u8MinDistance (uint8_t) 10
#define u16MaxVoltage (uint16_t) 4800
#define u8SubtractionValue (uint8_t) 20
#define u8NumberOfAdditions (uint8_t) 3
#define u8MuxSet (uint8_t) 7
#define u8OffsetNumber (uint8_t) 8

/*
This function sets the registers needed for reading the sensor
and sets the prescaler to 8
*/
void Infrared_vAnalog_Init(uint8_t u8Pin_input);

/*
This function returns the Voltage value the sensor gives to the analog pin
uint8_t u8Pin_input - The pin that needs to be read
*/
uint16_t Infrared_u16Analog_Read(uint8_t u8Pin_input);

/*
This function returns the distance detected by sensor in cm
uint8_t u8Pin_input - The pin that needs to be read
*/
uint16_t Infrared_u16Analog_Distance(uint8_t u8Pin_input);

#endif /* Infrared_T2_H_ */
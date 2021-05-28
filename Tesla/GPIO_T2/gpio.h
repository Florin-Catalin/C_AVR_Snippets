/*
 * gpio.h
 *
 * Created: 4/15/2021 3:31:55 PM
 *  Author: anamaria.rosca
 */ 


#ifndef GPIO_H_
#define GPIO_H_


#include <avr/io.h>
#include <util/delay.h>

// function used to set the mode of a pin
// setting a 0 for the pin will indicate an input and a 1 an output
// variable u8Pin will indicate the number of the pin
// variable u8Mode will indicate the mode of the pin
// type of the function is void so it won't return anything
void GPIO_vSetUp(uint8_t u8Pin,uint8_t u8Mode);

// function used to set the value of the pin
// for value 0 the pin will indicate low and for 1 high
// variable u8Pin will indicate the number of the pin
// variable u8Val will indicate the value
// type of the function is void so it won't return anything
void GPIO_vDigitalWrite(uint8_t u8Pin, uint8_t u8Val);

// function used to read the value from a specified pin, either high or low
// variable u8Pin will indicate the number of the pin
// type of the function is int and it will return the value that we have on the pin
int GPIO_vDigitalRead(uint8_t u8Pin);

//function used to activate the pull up resistor of the pin
// u8Pin will be the number of the pin
// type of the function is void so it won't return anything
void GPIO_vPullUp(uint8_t u8Pin);


#endif /* GPIO_H_ */
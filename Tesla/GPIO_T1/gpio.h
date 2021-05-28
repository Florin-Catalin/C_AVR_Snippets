/*
 * IncFile1.h
 *
 * Created: 4/9/2021 1:36:28 PM
 *  Author: alin.pop
 */ 


#ifndef gpio_H_
#define gpio_H_

#include <avr/io.h>

typedef uint8_t u8Pin;
typedef uint8_t u8Mode;
typedef uint8_t u8Value;

/*function which set a pin, given as a parameter, as input or output, depends on the u8Mode parameter
  uint8_t u8Pin - input value - pin to be set
  uint8_t u8Mode - input value - mode of the pin : 0 - input and 1 - output
  The function type is void, so it won't return anything.
*/
void gpio_vPinMode(u8Pin, u8Mode);

/*function which set a pin value, given as parameter, with the value also given as parameter
  uint8_t u8Pin - input value - pin to be set
  uint8_t u8Value - input value - 0 - LOW, 1 - HIGH
  The function type is void, so it won’t return anything.
*/
void gpio_vSetState(u8Pin, u8Value);

/*function which read the value of a pin, 
  uint8_t u8Pin - input value - the pin from where we read the value
  return 0 if our pin is LOW or a positive value if we have HIGH on pin
*/
uint8_t gpio_u8ReadState(u8Pin);

/*function which activate the internal pullup resistor on the required pin, 
  uint8_t u8Pin - input value - the pin on which we want to activate the pullup resistor
  The function type is void, so it won’t return anything.
*/
void gpio_vActivatePullupRes(u8Pin);


#endif /* gpio_H_ */
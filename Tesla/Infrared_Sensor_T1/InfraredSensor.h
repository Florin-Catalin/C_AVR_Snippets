/*
 * InfraredSensor.h
 *
 * Created: 4/27/2021 3:27:17 PM
 *  Author: adrian.marginean
 */ 


#ifndef INFRAREDSENSOR_H_
#define INFRAREDSENSOR_H_

typedef uint8_t u8PinNumber;
typedef uint8_t u8Distance;

#define InfraredSensor_u8MaxDistance (uint8_t) 80
#define InfraredSensor_u8MinDistance (uint8_t) 10
#define InfraredSensor_u8InputMode (uint8_t) 0
#define InfraredSensor_u16MaxVoltage (uint16_t) 4800
#define InfraredSensor_u8AnalogError (uint8_t) 20

typedef enum {
	false = 0,
	true = 1
} t_bool;



/*
  This function is just for digital pins and return true if the sensor
  detect an obstacle and on the other hand false.
  uint8_t u8PinNumber - input - represent the pin number
  -the function type is bool return true(1) or false(0)
*/
t_bool InfraredSensor_u8IsObstacleDigitalPin(u8PinNumber);

/*
 This function set the registers for read the analog value
  -the function type is void (don't return something)
*/
void InfraredSensor_vInitADC();

/*
  This function return the analog value, a number from 0 to 1023
  uint8_t u8PinNumber - input- represent the analog pin from 0 to 15
  -the function type is uint16_t and return a number between 0 and 1023
*/
uint16_t InfraredSensor_u16ReadADC(u8PinNumber);

/*
  This function compute the distance from sensor to object, the range 
  is from 10 to 80. The formula is just for sensor: SHARP 2Y0A21
  uint8_t u8PinNumber - input- represent the analog pin from 0 to 15
  -the function type is uint8_t and return a number between 10 and 80
*/
uint8_t InfraredSensor_u8ComputeDistanceSharpSensor(u8PinNumber);

/*
  This function return true if the object is closer then the distance(u8Distance)
  uint8_t u8PinNumber - input- represent the analog pin from 0 to 15
  uint8_t u8Distance -input- represent the distance from 10 to 80
  -the function type is bool return true(1) or false(0)
*/
t_bool InfraredSensor_u8IsObstacleSharpSensor(u8PinNumber,u8Distance);

#endif /* INFRAREDSENSOR_H_ */
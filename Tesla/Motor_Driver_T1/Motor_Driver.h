/*
 * Motor_Driver.h
 *
 * Created: 4/21/2021 11:30:25 AM
 *  Author: alin.pop
 */ 


#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

#include "gpio.h"
#include "PWM.h"

#define Motor_Driver_u8Input1 (uint8_t) 0x03
#define Motor_Driver_u8Input2 (uint8_t) 0x04
#define Motor_Driver_u8Input3 (uint8_t) 0x05
#define Motor_Driver_u8Input4 (uint8_t) 0x06
#define Motor_Driver_u8EnableA (uint8_t) 0x02
#define Motor_Driver_u8EnableB (uint8_t) 0x0B
#define Motor_Driver_u8Forward (uint8_t) 0x00
#define Motor_Driver_u8Backward (uint8_t) 0x01
#define Motor_Driver_u8Right (uint8_t) 0x02
#define Motor_Driver_u8Left (uint8_t) 0x03
#define Motor_Driver_u8High (uint8_t) 0x01
#define Motor_Driver_u8Low (uint8_t) 0x00
#define Motor_Driver_u8Output (uint8_t) 0x01
#define Motor_Driver_u8MinSpeed (uint8_t) 0x15
#define Motor_Driver_u8MaxSpeed (uint8_t) 0x64

typedef uint8_t u8Direction;
typedef uint16_t u16LefthWheelSpeed;
typedef uint16_t u16RightWheelSpeed;

/*function which set the mode of the required pins for motor driver
  The function type is void, so it won't return anything.
*/
void Motor_Driver_vSetup();

/*function which set the initial state of the pins required for motor driver, also set the PWM pins
  The function type is void, so it won't return anything.
*/
void Motor_Driver_vInit();

/*function which action the motors, with the required speed on each wheel and in the required direction
  uint16_t u16LeftWheelSpeed - used to set the speed of the left wheel (range 0 - 100)
  uint16_t u16RightWheelSpeed - used to set the speed of the right wheel (range 0 - 100)
  uint8_t u8Direction - used to set the direction (0 - forward, 1 - backward, 2 - right, 3 - left, any other number - brake)
  The function type is void, so it won't return anything.
*/
void Motor_Driver_vMove(uint16_t u16LeftWheelSpeed, uint16_t u16RightWheelSpeed, uint8_t u8Direction);


#endif /* MOTOR_DRIVER_H_ */
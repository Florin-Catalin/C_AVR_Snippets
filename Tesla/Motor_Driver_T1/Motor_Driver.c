/*
 * Motor_Driver.c
 *
 * Created: 4/21/2021 11:30:10 AM
 *  Author: alin.pop
 */ 

#include "Motor_Driver.h"

void Motor_Driver_vSetup(){
	gpio_vPinMode(Motor_Driver_u8Input1, Motor_Driver_u8Output); //set required pins as output
	gpio_vPinMode(Motor_Driver_u8Input2, Motor_Driver_u8Output);
	gpio_vPinMode(Motor_Driver_u8Input3, Motor_Driver_u8Output);
	gpio_vPinMode(Motor_Driver_u8Input4, Motor_Driver_u8Output);
	gpio_vPinMode(Motor_Driver_u8EnableA, Motor_Driver_u8Output);
	gpio_vPinMode(Motor_Driver_u8EnableB, Motor_Driver_u8Output);
}

void Motor_Driver_vInit(){
	PWM_vSetup(Motor_Driver_u8EnableA); //set PWM pins
	PWM_vSetup(Motor_Driver_u8EnableB);
	gpio_vSetState(Motor_Driver_u8Input1, Motor_Driver_u8Low); //set the initial state for motor driver s brake
	gpio_vSetState(Motor_Driver_u8Input2, Motor_Driver_u8Low);
	gpio_vSetState(Motor_Driver_u8Input3, Motor_Driver_u8Low);
	gpio_vSetState(Motor_Driver_u8Input4, Motor_Driver_u8Low);
	PWM_vSetPWMDuty(Motor_Driver_u8EnableA, Motor_Driver_u8Low);
	PWM_vSetPWMDuty(Motor_Driver_u8EnableB, Motor_Driver_u8Low);
}

void Motor_Driver_vMove(uint16_t u16RightWheelSpeed, uint16_t u16LefttWheelSpeed, uint8_t u8Direction){
	if(u16LefttWheelSpeed < Motor_Driver_u8MinSpeed) //if we set a lower value than the limit (20) set the value at 20
		u16LefttWheelSpeed = Motor_Driver_u8MinSpeed;
	else if(u16LefttWheelSpeed > Motor_Driver_u8MaxSpeed) //if we set a higher value than the limit (100) set the value at 100
		u16LefttWheelSpeed = Motor_Driver_u8MaxSpeed;
		
	if(u16RightWheelSpeed < Motor_Driver_u8MinSpeed)
		u16RightWheelSpeed = Motor_Driver_u8MinSpeed;
	else if(u16RightWheelSpeed > Motor_Driver_u8MaxSpeed)
		u16RightWheelSpeed = Motor_Driver_u8MaxSpeed;
		
	switch(u8Direction){
		case Motor_Driver_u8Forward: //in case we want to go forward
			gpio_vSetState(Motor_Driver_u8Input1, Motor_Driver_u8High); //set the direction pins in order to go forward
			gpio_vSetState(Motor_Driver_u8Input2, Motor_Driver_u8Low);
			gpio_vSetState(Motor_Driver_u8Input3, Motor_Driver_u8Low);
			gpio_vSetState(Motor_Driver_u8Input4, Motor_Driver_u8High);
			PWM_vSetPWMDuty(Motor_Driver_u8EnableA, u16LefttWheelSpeed); //set the speed of the motors
			PWM_vSetPWMDuty(Motor_Driver_u8EnableB, u16RightWheelSpeed);
		break;
				
		case Motor_Driver_u8Backward: //in case we want to go back
			gpio_vSetState(Motor_Driver_u8Input1, Motor_Driver_u8Low);
			gpio_vSetState(Motor_Driver_u8Input2, Motor_Driver_u8High);
			gpio_vSetState(Motor_Driver_u8Input3, Motor_Driver_u8High);
			gpio_vSetState(Motor_Driver_u8Input4, Motor_Driver_u8Low);
			PWM_vSetPWMDuty(Motor_Driver_u8EnableA, u16LefttWheelSpeed);
			PWM_vSetPWMDuty(Motor_Driver_u8EnableB, u16RightWheelSpeed);
		break;
		
		case Motor_Driver_u8Right: //in case we want to go right
			gpio_vSetState(Motor_Driver_u8Input1, Motor_Driver_u8Low);
			gpio_vSetState(Motor_Driver_u8Input2, Motor_Driver_u8High);
			gpio_vSetState(Motor_Driver_u8Input3, Motor_Driver_u8Low);
			gpio_vSetState(Motor_Driver_u8Input4, Motor_Driver_u8High);
			PWM_vSetPWMDuty(Motor_Driver_u8EnableA, u16LefttWheelSpeed);
			PWM_vSetPWMDuty(Motor_Driver_u8EnableB, u16RightWheelSpeed);
		break;
		
		case Motor_Driver_u8Left: //in case we want to go left
			gpio_vSetState(Motor_Driver_u8Input1, Motor_Driver_u8High);
			gpio_vSetState(Motor_Driver_u8Input2, Motor_Driver_u8Low);
			gpio_vSetState(Motor_Driver_u8Input3, Motor_Driver_u8High);
			gpio_vSetState(Motor_Driver_u8Input4, Motor_Driver_u8Low);
			PWM_vSetPWMDuty(Motor_Driver_u8EnableA, u16LefttWheelSpeed);
			PWM_vSetPWMDuty(Motor_Driver_u8EnableB, u16RightWheelSpeed);
		break;
		
		default: //in case we want to stop
			gpio_vSetState(Motor_Driver_u8Input1, Motor_Driver_u8Low);
			gpio_vSetState(Motor_Driver_u8Input2, Motor_Driver_u8Low);
			gpio_vSetState(Motor_Driver_u8Input3, Motor_Driver_u8Low);
			gpio_vSetState(Motor_Driver_u8Input4, Motor_Driver_u8Low);
		break;
	}
}
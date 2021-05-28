/*
 * GccApplication1.c
 *
 * Created: 4/5/2021 1:54:08 PM
 * Author : alin.pop
 */ 

#include "Motor_Driver.h"
#include "ultrasonic.h"
#include "uart.h"
#include "InfraredSensor.h"

#define Main_SharpLeft (uint8_t) 0x00
#define Main_SharpRight (uint8_t) 0x01
#define Main_SensorDeactivate (uint8_t) 0x00
#define Main_UltrasonicMinValue (uint8_t) 0x1E
#define Main_SharpMinValue (uint8_t) 0x1E
#define Main_ForwardDirection (uint8_t) 0x00
#define Main_BackwardDirection (uint8_t) 0x01
#define Main_LeftDirection (uint8_t) 0x02
#define Main_RightDirection (uint8_t) 0x03
#define Main_StopDirection (uint8_t) 0x05
#define Main_ForwardMotorSpeed (uint8_t) 0x1E
#define Main_TurnMotorSpeed (uint8_t) 0x20
#define Main_BluetoothForwardMotorSpeed (uint8_t) 0x15
#define Main_BluetoothTurnMotorSpeed (uint8_t) 0x20
#define Main_BuzzPin (uint8_t) 0x0A
#define Main_Output (uint8_t) 0x01
#define Main_MotorStop (uint8_t) 0x00
#define Main_NullValue (uint8_t) 0x00
#define Main_BuzzerMaxValue (uint8_t) 0x46
#define Main_BuzzerStart (uint8_t) 0x00
#define Main_BuzzerStop (uint8_t) 0x01

void Main_vBuzz(uint8_t u8_tone, uint8_t u8_stop){
	gpio_vPinMode(Main_BuzzPin, Main_Output);
	PWM_vSetup(Main_BuzzPin);
	if(u8_stop == Main_NullValue){
		for(uint8_t u8_i = Main_NullValue; u8_i <= Main_BuzzerMaxValue; u8_i += u8_tone){
			PWM_vSetPWMDuty(Main_BuzzPin, u8_i);//activate buzzer
		}
	}
	else{
		TCCR2A = Main_NullValue;
		TCCR2B = Main_NullValue;
		PWM_vSetPWMDuty(Main_BuzzPin, Main_NullValue);//stop buzzer
	}
}

void Main_vDirtyDelayRight(void)//used to move the robot ~= 90° to the right
{
	for(volatile uint32_t u32_i = Main_NullValue; u32_i < 32000u; u32_i++)
		for(volatile uint32_t u32_j = Main_NullValue; u32_j < 5u; u32_j++);
}

void Main_vDirtyDelayLeft(void)//used to move the robot ~= 90° to the left
{
	for(volatile uint32_t u32_i = Main_NullValue; u32_i < 30000u; u32_i++)
		for(volatile uint32_t u32_j = Main_NullValue; u32_j < 5u; u32_j++);
}

int main(void)
{
	Motor_Driver_vSetup();
	Motor_Driver_vInit();
	ultrasonic_vSetPins();
	ultrasonic_vTimerInit();
	InfraredSensor_vInitADC();
	UART_vSerialBegin(9600);
	uint8_t u8_ReceivedCharacter;
	
    while (1) 
    {
		u8_ReceivedCharacter = UART_ui8SerialReadByte();
		if(u8_ReceivedCharacter == 'S') //enter Bluetooth controlled mode			
			while(1){
				u8_ReceivedCharacter = UART_ui8SerialReadByte();
				if(u8_ReceivedCharacter == 'F'){//when receive F character go forward
					Motor_Driver_vMove(Main_BluetoothForwardMotorSpeed, Main_BluetoothForwardMotorSpeed, Main_ForwardDirection);
					Main_vBuzz(6, Main_BuzzerStop);
				}

				if(u8_ReceivedCharacter == 'R'){//when receive R character go right ~= 90°
					Main_vBuzz(6, Main_BuzzerStop);
					Motor_Driver_vMove(Main_BluetoothTurnMotorSpeed, Main_BluetoothTurnMotorSpeed, Main_LeftDirection);
					Main_vDirtyDelayRight();
					Motor_Driver_vMove(Main_MotorStop, Main_MotorStop, Main_StopDirection);
				}
				
				if(u8_ReceivedCharacter == 'L'){//when receive L character go left ~= 90°
					Main_vBuzz(6, Main_BuzzerStop);
					Motor_Driver_vMove(Main_BluetoothTurnMotorSpeed, Main_BluetoothTurnMotorSpeed, Main_RightDirection);
					Main_vDirtyDelayLeft();
					Motor_Driver_vMove(Main_MotorStop, Main_MotorStop, Main_StopDirection);
				}
				
				if(u8_ReceivedCharacter == 'B'){//when receive B character go backwards
					Main_vBuzz(6, Main_BuzzerStop);
					Motor_Driver_vMove(Main_BluetoothForwardMotorSpeed, Main_BluetoothForwardMotorSpeed, Main_BackwardDirection);
				}
				
				if(u8_ReceivedCharacter == 'S'){//when receive S character stop
					Main_vBuzz(6, Main_BuzzerStop);
					Motor_Driver_vMove(Main_MotorStop, Main_MotorStop, Main_StopDirection);
				}
			}
			
		if(u8_ReceivedCharacter == 'Q')//enter free mode
			while(1){
				while((ultrasonic_u32GetDistance() > Main_UltrasonicMinValue || ultrasonic_u32GetDistance() == Main_SensorDeactivate) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpLeft, Main_SharpMinValue) == Main_SensorDeactivate && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpRight, Main_SharpMinValue) == Main_SensorDeactivate){
					Motor_Driver_vMove(Main_ForwardMotorSpeed, Main_ForwardMotorSpeed, Main_ForwardDirection);//when sensors see nothing go forward
					Main_vBuzz(6, Main_BuzzerStop);
				}
		
				while((ultrasonic_u32GetDistance() > Main_UltrasonicMinValue || ultrasonic_u32GetDistance() == Main_SensorDeactivate) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpLeft, Main_SharpMinValue) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpRight, Main_SharpMinValue)){
					Motor_Driver_vMove(Main_ForwardMotorSpeed, Main_ForwardMotorSpeed, Main_ForwardDirection);//when ultrasonic sensor see nothing and both sharps see something go forward
					Main_vBuzz(6, Main_BuzzerStop);
				}
		
				while((ultrasonic_u32GetDistance() < Main_UltrasonicMinValue && ultrasonic_u32GetDistance() != Main_SensorDeactivate) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpLeft, Main_SharpMinValue) == Main_SensorDeactivate && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpRight, Main_SharpMinValue) == Main_SensorDeactivate){
					Motor_Driver_vMove(Main_TurnMotorSpeed, Main_TurnMotorSpeed, Main_LeftDirection);//when only ultrasonic sensor see something go left
					Main_vBuzz(6, Main_BuzzerStart);
				}
	
				while((ultrasonic_u32GetDistance() > Main_UltrasonicMinValue || ultrasonic_u32GetDistance() == Main_SensorDeactivate) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpLeft, Main_SharpMinValue) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpRight, Main_SharpMinValue) == Main_SensorDeactivate){
					Motor_Driver_vMove(Main_TurnMotorSpeed, Main_TurnMotorSpeed, Main_LeftDirection);//when ultrasonic sensor and right sharp see nothing and left sharps see something go right
					Main_vBuzz(10, Main_BuzzerStart);
				}

				while((ultrasonic_u32GetDistance() > Main_UltrasonicMinValue || ultrasonic_u32GetDistance() == Main_SensorDeactivate) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpLeft, Main_SharpMinValue) == Main_SensorDeactivate && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpRight, Main_SharpMinValue)){
					Motor_Driver_vMove(Main_TurnMotorSpeed, Main_TurnMotorSpeed, Main_RightDirection);//when ultrasonic sensor and left sharp see nothing and right sharps see something go left
					Main_vBuzz(12, Main_BuzzerStart);
				}
		
				while((ultrasonic_u32GetDistance() < Main_UltrasonicMinValue && ultrasonic_u32GetDistance() != Main_SensorDeactivate) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpLeft, Main_SharpMinValue) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpRight, Main_SharpMinValue)){
					Motor_Driver_vMove(Main_TurnMotorSpeed, Main_MotorStop, Main_BackwardDirection);//when all sensors see something go back
					Main_vBuzz(20, Main_BuzzerStart);
				}

				while((ultrasonic_u32GetDistance() < Main_UltrasonicMinValue && ultrasonic_u32GetDistance() != Main_SensorDeactivate) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpLeft, Main_SharpMinValue)){
					Motor_Driver_vMove(Main_TurnMotorSpeed, Main_TurnMotorSpeed, Main_LeftDirection);
					Main_vBuzz(30, Main_BuzzerStart);
				}
		
				while((ultrasonic_u32GetDistance() < Main_UltrasonicMinValue && ultrasonic_u32GetDistance() != Main_SensorDeactivate) && InfraredSensor_u8IsObstacleSharpSensor(Main_SharpRight, Main_SharpMinValue)){
					Motor_Driver_vMove(Main_TurnMotorSpeed, Main_TurnMotorSpeed, Main_RightDirection);
					Main_vBuzz(4, Main_BuzzerStart);
				}	
			}
    }
}


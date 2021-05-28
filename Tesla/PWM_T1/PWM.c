/*
 * PWM.c
 *
 * Created: 4/14/2021 1:54:15 PM
 *  Author: adrian.marginean
 */ 

#include "PWM.h"

/*
  This function set the register for a specific pin, set the registers for PWM fast mode with a 256 prescaler
  uint8_t u8PinNumber -input- represent the pin number
  -the function type is void (don't return something)
*/
void PWM_vSetup(uint8_t u8PinNumber){
	
	switch(u8PinNumber){
		
		case 2:
		TCCR3A |= (1 << COM3B1)  |(1 << WGM30) | (1 << WGM31);// set Fast PWM 10-bit Mode Top=0x03FF
		TCCR3B |= (1 << CS32)| (1 << WGM32); //set the p-scaler I/0clk/256
		break;
		
		case 3:
		TCCR3A |= (1 << COM3C1) |(1 << WGM30) | (1 << WGM31);
		TCCR3B |= (1 << CS32)| (1 << WGM32); 
		break;
		
		case 4:
		TCCR0A |= (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);
		TCCR0B |= (1 << CS02); 
		break;
		
		case 5:
		TCCR3A |= (1 << COM3A1)  |(1 << WGM30) | (1 << WGM31);
		TCCR3B |= (1 << CS32) | (1 << WGM32); 
		break;
		
		case 6:
		TCCR4A |= (1 << COM4A1)  |(1 << WGM40) | (1 << WGM41);
		TCCR4B |= (1 << CS42) | (1 << WGM42); 
		break;
		
		case 7:
		TCCR4A |= (1 << COM4B1)  |(1 << WGM40) | (1 << WGM41);
		TCCR4B |= (1 << CS42) | (1 << WGM42); 
		break;
		
		case 8:
		TCCR4A |= (1 << COM4C1)  |(1 << WGM40) | (1 << WGM41);
		TCCR4B |= (1 << CS42) | (1 << WGM42); 
		break;
		
		case 9:
		TCCR2A |= (1 << COM2B1)  |(1 << WGM20) | (1 << WGM21);
		TCCR2B |= (1 << CS22); 
		break;
		
		case 10:
		TCCR2A |= (1 << COM2A1)  |(1 << WGM20) | (1 << WGM21);
		TCCR2B |= (1 << CS22); 
		break;
		
		case 11:
		TCCR1A |= (1 << COM1A1)  |(1 << WGM10) | (1 << WGM11);
		TCCR1B |= (1 << CS12) | (1 << WGM12); 
		break;
		
		case 12:
		TCCR1A |= (1 << COM1B1)  |(1 << WGM10) | (1 << WGM11);
		TCCR1B |= (1 << CS12) | (1 << WGM12); 
		break;
		
		case 13:
		TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
		TCCR0B |= (1 << CS02); 
		break;
		
		default:
		break;
	}
	
}


/*
  This function calculate the duty cycle and put the result on a pin
  uint8_t u8PinNumber -input- represent the pin number
  uint16_t u16Duty -input- represent the percentage of duty from 0 to 100.
  -the function type is void (don't return something)
*/
void PWM_vSetPWMDuty(uint8_t u8PinNumber, uint16_t u16Duty){
	
	uint32_t u32DutyCycle;
	
	if((u8PinNumber == 13) || (u8PinNumber == 4) || (u8PinNumber == 10) || (u8PinNumber == 9)){
		u32DutyCycle=u16Duty * 2.55; //because timer 0 and 2 are on 8bits

	}else if((u8PinNumber == 2) || (u8PinNumber == 3) || (u8PinNumber == 5) || (u8PinNumber == 6) || (u8PinNumber == 7) || (u8PinNumber == 8) || (u8PinNumber == 11) || (u8PinNumber == 12) ){
		u32DutyCycle=u16Duty * 10.23; //because timer 1 3 and 4 are on 16bits
			
		}
	
	switch(u8PinNumber){
		
		case 2:
		OCR3B = u32DutyCycle;
		break;
		
		case 3:
		OCR3C = u32DutyCycle;
		break;
		
		case 4:
		OCR0B = u32DutyCycle;
		break;
		
		case 5:
		OCR3A = u32DutyCycle;
		break;
		
		case 6:
		OCR4A = u32DutyCycle;
		break;
		
		case 7:
		OCR4B = u32DutyCycle;
		break;
		
		case 8:
		OCR4C = u32DutyCycle;
		break;
		
		case 9:
		OCR2B = u32DutyCycle;
		break;
		
		case 10:
		OCR2A = u32DutyCycle;
		break;
		
		case 11:
		OCR1A = u32DutyCycle;
		break;
		
		case 12:
		OCR1B = u32DutyCycle;
		break;
		
		case 13:
		OCR0A = u32DutyCycle;
		break;
		
		default:
		break;
		
	}
	
}


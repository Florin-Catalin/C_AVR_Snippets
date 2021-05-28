/*
 * PWM.h
 *
 * Created: 4/5/2021 2:15:39 PM
 * Author : raul.garbou
 */ 

#include "PWM.h"

/*
  This function sets the registers for a given pin in fast PWM mode with a 64 prescaler
*/

void PWM_init(uint8_t u8Pin)
{
	
	switch(u8Pin){
		
		case 2:
			TCCR3A |= (1 << COM3B1) | (1 << WGM31) | (1 << WGM30); // Fast PWM into the 8'th mode
			TCCR3B |= (1 << WGM32) | (1 << CS31) | (1 << CS30); //set the prescaler to 64
			break;
		
		case 3:
			TCCR3A |= (1 << COM3C1) | (1 << WGM31) | (1 << WGM30); // Fast PWM into the 8'th mode
			TCCR3B |= (1 << WGM32) | (1 << CS31) | (1 << CS30); //set the prescaler to 64
			break;
		
		case 4:
			TCCR0A |= (1 << COM0B1) | (1 << WGM01) | (1 << WGM00); // Fast PWM into the 8'th mode
			TCCR0B |= (1 << WGM02) | (1 << CS01) | (1 << CS00); //set the prescaler to 64
			break;
		
		case 5:
			TCCR3A |= (1 << COM3A1) | (1 << WGM31) | (1 << WGM30); // Fast PWM into the 8'th mode
			TCCR3B |= (1 << WGM32) | (1 << CS31) | (1 << CS30); //set the prescaler to 64
			break;
		
		case 6:
			TCCR4A |= (1 << COM4A1) | (1 << WGM41) | (1 << WGM40); // Fast PWM into the 8'th mode
			TCCR4B |= (1 << WGM42) | (1 << CS41) | (1 << CS40); //set the prescaler to 64
			break;
		
		case 7:
			TCCR4A |= (1 << COM4B1) | (1 << WGM41) | (1 << WGM40); // Fast PWM into the 8'th mode
			TCCR4B |= (1 << WGM42) | (1 << CS41) | (1 << CS40); //set the prescaler to 64
			break;
		
		case 8:
			TCCR4A |= (1 << COM4C1) | (1 << WGM41) | (1 << WGM40); // Fast PWM into the 8'th mode
			TCCR4B |= (1 << WGM42) | (1 << CS41) | (1 << CS40); //set the prescaler to 64
			break;
		
		case 9:
			TCCR2A |= (1 << COM4B1) | (1 << WGM21) | (1 << WGM20); // Fast PWM into the 8'th mode
			TCCR2B |= (1 << WGM22) | (1 << CS21) | (1 << CS20); //set the prescaler to 64
			break;
		
		case 10:
			TCCR2A |= (1 << COM2A1) | (1 << WGM21) | (1 << WGM20); // Fast PWM into the 8'th mode
			TCCR2B |= (1 << WGM22) | (1 << CS21) | (1 << CS20); //set the prescaler to 64
			break;
		
		case 11:
			TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10); // Fast PWM into the 8'th mode
			TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10); //set the prescaler to 64
			break;
		
		case 12:
			TCCR1A |= (1 << COM1B1) | (1 << WGM11) | (1 << WGM10); // Fast PWM into the 8'th mode
			TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10); //set the prescaler to 64
			break;
		
		case 13:
			TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // Fast PWM into the 8'th mode
			TCCR0B |= (1 << WGM02) | (1 << CS01) | (1 << CS00); //set the prescaler to 64
			break;
		
		default:
			break;
	}
	
}


/*
  This function calculates the duty cycle and puts the result on a pin
*/

void PWM_Duty_Cycle(uint8_t u8Pin, uint16_t u16Value)
{
	uint32_t u32Value;
	
	if(u16Value >= 0 && u16Value <= 100)
	{
		if((u8Pin == 4) || (u8Pin == 9) || (u8Pin == 10) || (u8Pin == 13))
		{
			u32Value=u16Value * 2.55; // Multiply to have full scale from 0-255
			switch(u8Pin)
			{
				case 4:
					OCR0B = u32Value; //Assign Value to OCR0B which serves as TOP value
					break;
			
				case 9:
					OCR2B = u32Value; //Assign Value to OCR2B which serves as TOP value
					break;
			
				case 10:
					OCR2A = u32Value; //Assign Value to OCR2A which serves as TOP value
					break;
			
				case 13:
					OCR0A = u32Value; //Assign Value to OCR0A which serves as TOP value
					break;
			
				default:
					break;
			}
		}
		else if((u8Pin == 2) || (u8Pin == 3) || (u8Pin == 5) || (u8Pin == 6) || (u8Pin == 7) || (u8Pin == 8) || (u8Pin == 11) || (u8Pin == 12))
		{
			u32Value=u16Value * 10.23; // Multiply to have full scale from 0-1023
				switch(u8Pin)
				{
					case 2:
						OCR3B = u32Value; //Assign Value to OCR3B which serves as TOP value
						break;
				
					case 3:
						OCR3C = u32Value; //Assign Value to OCR3C which serves as TOP value
						break;
				
					case 5:
						OCR3A = u32Value; //Assign Value to OCR3A which serves as TOP value
						break;
				
					case 6:
						OCR4A = u32Value; //Assign Value to OCR4A which serves as TOP value
						break;
				
					case 7:
						OCR4B = u32Value; //Assign Value to OCR4B which serves as TOP value
						break;
				
					case 8:
						OCR4C = u32Value; //Assign Value to OCR4C which serves as TOP value
						break;
					
					case 11:
						OCR1A = u32Value; //Assign Value to OCR1A which serves as TOP value
						break;
				
					case 12:
						OCR1B = u32Value; //Assign Value to OCR1B which serves as TOP value
						break;

					default:
						break;
				}
		}
	}
}


/*
 * Infrared_T2.c
 *
 * Created: 4/20/2021 1:34:21 PM
 *  Author: raul.garbou
 */ 

#include "Infrared_T2.h"
#include "gpio.h"


void Infrared_vAnalog_Init(uint8_t u8Pin_input)
{
	GPIO_vSetUp(u8Pin_input,0);
	//ADMUX  = 0; //Clean the registers
	//ADCSRA = 0;
	
	//Set the Multiplex Registers
	ADMUX |= (1 << REFS0); //Set voltage reference to 5V
	
	//Turn on ADC
	ADCSRA |= (1 << ADEN) | (1 << ADPS1) | (1 << ADPS0); //Set prescaler to 8
	
}

uint16_t Infrared_u16Analog_Read(uint8_t u8Pin_input)
{	
	//Assign channel
	if(u8Pin_input < 8) //first 8 pins of digital
	{
		ADMUX |= (u8Pin_input & u8MuxSet); //Activate MUX0:3 accordingly
	}
	else //the other 8 pins of digital
	{
		ADCSRB |= (1 << MUX5);
		ADMUX |= ((u8Pin_input - u8OffsetNumber) & u8MuxSet); //activate MUX5 and activate MUX0:3 accordingly
		/*uart_vTransmitMsg("ADMUX = ");
		uart_vTransmitNumber(ADMUX);
		uart_vTransmitMsg("\n");*/
	}
	//Starts conversion
	ADCSRA |= (1 << ADSC);
		
	while (ADCSRA & (1 << ADSC));
	return (ADC);
}

uint16_t Infrared_u16Analog_Distance(uint8_t u8Pin_input)
{
	//Start ADC in single channel
	Infrared_vAnalog_Init(u8Pin_input);
	//Read 3 values and average them to reduce error
	uint16_t u16Distance = Infrared_u16Analog_Read(u8Pin_input);
	u16Distance = u16Distance + Infrared_u16Analog_Read(u8Pin_input);
	u16Distance = u16Distance + Infrared_u16Analog_Read(u8Pin_input);
	u16Distance = u16Distance / u8NumberOfAdditions; //Average 3 separate reads
	
	//compute the distance
	u16Distance = u16MaxVoltage / (u16Distance - u8SubtractionValue);
	//Known formula for converting Voltage to cm on this specific model

	//Edges of detection
	if(u16Distance < u8MinDistance)
		u16Distance = u8MinDistance;
	else if(u16Distance > u8MaxDistance)
		u16Distance = u8MaxDistance;
	//return distance
	return u16Distance;
}
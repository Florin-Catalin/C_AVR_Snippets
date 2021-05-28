/*
 * InfraredSensor.c
 *
 * Created: 4/20/2021 3:31:30 PM
 *  Author: adrian.marginean
 */ 

#include "gpio.h"
#include "InfraredSensor.h"


t_bool InfraredSensor_u8IsObstacleDigitalPin(uint8_t u8PinNumber){
	//set input mode for the specific pin 
	gpio_vPinMode(u8PinNumber,InfraredSensor_u8InputMode);
	
	return gpio_u8ReadState(u8PinNumber) ? false :true;
}


void InfraredSensor_vInitADC(){
	// AVcc with external capacitor at AREF pin
	ADMUX |= (1<<REFS0);
	//set prescaller to 128 and enable ADC
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0) | (1<<ADEN);
}


uint16_t InfraredSensor_u16ReadADC(uint8_t u8PinNumber){
	//select ADC channel with safety mask
	ADMUX = (ADMUX & 0xF0) | (u8PinNumber & 0x0F);
	//single conversion mode
	ADCSRA |= (1<<ADSC);
	// wait until ADC conversion is complete
	while( ADCSRA & (1<<ADSC) );
	return ADC;
}


uint8_t InfraredSensor_u8ComputeDistanceSharpSensor(uint8_t u8PinNumber){
	//init adc for the specific channel
	InfraredSensor_vInitADC(u8PinNumber);
	//read the analog value
	uint16_t u16Distance = InfraredSensor_u16ReadADC(u8PinNumber);
	//compute the distance
	u16Distance = InfraredSensor_u16MaxVoltage / (u16Distance - InfraredSensor_u8AnalogError);
	//test the boundaries
	if(u16Distance < InfraredSensor_u8MinDistance) 
	       u16Distance = InfraredSensor_u8MinDistance;
	  else if(u16Distance > InfraredSensor_u8MaxDistance) 
	       u16Distance = InfraredSensor_u8MaxDistance;
	//return the result
	return u16Distance;
}

t_bool InfraredSensor_u8IsObstacleSharpSensor(uint8_t u8PinNumber, uint8_t u8Distance){
	
	 return (InfraredSensor_u8ComputeDistanceSharpSensor(u8PinNumber) < u8Distance) ? true : false;
	 
}


/*
 * gpio.c
 *
 * Created: 4/15/2021 3:31:42 PM
 *  Author: anamaria.rosca
 */ 

#include "gpio.h"

void GPIO_vSetUp(uint8_t u8Pin,uint8_t u8Mode){
	// function used to set the pins as input or output
	// setting a 0 for the bit will indicate an input and a 1 an output
	
	switch(u8Pin){
		
		case 0 :
		if(u8Mode==0){           // check if the mode is 0 or 1
			DDRE &= ~(1 << PE0); /// set input 
		}
		else
		DDRE |= (1 << PE0); // set output
		break;
		
		case 1 :
		if(u8Mode==0){
			DDRE &= ~(1 << PE1);
		}
		else
		DDRE |= (1 << PE1);
		break;
		
		case 2 :
		if(u8Mode==0){
			DDRE &= ~(1 << PE4);
		}
		else
		DDRE |= (1 << PE4);
		break;
		
		case 3 :
		if(u8Mode==0){
			DDRE &= ~(1 << PE5);
		}
		else
		DDRE |= (1 << PE5);
		break;
		
		case 4 :
		if(u8Mode==0){
			DDRG &= ~(1 << PG5);
		}
		else
		DDRG |= (1 << PG5);
		break;
		
		case 5 :
		if(u8Mode==0){
			DDRE &= ~(1 << PE3);
		}
		else
		DDRE |= (1 << PE3);
		break;
		
		case 6 :
		if(u8Mode==0){
			DDRH &= ~(1 << PH3);
		}
		else
		DDRH |= (1 << PH3);
		break;
		
		case 7 :
		if(u8Mode==0){
			DDRH &= ~(1 << PH4);
		}
		else
		DDRH |= (1 << PH4);
		break;
		
		case 8 :
		if(u8Mode==0){
			DDRH &= ~(1 << PH5);
		}
		else
		DDRH |= (1 << PH5);
		break;
		
		case 9 :
		if(u8Mode==0){
			DDRH &= ~(1 << PH6);
		}
		else
		DDRH |= (1 << PH6);
		break;
		
		case 10 :
		if(u8Mode==0){
			DDRB &= ~(1 << PB4);
		}
		else
		DDRB |= (1 << PB4);
		break;
		
		case 11 :
		if(u8Mode==0){
			DDRB &= ~(1 << PB5);
		}
		else
		DDRB |= (1 << PB5);
		break;
		
		case 12 :
		if(u8Mode==0){
			DDRB  &= ~(1 << PB6);
		}
		else
		DDRB |= (1 << PB6);
		break;
		
		case 13 :
		if(u8Mode==0){
			DDRB &= ~(1 << PB7);
		}
		else
		DDRB |= (1 << PB7);
		break;
		
		case 14 :
		if(u8Mode==0){
			DDRJ  &= ~(1 << PJ1);
		}
		else
		DDRJ |= (1 << PJ1);
		break;
		
		case 15 :
		if(u8Mode==0){
			DDRJ &= ~(1 << PJ0);
		}
		else
		DDRJ |= (1 << PJ0);
		break;
		
		case 16 :
		if(u8Mode==0){
			DDRH &= ~(1 << PH1);
		}
		else
		DDRH |= (1 << PH1);
		break;
		
		case 17 :
		if(u8Mode==0){
			DDRH &= ~(1 << PH0);
		}
		else
		DDRH |= (1 << PH0);
		break;
		
		case 18 :
		if(u8Mode==0){
			DDRD &= ~(1 << PD3);
		}
		else
		DDRD |= (1 << PD3);
		break;
		
		case 19 :
		if(u8Mode==0){
			DDRD &= ~(1 << PD2);
		}
		else
		DDRD |= (1 << PD2);
		break;
		
		case 20 :
		if(u8Mode==0){
			DDRD &= ~(1 << PD1);
		}
		else
		DDRD |= (1 << PD1);
		break;
		
		case 21 :
		if(u8Mode==0){
			DDRD &= ~(1 << PD0);
		}
		else
		DDRD |= (1 << PD0);
		break;
		
		case 22 :
		if(u8Mode==0){
			DDRA &= ~(1 << PA0);
		}
		else
		DDRA |= (1 << PA0);
		break;
		
		case 23 :
		if(u8Mode==0){
			DDRA &= ~(1 << PA1);
		}
		else
		DDRA |= (1 << PA1);
		break;
		
		case 24 :
		if(u8Mode==0){
			DDRA &= ~(1 << PA2);
		}
		else
		DDRA |= (1 << PA2);
		break;
		
		case 25 :
		if(u8Mode==0){
			DDRA &= ~(1 << PA3);
		}
		else
		DDRA |= (1 << PA3);
		break;
		
		case 26 :
		if(u8Mode==0){
			DDRA &= ~(1 << PA4);
		}
		else
		DDRA |= (1 << PA4);
		break;
		
		case 27 :
		if(u8Mode==0){
			DDRA &= ~(1 << PA5);
		}
		else
		DDRA |= (1 << PA5);
		break;
		
		case 28 :
		if(u8Mode==0){
			DDRA &= ~(1 << PA6);
		}
		else
		DDRA |= (1 << PA6);
		break;
		
		case 29 :
		if(u8Mode==0){
			DDRA &= ~(1 << PA7);
		}
		else
		DDRA |= (1 << PA7);
		break;
		
		case 30 :
		if(u8Mode==0){
			DDRC &= ~(1 << PC7);
		}
		else
		DDRC |= (1 << PC7);
		break;
		
		case 31 :
		if(u8Mode==0){
			DDRC &= ~(1 << PC6);
		}
		else
		DDRC |= (1 << PC6);
		break;
		
		case 32 :
		if(u8Mode==0){
			DDRC &= ~(1 << PC5);
		}
		else
		DDRC |= (1 << PC5);
		break;
		
		case 33 :
		if(u8Mode==0){
			DDRC &= ~(1 << PC4);
		}
		else
		DDRC |= (1 << PC4);
		break;
		
		case 34 :
		if(u8Mode==0){
			DDRC &= ~(1 << PC3);
		}
		else
		DDRC |= (1 << PC3);
		break;
		
		case 35 :
		if(u8Mode==0){
			DDRC &= ~(1 << PC2);
		}
		else
		DDRC |= (1 << PC2);
		break;
		
		case 36 :
		if(u8Mode==0){
			DDRC &= ~(1 << PC1);
		}
		else
		DDRC |= (1 << PC1);
		break;
		
		case 37 :
		if(u8Mode==0){
			DDRC &= ~(1 << PC0);
		}
		else
		DDRC |= (1 << PC0);
		break;
		
		case 38 :
		if(u8Mode==0){
			DDRD &= ~(1 << PD7);
		}
		else
		DDRD |= (1 << PD7);
		break;
		
		case 39 :
		if(u8Mode==0){
			DDRG &= ~(1 << PG2);
		}
		else
		DDRG |= (1 << PG2);
		break;
		
		case 40 :
		if(u8Mode==0){
			DDRG &= ~(1 << PG1);
		}
		else
		DDRG |= (1 << PG1);
		break;
		
		case 41 :
		if(u8Mode==0){
			DDRG &= ~(1 << PG0);
		}
		else
		DDRG |= (1 << PG0);
		break;
		
		case 42 :
		if(u8Mode==0){
			DDRL &= ~(1 << PL7);
		}
		else
		DDRL |= (1 << PL7);
		break;
		
		case 43 :
		if(u8Mode==0){
			DDRL &= ~(1 << PL6);
		}
		else
		DDRL |= (1 << PL6);
		break;
		
		case 44 :
		if(u8Mode==0){
			DDRL &= ~(1 << PL5);
		}
		else
		DDRL |= (1 << PL5);
		break;
		
		case 45 :
		if(u8Mode==0){
			DDRL &= ~(1 << PL4);
		}
		else
		DDRL |= (1 << PL4);
		break;
		
		case 46 :
		if(u8Mode==0){
			DDRL &= ~(1 << PL3);
		}
		else
		DDRL |= (1 << PL3);
		break;
		
		case 47 :
		if(u8Mode==0){
			DDRL &= ~(1 << PL2);
		}
		else
		DDRL |= (1 << PL2);
		break;
		
		case 48 :
		if(u8Mode==0){
			DDRL &= ~(1 << PL1);
		}
		else
		DDRL |= (1 << PL1);
		break;
		
		case 49 :
		if(u8Mode==0){
			DDRL &= ~(1 << PL0);
		}
		else
		DDRL |= (1 << PL0);
		break;
		
		case 50 :
		if(u8Mode==0){
			DDRB &= ~(1 << PB3);
		}
		else
		DDRB |= (1 << PB3);
		break;
		
		case 51 :
		if(u8Mode==0){
			DDRB &= ~(1 << PB2);
		}
		else
		DDRB |= (1 << PB2);
		break;
		
		case 52 :
		if(u8Mode==0){
			DDRB &= ~(1 << PB1);
		}
		else
		DDRB |= (1 << PB1);
		break;
		
		case 53 :
		if(u8Mode==0){
			DDRB &= ~(1 << PB0);
		}
		else
		DDRB |= (1 << PB0);
		break;
		
		default:
		break;
		
	}
}

void GPIO_vDigitalWrite(uint8_t u8Pin, uint8_t u8Val){
	// function used to set the pins low or high
	// 0 will indicate low and 1 high
	
	switch(u8Pin){
		
		case 0 :
		if(u8Val == 0){	          //check if the variable is 0
			PORTE &= ~(1 << PE0); //set the pin PE0 low
		}
		else
		PORTE |= (1 << PE0); //set the pin PE0 high
		break;
		
		case 1 :
		if(u8Val == 0){
			PORTE &= ~(1 << PE1);
		}
		else
		PORTE |= (1 << PE1);
		break;
		
		case 2 :
		if(u8Val == 0){
			PORTE &= ~(1 << PE4);
		}
		else
		PORTE |= (1 << PE4);
		break;
		
		case 3 :
		if(u8Val == 0){
			PORTE &= ~(1 << PE5);
		}
		else
		PORTE |= (1 << PE5);
		break;
		
		case 4 :
		if(u8Val == 0){
			PORTG &= ~(1 << PG5);
		}
		else
		PORTG |= (1 << PG5);
		break;
		
		case 5 :
		if(u8Val == 0){
			PORTE &= ~(1 << PE3);
		}
		else
		PORTE |= (1 << PE3);
		break;
		
		case 6 :
		if(u8Val == 0){
			PORTH &= ~(1 << PH3);
		}
		else
		PORTH |= (1 << PH3);
		break;
		
		case 7 :
		if(u8Val == 0){
			PORTH &= ~(1 << PH4);
		}
		else
		PORTH |= (1 << PH4);
		break;
		
		case 8 :
		if(u8Val == 0){
			PORTH &= ~(1 << PH5);
		}
		else
		PORTH |= (1 << PH5);
		break;
		
		case 9 :
		if(u8Val == 0){
			PORTH &= ~(1 << PH6);
		}
		else
		PORTH |= (1 << PH6);
		break;
		
		case 10 :
		if(u8Val == 0){
			PORTB &= ~(1 << PB4);
		}
		else
		PORTB |= (1 << PB4);
		break;
		
		case 11 :
		if(u8Val == 0){
			PORTB &= ~(1 << PB5);
		}
		else
		PORTB |= (1 << PB5);
		break;
		
		case 12 :
		if(u8Val == 0){
			PORTB &= ~(1 << PB6);
		}
		else
		PORTB |= (1 << PB6);
		break;
		
		case 13 :
		if(u8Val == 0){
			PORTB &= ~(1 << PB7);
		}
		else
		PORTB |= (1 << PB7);
		break;
		
		case 14 :
		if(u8Val == 0){
			PORTJ &= ~(1 << PJ1);
		}
		else
		PORTJ |= (1 << PJ1);
		break;
		
		case 15 :
		if(u8Val == 0){
			PORTJ &= ~(1 << PJ0);
		}
		else
		PORTJ |= (1 << PJ0);
		break;
		
		case 16 :
		if(u8Val == 0){
			PORTH &= ~(1 << PH1);
		}
		else
		PORTH |= (1 << PH1);
		break;
		
		case 17 :
		if(u8Val == 0){
			PORTH &= ~(1 << PH0);
		}
		else
		PORTH |= (1 << PH0);
		break;
		
		case 18 :
		if(u8Val == 0){
			PORTD &= ~(1 << PD3);
		}
		else
		PORTD |= (1 << PD3);
		break;
		
		case 19 :
		if(u8Val == 0){
			PORTD &= ~(1 << PD2);
		}
		else
		PORTD |= (1 << PD2);
		break;
		
		case 20 :
		if(u8Val == 0){
			PORTD &= ~(1 << PD1);
		}
		else
		PORTD |= (1 << PD1);
		break;
		
		case 21 :
		if(u8Val == 0){
			PORTD &= ~(1 << PD0);
		}
		else
		PORTD |= (1 << PD0);
		break;
		
		case 22 :
		if(u8Val == 0){
			PORTA &= ~(1 << PA0);
		}
		else
		PORTA |= (1 << PA0);
		break;
		
		case 23 :
		if(u8Val == 0){
			PORTA &= ~(1 << PA1);
		}
		else
		PORTA |= (1 << PA1);
		break;
		
		case 24 :
		if(u8Val == 0){
			PORTA &= ~(1 << PA2);
		}
		else
		PORTA |= (1 << PA2);
		break;
		
		case 25 :
		if(u8Val == 0){
			PORTA &= ~(1 << PA3);
		}
		else
		PORTA |= (1 << PA3);
		break;
		
		case 26 :
		if(u8Val == 0){
			PORTA &= ~(1 << PA4);
		}
		else
		PORTA |= (1 << PA4);
		break;
		
		case 27 :
		if(u8Val == 0){
			PORTA &= ~(1 << PA5);
		}
		else
		PORTA |= (1 << PA5);
		break;
		
		case 28 :
		if(u8Val == 0){
			PORTA &= ~(1 << PA6);
		}
		else
		PORTA |= (1 << PA6);
		break;
		
		case 29 :
		if(u8Val == 0){
			PORTA &= ~(1 << PA7);
		}
		else
		PORTA |= (1 << PA7);
		break;
		
		case 30 :
		if(u8Val == 0){
			PORTC &= ~(1 << PC7);
		}
		else
		PORTC |= (1 << PC7);
		break;
		
		case 31 :
		if(u8Val == 0){
			PORTC &= ~(1 << PC6);
		}
		else
		PORTC |= (1 << PC6);
		break;
		
		case 32 :
		if(u8Val == 0){
			PORTC &= ~(1 << PC5);
		}
		else
		PORTC |= (1 << PC5);
		break;
		
		case 33 :
		if(u8Val == 0){
			PORTC &= ~(1 << PC4);
		}
		else
		PORTC |= (1 << PC4);
		break;
		
		case 34 :
		if(u8Val == 0){
			PORTC &= ~(1 << PC3);
		}
		else
		PORTC |= (1 << PC3);
		break;
		
		case 35 :
		if(u8Val == 0){
			PORTC &= ~(1 << PC2);
		}
		else
		PORTC |= (1 << PC2);
		break;
		
		case 36 :
		if(u8Val == 0){
			PORTC &= ~(1 << PC1);
		}
		else
		PORTC |= (1 << PC1);
		break;
		
		case 37 :
		if(u8Val == 0){
			PORTC &= ~(1 << PC0);
		}
		else
		PORTC |= (1 << PC0);
		break;
		
		case 38 :
		if(u8Val == 0){
			PORTD &= ~(1 << PD7);
		}
		else
		PORTD |= (1 << PD7);
		break;
		
		case 39 :
		if(u8Val == 0){
			PORTG &= ~(1 << PG2);
		}
		else
		PORTG |= (1 << PG2);
		break;
		
		case 40 :
		if(u8Val == 0){
			PORTG &= ~(1 << PG1);
		}
		else
		PORTG |= (1 << PG1);
		break;
		
		case 41 :
		if(u8Val == 0){
			PORTG &= ~(1 << PG0);
		}
		else
		PORTG |= (1 << PG0);
		break;
		
		case 42 :
		if(u8Val == 0){
			PORTL &= ~(1 << PL7);
		}
		else
		PORTL |= (1 << PL7);
		break;
		
		case 43 :
		if(u8Val == 0){
			PORTL &= ~(1 << PL6);
		}
		else
		PORTL |= (1 << PL6);
		break;
		
		case 44 :
		if(u8Val == 0){
			PORTL &= ~(1 << PL5);
		}
		else
		PORTL |= (1 << PL5);
		break;
		
		case 45 :
		if(u8Val == 0){
			PORTL &= ~(1 << PL4);
		}
		else
		PORTL |= (1 << PL4);
		break;
		
		case 46 :
		if(u8Val == 0){
			PORTL &= ~(1 << PL3);
		}
		else
		PORTL |= (1 << PL3);
		break;
		
		
		case 47 :
		if(u8Val == 0){
			PORTL &= ~(1 << PL2);
		}
		else
		PORTL |= (1 << PL2);
		break;
		
		case 48 :
		if(u8Val == 0){
			PORTL &= ~(1 << PL1);
		}
		else
		PORTL |= (1 << PL1);
		break;
		
		case 49 :
		if(u8Val == 0){
			PORTL &= ~(1 << PL0);
		}
		else
		PORTL |= (1 << PL0);
		break;
		
		case 50 :
		if(u8Val == 0){
			PORTB &= ~(1 << PB3);
		}
		else
		PORTB |= (1 << PB3);
		break;
		
		case 51 :
		if(u8Val == 0){
			PORTB &= ~(1 << PB2);
		}
		else
		PORTB |= (1 << PB2);
		break;
		
		case 52 :
		if(u8Val == 0){
			PORTB &= ~(1 << PB1);
		}
		else
		PORTB |= (1 << PB1);
		break;
		
		case 53 :
		if(u8Val == 0){
			PORTB &= ~(1 << PB0);
		}
		else
		PORTB |= (1 << PB0);
		break;
		
		default:
		break;
	}
}

int GPIO_vDigitalRead(uint8_t u8Pin){
	// function used to read the value from a specified pin, either high or low
	
	switch(u8Pin){
		
		case 0 :
		return PINE & (1<< PE0); //return the value of the pin
		break;
		
		case 1 :
		return PINE & (1 << PE1);
		break;
		
		case 2 :
		return PINE & (1 << PE4);
		break;
		
		case 3 :
		return PINE & (1 << PE5);
		break;
		
		case 4 :
		return PING & (1 << PG5);
		break;
		
		case 5 :
		return PINE & (1 << PE3);
		break;
		
		case 6 :
		return PINH & (1 << PH3);
		break;
		
		case 7 :
		return PINH & (1 << PH4);
		break;
		
		case 8 :
		return PINH & (1 << PH5);
		break;
		
		case 9 :
		return PINH & (1 << PH6);
		break;
		
		case 10 :
		return PINB & (1 << PB4);
		break;
		
		case 11 :
		return PINB & (1 << PB5);
		break;
		
		case 12 :
		return PINB & (1 << PB6);
		break;
		
		case 13 :
		return PINB & (1 << PB7);
		break;
		
		case 14 :
		return PINJ & (1 << PJ1);
		break;
		
		case 15 :
		return PINJ & (1 << PJ0);
		break;
		
		case 16 :
		return PINH & (1 << PH1);
		break;
		
		case 17 :
		return PINH & (1 << PH0);
		break;
		
		case 18 :
		return PIND & (1 << PD3);
		break;
		
		case 19 :
		return PIND & (1 << PD2);
		break;
		
		case 20 :
		return PIND & (1 << PD1);
		break;
		
		case 21 :
		return PIND & (1 << PD0);
		break;
		
		case 22 :
		return PINA & (1 << PA0);
		break;
		
		case 23 :
		return PINA & (1 << PA1);
		break;
		
		case 24 :
		return PINA & (1 << PA2);
		break;
		
		case 25 :
		return PINA & (1 << PA3);
		break;
		
		case 26 :
		return PINA & (1 << PA4);
		break;
		
		case 27 :
		return PINA & (1 << PA5);
		break;
		
		case 28 :
		return PINA & (1 << PA6);
		break;
		
		case 29 :
		return PINA & (1 << PA7);
		break;
		
		case 30 :
		return PINC & (1 << PC7);
		break;
		
		case 31 :
		return PINC & (1 << PC6);
		break;
		
		case 32 :
		return PINC & (1 << PC5);
		break;
		
		case 33 :
		return PINC & (1 << PC4);
		break;
		
		case 34 :
		return PINC & (1 << PC3);
		break;
		
		case 35 :
		return PINC & (1 << PC2);
		break;
		
		case 36 :
		return PINC & (1 << PC1);
		break;
		
		case 37 :
		return PINC & (1 << PC0);
		break;
		
		case 38 :
		return PIND & (1 << PD7);
		break;
		
		case 39 :
		return PING & (1 << PG2);
		break;
		
		case 40 :
		return PING & (1 << PG1);
		break;
		
		case 41 :
		return PING & (1 << PG0);
		break;
		
		case 42 :
		return PINL & (1 << PL7);
		break;
		
		case 43 :
		return PINL & (1 << PL6);
		break;
		
		case 44 :
		return PINL & (1 << PL5);
		break;
		
		case 45 :
		return PINL & (1 << PL4);
		break;
		
		case 46 :
		return PINL & (1 << PL3);
		break;
		
		case 47 :
		return PINL & (1 << PL2);
		break;
		
		case 48 :
		return PINL & (1 << PL1);
		break;
		
		case 49 :
		return PINL & (1 << PL0);
		break;
		
		case 50 :
		return PINB & (1 << PB3);
		break;
		
		case 51 :
		return PINB & (1 << PB2);
		break;
		
		case 52 :
		return PINB & (1 << PB1);
		break;
		
		case 53 :
		return PINB & (1 << PB0);
		break;
		
		
		default:
		break;
		
		
	}
	return -1;
	
}

void GPIO_vPullUp(uint8_t u8Pin){
	// function used to activate the pull up resistor of the pin
	// u8Pin will be the number of the pin
	// type of the function is void so it won't return anything
	
	switch(u8Pin){
		
		case 0 :
		PORTE |= (1 << PE0);  //activate pull up on pin PE0
		break;
		
		case 1 :
		PORTE |= (1 << PE1);
		break;
		
		case 2 :
		PORTE |= (1 << PE4);
		break;
		
		case 3 :
		PORTE |= (1 << PE5);
		break;
		
		case 4 :
		PORTG |= (1 << PG5);
		break;
		
		case 5 :
		PORTE |= (1 << PE3);
		break;
		
		case 6 :
		PORTH |= (1 << PH3);
		break;
		
		case 7 :
		PORTH |= (1 << PH4);
		break;
		
		case 8 :
		PORTH |= (1 << PH5);
		break;
		
		case 9 :
		PORTH |= (1 << PH6);
		break;
		
		case 10 :
		PORTB |= (1 << PB4);
		break;
		
		case 11 :
		PORTB |= (1 << PB5);
		break;
		
		case 12 :
		PORTB |= (1 << PB6);
		break;
		
		case 13 :
		PORTB |= (1 << PB7);
		break;
		
		case 14 :
		PORTJ |= (1 << PJ1);
		break;
		
		case 15 :
		PORTJ |= (1 << PJ0);
		break;
		
		case 16 :
		PORTH |= (1 << PH1);
		break;
		
		case 17 :
		PORTH |= (1 << PH0);
		break;
		
		case 18 :
		PORTD |= (1 << PD3);
		break;
		
		case 19 :
		PORTD |= (1 << PD2);
		break;
		
		case 20 :
		PORTD |= (1 << PD1);
		break;
		
		case 21 :
		PORTD |= (1 << PD0);
		break;
		
		case 22 :
		PORTA |= (1 << PA0);
		break;
		
		case 23 :
		PORTA |= (1 << PA1);
		break;
		
		case 24 :
		PORTA |= (1 << PA2);
		break;
		
		case 25 :
		PORTA |= (1 << PA3);
		break;
		
		case 26 :
		PORTA |= (1 << PA4);
		break;
		
		case 27 :
		PORTA |= (1 << PA5);
		break;
		
		case 28 :
		PORTA |= (1 << PA6);
		break;
		
		case 29 :
		PORTA |= (1 << PA7);
		break;
		
		case 30 :
		PORTC |= (1 << PC7);
		break;
		
		case 31 :
		PORTC |= (1 << PC6);
		break;
		
		case 32 :
		PORTC |= (1 << PC5);
		break;
		
		case 33 :
		PORTC |= (1 << PC4);
		break;
		
		case 34 :
		PORTC |= (1 << PC3);
		break;
		
		case 35 :
		PORTC |= (1 << PC2);
		break;
		
		case 36 :
		PORTC |= (1 << PC1);
		break;
		
		case 37 :
		PORTC |= (1 << PC0);
		break;
		
		case 38 :
		PORTD |= (1 << PD7);
		break;
		
		case 39 :
		PORTG |= (1 << PG2);
		break;
		
		case 40 :
		PORTG |= (1 << PG1);
		break;
		
		case 41 :
		PORTG |= (1 << PG0);
		break;
		
		case 42 :
		PORTL |= (1 << PL7);
		break;
		
		case 43 :
		PORTL |= (1 << PL6);
		break;
		
		case 44 :
		PORTL |= (1 << PL5);
		break;
		
		case 45 :
		PORTL |= (1 << PL4);
		break;
		
		case 46 :
		PORTL |= (1 << PL3);
		break;
		
		case 47 :
		PORTL |= (1 << PL2);
		break;
		
		case 48 :
		PORTL |= (1 << PL1);
		break;
		
		case 49 :
		PORTL |= (1 << PL0);
		break;
		
		case 50 :
		PORTB |= (1 << PB3);
		break;
		
		case 51 :
		PORTB |= (1 << PB2);
		break;
		
		case 52 :
		PORTB |= (1 << PB1);
		break;
		
		case 53 :
		PORTB |= (1 << PB0);
		break;
		
		default:
		break;
	}
}
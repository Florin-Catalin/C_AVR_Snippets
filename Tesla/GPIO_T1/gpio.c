/*
 * gpio.c
 *
 * Created: 4/9/2021 1:35:52 PM
 *  Author: alin.pop
 */ 

#include "gpio.h"

void gpio_vPinMode(uint8_t u8Pin, uint8_t u8Mode){
	switch(u8Pin){
		//set pin0
		case 0 :
		if(u8Mode == 0) //in this case we must set the pin as input
			DDRE &= ~(1 << PE0); //modify DDR register to set the required pin as input (put 0 on required pin in DDR register)
		else  //in this case we must set the pin as output
			DDRE |= (1 << PE0); //modify DDR register to set the required pin as output (put 1 on required pin in DDR register)
		break;
		
		//set pin1
		case 1 :
		if(u8Mode == 0)
			DDRE &= ~(1 << PE1);
		else 
			DDRE |= (1 << PE1);
		break;
		
		//set pin2
		case 2 :
		if(u8Mode == 0)
			DDRE &= ~(1 << PE4);
		else 
			DDRE |= (1 << PE4);
		break;
		
		//set pin3
		case 3 :
		if(u8Mode == 0)
			DDRE &= ~(1 << PE5);
		else 
			DDRE |= (1 << PE5);
		break;
		
		//set pin4
		case 4 :
		if(u8Mode == 0)
			DDRG &= ~(1 << PG5);
		else 
			DDRG |= (1 << PG5);
		break;
		
		//set pin5
		case 5 :
		if(u8Mode == 0)
			DDRE &= ~(1 << PE3);
		else 
			DDRE |= (1 << PE3);
		break;
		
		//set pin6
		case 6 :
		if(u8Mode == 0)
			DDRH &= ~(1 << PH3);
		else 
			DDRH |= (1 << PH3);
		break;
		
		//set pin7
		case 7 :
		if(u8Mode == 0)
			DDRH &= ~(1 << PH4);
		else 
			DDRH |= (1 << PH4);
		break;
		//set pin8
		case 8 :
		if(u8Mode == 0)
			DDRH &= ~(1 << PH5);
		else 
			DDRH |= (1 << PH5);
		break;
		
		//set pin9
		case 9 :
		if(u8Mode == 0)
			DDRH &= ~(1 << PH6);
		else 
			DDRH |= (1 << PH6);
		break;
		
		//set pin10
		case 10 :
		if(u8Mode == 0)
			DDRB &= ~(1 << PB4);
		else 
			DDRB |= (1 << PB4);
		break;
		
		//set pin11
		case 11 :
		if(u8Mode == 0)
			DDRB &= ~(1 << PB5);
		else 
			DDRB |= (1 << PB5);
		break;
		
		//set pin12
		case 12 :
		if(u8Mode == 0)
			DDRB &= ~(1 << PB6);
		else 
			DDRB |= (1 << PB6);
		break;
		
		//set pin13
		case 13 :
		if(u8Mode == 0)
			DDRB &= ~(1 << PB7);
		else 
			DDRB |= (1 << PB7);
		break;
		
		//set pin14
		case 14 :
		if(u8Mode == 0) 
			DDRJ &= ~(1 << PJ1);
		else if(u8Mode == 1)
			DDRJ |= (1 << PJ1);
		break;
		
		//set pin15
		case 15 :
		if(u8Mode == 0)
			DDRJ &= ~(1 << PJ0);
		else 
			DDRJ |= (1 << PJ0);
		break;
		
		//set pin16
		case 16 :
		if(u8Mode == 0)
			DDRH &= ~(1 << PH1);
		else 
			DDRH |= (1 << PH1);
		break;
		
		//set pin17
		case 17 :
		if(u8Mode == 0)
			DDRH &= ~(1 << PH0);
		else 
			DDRH |= (1 << PH0);
		break;
		
		//set pin18
		case 18 :
		if(u8Mode == 0)
			DDRD &= ~(1 << PD3);
		else 
			DDRD |= (1 << PD3);
		break;
		
		//set pin19
		case 19 :
		if(u8Mode == 0)
			DDRD &= ~(1 << PD2);
		else
			DDRD |= (1 << PD2);
		break;
		
		//set pin20
		case 20 :
		if(u8Mode == 0)
			DDRD &= ~(1 << PD1);
		else 
			DDRD |= (1 << PD1);
		break;
		
		//set pin21
		case 21 :
		if(u8Mode == 0)
			DDRD &= ~(1 << PD0);
		else 
			DDRD |= (1 << PD0);
		break;
		
		//set pin22
		case 22 :
		if(u8Mode == 0)
			DDRA &= ~(1 << PA0);
		else 
			DDRA |= (1 << PA0);
		break;
		
		//set pin23
		case 23 :
		if(u8Mode == 0)
			DDRA &= ~(1 << PA1);
		else 
			DDRA |= (1 << PA1);
		break;
		
		//set pin24
		case 24 :
		if(u8Mode == 0)
			DDRA &= ~(1 << PA2);
		else 
			DDRA |= (1 << PA2);
		break;
		
		//set pin25
		case 25 :
		if(u8Mode == 0)
			DDRA &= ~(1 << PA3);
		else 
			DDRA |= (1 << PA3);
		break;
		
		//set pin26
		case 26 :
		if(u8Mode == 0)
			DDRA &= ~(1 << PA4);
		else 
			DDRA |= (1 << PA4);
		break;
		
		//set pin27
		case 27 :
		if(u8Mode == 0)
			DDRA &= ~(1 << PA5);
		else 
			DDRA |= (1 << PA5);
		break;
		
		//set pin28
		case 28 :
		if(u8Mode == 0)
			DDRA &= ~(1 << PA6);
		else 
			DDRA |= (1 << PA6);
		break;
		
		//set pin29
		case 29 :
		if(u8Mode == 0)
			DDRA &= ~(1 << PA7);
		else 
			DDRA |= (1 << PA7);
		break;
		
		//set pin30
		case 30 :
		if(u8Mode == 0)
			DDRC &= ~(1 << PC7);
		else 
			DDRC |= (1 << PC7);
		break;
		
		//set pin31
		case 31 :
		if(u8Mode == 0)
			DDRC &= ~(1 << PC6);
		else 
			DDRC |= (1 << PC6);
		break;
		
		//set pin32
		case 32 :
		if(u8Mode == 0)
			DDRC &= ~(1 << PC5);
		else 
			DDRC |= (1 << PC5);
		break;
		
		//set pin33
		case 33 :
		if(u8Mode == 0)
			DDRC &= ~(1 << PC4);
		else
			DDRC |= (1 << PC4);
		break;
		
		//set pin34
		case 34 :
		if(u8Mode == 0)
			DDRC &= ~(1 << PC3);
		else 
			DDRC |= (1 << PC3);
		break;
		
		//set pin35
		case 35 :
		if(u8Mode == 0)
			DDRC &= ~(1 << PC2);
		else 
			DDRC |= (1 << PC2);
		break;
		
		//set pin36
		case 36 :
		if(u8Mode == 0)
			DDRC &= ~(1 << PC1);
		else 
			DDRC |= (1 << PC1);
		break;
		
		//set pin37
		case 37 :
		if(u8Mode == 0)
			DDRC &= ~(1 << PC0);
		else 
			DDRC |= (1 << PC0);
		break;
		
		//set pin38
		case 38 :
		if(u8Mode == 0)
			DDRD &= ~(1 << PD7);
		else 
			DDRD |= (1 << PD7);
		break;
		
		//set pin39
		case 39 :
		if(u8Mode == 0)
			DDRG &= ~(1 << PG2);
		else 
			DDRG |= (1 << PG2);
		break;
		
		//set pin40
		case 40 :
		if(u8Mode == 0)
			DDRG &= ~(1 << PG1);
		else 
			DDRG |= (1 << PG1);
		break;
		
		//set pin41
		case 41 :
		if(u8Mode == 0)
			DDRG &= ~(1 << PG0);
		else 
			DDRG |= (1 << PG0);
		break;
		
		//set pin42
		case 42 :
		if(u8Mode == 0)
			DDRL &= ~(1 << PL7);
		else
			DDRL |= (1 << PL7);
		break;
		
		//set pin43
		case 43 :
		if(u8Mode == 0)
			DDRL &= ~(1 << PL6);
		else 
			DDRL |= (1 << PL6);
		break;
		
		//set pin44
		case 44 :
		if(u8Mode == 0)
			DDRL &= ~(1 << PE5);
		else 
			DDRL |= (1 << PE5);
		break;
		
		//set pin45
		case 45 :
		if(u8Mode == 0)
			DDRL &= ~(1 << PL4);
		else 
			DDRL |= (1 << PL4);
		break;
		
		//set pin46
		case 46 :
		if(u8Mode == 0)
			DDRL &= ~(1 << PL3);
		else 
			DDRL |= (1 << PL3);
		break;
		
		//set pin47
		case 47 :
		if(u8Mode == 0)
			DDRL &= ~(1 << PL2);
		else 
			DDRL |= (1 << PL2);
		break;
		
		//set pin48
		case 48 :
		if(u8Mode == 0)
			DDRL &= ~(1 << PL1);
		else 
			DDRL |= (1 << PL1);
		break;
		
		//set pin49
		case 49 :
		if(u8Mode == 0)
			DDRL &= ~(1 << PL0);
		else 
			DDRL |= (1 << PL0);
		break;
		
		//set pin50
		case 50 :
		if(u8Mode == 0)
			DDRB &= ~(1 << PB3);
		else
			DDRB |= (1 << PB3);
		break;
		
		//set pin51
		case 51 :
		if(u8Mode == 0)
			DDRB &= ~(1 << PB2);
		else 
			DDRB |= (1 << PB2);
		break;
		
		//set pin52
		case 52 :
		if(u8Mode == 0)
			DDRB &= ~(1 << PB1);
		else
			DDRB |= (1 << PB1);
		break;
		
		//set pin53
		case 53 :
		if(u8Mode == 0)
			DDRB &= ~(1 << PB0);
		else 
			DDRB |= (1 << PB0);
		break;
		
		default :
		break;
	}
}

void gpio_vSetState(uint8_t u8Pin, uint8_t u8Value){
	switch(u8Pin){
		//set pin0
		case 0 :
		if(u8Value == 0) // in this case we have to put value 0 on the output pin
			PORTE &= ~(1 << PE0); // set the output value of the pin to LOW by setting the required pin from PORT register to 0
		else  // in this case we have to put value 1 on the output pin
			PORTE |= (1 << PE0); // set the output value of the pin to HIGH by setting the required pin from PORT register to 1
		break;
		
		//set pin1
		case 1 :
		if(u8Value == 0)
			PORTE &= ~(1 << PE1);
		else 
			PORTE |= (1 << PE1);
		break;
		
		//set pin2
		case 2 :
		if(u8Value == 0)
			PORTE &= ~(1 << PE4);
		else 
			PORTE |= (1 << PE4);
		break;
		
		//set pin3
		case 3 :
		if(u8Value == 0)
			PORTE &= ~(1 << PE5);
		else 
			PORTE |= (1 << PE5);
		break;
		
		//set pin4
		case 4 :
		if(u8Value == 0)
			PORTG &= ~(1 << PG5);
		else 
			PORTG |= (1 << PG5);
		break;
		
		//set pin5
		case 5 :
		if(u8Value == 0)
			PORTE &= ~(1 << PE3);
		else 
			PORTE |= (1 << PE3);
		break;
		
		//set pin6
		case 6 :
		if(u8Value == 0)
			PORTH &= ~(1 << PH3);
		else 
			PORTH |= (1 << PH3);
		break;
		
		//set pin7
		case 7 :
		if(u8Value == 0)
			PORTH &= ~(1 << PH4);
		else 
			PORTH |= (1 << PH4);
		break;
		//set pin8
		case 8 :
		if(u8Value == 0)
			PORTH &= ~(1 << PH5);
		else
			PORTH |= (1 << PH5);
		break;
		
		//set pin9
		case 9 :
		if(u8Value == 0)
			PORTH &= ~(1 << PH6);
		else 
			PORTH |= (1 << PH6);
		break;
		
		//set pin10
		case 10 :
		if(u8Value == 0)
			PORTB &= ~(1 << PB4);
		else 
			PORTB |= (1 << PB4);
		break;
		
		//set pin11
		case 11 :
		if(u8Value == 0)
			PORTB &= ~(1 << PB5);
		else 
			PORTB |= (1 << PB5);
		break;
		
		//set pin12
		case 12 :
		if(u8Value == 0)
			PORTB &= ~(1 << PB6);
		else 
			PORTB |= (1 << PB6);
		break;
		
		//set pin13
		case 13 :
		if(u8Value == 0)
			PORTB &= ~(1 << PB7);
		else 
			PORTB |= (1 << PB7);
		break;
		
		//set pin14
		case 14 :
		if(u8Value == 0)
			PORTJ &= ~(1 << PJ1);
		else 
			PORTJ |= (1 << PJ1);
		break;
		
		//set pin15
		case 15 :
		if(u8Value == 0)
			PORTJ &= ~(1 << PJ0);
		else 
			PORTJ |= (1 << PJ0);
		break;
		
		//set pin16
		case 16 :
		if(u8Value == 0)
			PORTH &= ~(1 << PH1);
		else 
			PORTH |= (1 << PH1);
		break;
		
		//set pin17
		case 17 :
		if(u8Value == 0)
			PORTH &= ~(1 << PH0);
		else 
			PORTH |= (1 << PH0);
		break;
		
		//set pin18
		case 18 :
		if(u8Value == 0)
			PORTD &= ~(1 << PD3);
		else 
			PORTD |= (1 << PD3);
		break;
		
		//set pin19
		case 19 :
		if(u8Value == 0)
			PORTD &= ~(1 << PD2);
		else 
			PORTD |= (1 << PD2);
		break;
		
		//set pin20
		case 20 :
		if(u8Value == 0)
			PORTD &= ~(1 << PD1);
		else 
			PORTD |= (1 << PD1);
		break;
		
		//set pin21
		case 21 :
		if(u8Value == 0)
			PORTD &= ~(1 << PD0);
		else 
			PORTD |= (1 << PD0);
		break;
		
		//set pin22
		case 22 :
		if(u8Value == 0)
			PORTA &= ~(1 << PA0);
		else
			PORTA |= (1 << PA0);
		break;
		
		//set pin23
		case 23 :
		if(u8Value == 0)
			PORTA &= ~(1 << PA1);
		else 
			PORTA |= (1 << PA1);
		break;
		
		//set pin24
		case 24 :
		if(u8Value == 0)
			PORTA &= ~(1 << PA2);
		else 
			PORTA |= (1 << PA2);
		break;
		
		//set pin25
		case 25 :
		if(u8Value == 0)
			PORTA &= ~(1 << PA3);
		else 
			PORTA |= (1 << PA3);
		break;
		
		//set pin26
		case 26 :
		if(u8Value == 0)
			PORTA &= ~(1 << PA4);
		else 
			PORTA |= (1 << PA4);
		break;
		
		//set pin27
		case 27 :
		if(u8Value == 0)
			PORTA &= ~(1 << PA5);
		else 
			PORTA |= (1 << PA5);
		break;
		
		//set pin28
		case 28 :
		if(u8Value == 0)
			PORTA &= ~(1 << PA6);
		else 
			PORTA |= (1 << PA6);
		break;
		
		//set pin29
		case 29 :
		if(u8Value == 0)
			PORTA &= ~(1 << PA7);
		else 
			PORTA |= (1 << PA7);
		break;
		
		//set pin30
		case 30 :
		if(u8Value == 0)
			PORTC &= ~(1 << PC7);
		else 
			PORTC |= (1 << PC7);
		break;
		
		//set pin31
		case 31 :
		if(u8Value == 0)
			PORTC &= ~(1 << PC6);
		else 
			PORTC |= (1 << PC6);
		break;
		
		//set pin32
		case 32 :
		if(u8Value == 0)
			PORTC &= ~(1 << PC5);
		else 
			PORTC |= (1 << PC5);
		break;
		
		//set pin33
		case 33 :
		if(u8Value == 0)
			PORTC &= ~(1 << PC4);
		else 
			PORTC |= (1 << PC4);
		break;
		
		//set pin34
		case 34 :
		if(u8Value == 0)
			PORTC &= ~(1 << PC3);
		else 
			PORTC |= (1 << PC3);
		break;
		
		//set pin35
		case 35 :
		if(u8Value == 0)
			PORTC &= ~(1 << PC2);
		else 
			PORTC |= (1 << PC2);
		break;
		
		//set pin36
		case 36 :
		if(u8Value == 0)
			PORTC &= ~(1 << PC1);
		else 
			PORTC |= (1 << PC1);
		break;
		
		//set pin37
		case 37 :
		if(u8Value == 0)
			PORTC &= ~(1 << PC0);
		else 
			PORTC |= (1 << PC0);
		break;
		
		//set pin38
		case 38 :
		if(u8Value == 0)
			PORTD &= ~(1 << PD7);
		else 
			PORTD |= (1 << PD7);
		break;
		
		//set pin39
		case 39 :
		if(u8Value == 0)
			PORTG &= ~(1 << PG2);
		else 
			PORTG |= (1 << PG2);
		break;
		
		//set pin40
		case 40 :
		if(u8Value == 0)
			PORTG &= ~(1 << PG1);
		else 
			PORTG |= (1 << PG1);
		break;
		
		//set pin41
		case 41 :
		if(u8Value == 0)
			PORTG &= ~(1 << PG0);
		else 
			PORTG |= (1 << PG0);
		break;
		
		//set pin42
		case 42 :
		if(u8Value == 0)
			PORTL &= ~(1 << PL7);
		else 
			PORTL |= (1 << PL7);
		break;
		
		//set pin43
		case 43 :
		if(u8Value == 0)
			PORTL &= ~(1 << PL6);
		else 
			PORTL |= (1 << PL6);
		break;
		
		//set pin44
		case 44 :
		if(u8Value == 0)
			PORTL &= ~(1 << PE5);
		else
			PORTL |= (1 << PE5);
		break;
		
		//set pin45
		case 45 :
		if(u8Value == 0)
			PORTL &= ~(1 << PL4);
		else 
			PORTL |= (1 << PL4);
		break;
		
		//set pin46
		case 46 :
		if(u8Value == 0)
			PORTL &= ~(1 << PL3);
		else
			PORTL |= (1 << PL3);
		break;
		
		//set pin47
		case 47 :
		if(u8Value == 0)
			PORTL &= ~(1 << PL2);
		else 
			PORTL |= (1 << PL2);
		break;
		
		//set pin48
		case 48 :
		if(u8Value == 0)
			PORTL &= ~(1 << PL1);
		else 
			PORTL |= (1 << PL1);
		break;
		
		//set pin49
		case 49 :
		if(u8Value == 0)
			PORTL &= ~(1 << PL0);
		else 
			PORTL |= (1 << PL0);
		break;
		
		//set pin50
		case 50 :
		if(u8Value == 0)
			PORTB &= ~(1 << PB3);
		else
			PORTB |= (1 << PB3);
		break;
		
		//set pin51
		case 51 :
		if(u8Value == 0)
			PORTB &= ~(1 << PB2);
		else 
			PORTB |= (1 << PB2);
		break;
		
		//set pin52
		case 52 :
		if(u8Value == 0)
			PORTB &= ~(1 << PB1);
		else 
			PORTB |= (1 << PB1);
		break;
		
		//set pin53
		case 53 :
		if(u8Value == 0)
			PORTB &= ~(1 << PB0);
		else 
			PORTB |= (1 << PB0);
		break;
		
		default :
		break;
	}
}

void gpio_vActivatePullupRes(uint8_t u8Pin){
	
	switch(u8Pin){
		//pin0
		case 0 :
			PORTE |= (1 << PE0); // activate the pullup resistor on required input pin
		break;
		
		//pin1
		case 1 :
			PORTE |= (1 << PE1);
		break;
		
		//pin2
		case 2 :
			PORTE |= (1 << PE4);
		break;
		
		//pin3
		case 3 :
			PORTE |= (1 << PE5);
		break;
		
		//pin4
		case 4 :
			PORTG |= (1 << PG5);
		break;
		
		//pin5
		case 5 :
			PORTE |= (1 << PE3);
		break;
		
		//pin6
		case 6 :
			PORTH |= (1 << PH3);
		break;
		
		//pin7
		case 7 :
			PORTH |= (1 << PH4);
		break;
		
		//pin8
		case 8 :
			PORTH |= (1 << PH5);
		break;
		
		//pin9
		case 9 :
			PORTH |= (1 << PH6);
		break;
		
		//pin10
		case 10 :
			PORTB |= (1 << PB4);
		break;
		
		//pin11
		case 11 :
			PORTB |= (1 << PB5);
		break;
		
		//pin12
		case 12 :
			PORTB |= (1 << PB6);
		break;
		
		//pin13
		case 13 :
			PORTB |= (1 << PB7);
		break;
		
		//pin14
		case 14 :
			PORTJ |= (1 << PJ1);
		break;
		
		//pin15
		case 15 :
			PORTJ |= (1 << PJ0);
		break;
		
		//pin16
		case 16 :
			PORTH |= (1 << PH1);
		break;
		
		//pin17
		case 17 :
			PORTH |= (1 << PH0);
		break;
		
		//pin18
		case 18 :
			PORTD |= (1 << PD3);
		break;
		
		//pin19
		case 19 :
			PORTD |= (1 << PD2);
		break;
		
		//pin20
		case 20 :
			PORTD |= (1 << PD1);
		break;
		
		//pin21
		case 21 :
			PORTD |= (1 << PD0);
		break;
		
		//pin22
		case 22 :
			PORTA |= (1 << PA0);
		break;
		
		//pin23
		case 23 :
			PORTA |= (1 << PA1);
		break;
		
		//pin24
		case 24 :
			PORTA |= (1 << PA2);
		break;
		
		//pin25
		case 25 :
			PORTA |= (1 << PA3);
		break;
		
		//pin26
		case 26 :
			PORTA |= (1 << PA4);
		break;
		
		//pin27
		case 27 :
			PORTA |= (1 << PA5);
		break;
		
		//pin28
		case 28 :
			PORTA |= (1 << PA6);
		break;
		
		//pin29
		case 29 :
			PORTA |= (1 << PA7);
		break;
		
		//pin30
		case 30 :
			PORTC |= (1 << PC7);
		break;
		
		//pin31
		case 31 :
			PORTC |= (1 << PC6);
		break;
		
		//pin32
		case 32 :
			PORTC |= (1 << PC5);
		break;
		
		//pin33
		case 33 :
			PORTC |= (1 << PC4);
		break;
		
		//pin34
		case 34 :
			PORTC |= (1 << PC3);
		break;
		
		//pin35
		case 35 :
			PORTC |= (1 << PC2);
		break;
		
		//pin36
		case 36 :
			PORTC |= (1 << PC1);
		break;
		
		//pin37
		case 37 :
			PORTC |= (1 << PC0);
		break;
		
		//pin38
		case 38 :
			PORTD |= (1 << PD7);
		break;
		
		//pin39
		case 39 :
			PORTG |= (1 << PG2);
		break;
		
		//pin40
		case 40 :
			PORTG |= (1 << PG1);
		break;
		
		//pin41
		case 41 :
			PORTG |= (1 << PG0);
		break;
		
		//pin42
		case 42 :
			PORTL |= (1 << PL7);
		break;
		
		//pin43
		case 43 :
			PORTL |= (1 << PL6);
		break;
		
		//pin44
		case 44 :
			PORTE |= (1 << PE5);
		break;
		
		//pin45
		case 45 :
			PORTL |= (1 << PL4);
		break;
		
		//pin46
		case 46 :
			PORTL |= (1 << PL3);
		break;
		
		//pin47
		case 47 :
			PORTL |= (1 << PL2);
		break;
		
		//pin48
		case 48 :
			PORTL |= (1 << PL1);
		break;
		
		//pin49
		case 49 :
			PORTL |= (1 << PL0);
		break;
		
		//pin50
		case 50 :
			PORTB |= (1 << PB3);
		break;
		
		//pin51
		case 51 :
			PORTB |= (1 << PB2);
		break;
		
		//pin52
		case 52 :
			PORTB |= (1 << PB1);
		break;
		
		//pin53
		case 53 :
			PORTB |= (1 << PB0);
		break;
		
		default :
		break;
	}
	
}

uint8_t gpio_u8ReadState(uint8_t u8Pin){
	
	switch(u8Pin){
		//read pin0
		case 0 :
			return PINE & (1 << PE0); // return the value of the required pin (0 if we have LOW on pin or a positive value if we have HIGH on pin)
		break;
		
		//read pin1
		case 1 :
			return PINE & (1 << PE1);
		break;
		
		//read pin2
		case 2 :
			return PINE & (1 << PE4);
		break;
		
		//read pin3
		case 3 :
			return PINE & (1 << PE5);
		break;
		
		//read pin4
		case 4 :
			return PING & (1 << PG5);
		break;
		
		//read pin5
		case 5 :
			return PINE & (1 << PE3);
		break;
		
		//read pin6
		case 6 :
			return PINH & (1 << PH3);
		break;
		
		//read pin7
		case 7 :
			return PINH & (1 << PH4);
		break;
		
		//read pin8
		case 8 :
			return PINH & (1 << PH5);
		break;
		
		//read pin9
		case 9 :
			return PINH & (1 << PH6);
		break;
		
		//read pin10
		case 10 :
			return PINB & (1 << PB4);
		break;
		
		//read pin11
		case 11 :
			return PINB & (1 << PB5);
		break;
		
		//read pin12
		case 12 :
			return PINB & (1 << PB6);
		break;
		
		//read pin13
		case 13 :
			return PINB & (1 << PB7);
		break;
		
		//read pin14
		case 14 :
			return PINJ & (1 << PJ1);
		break;
		
		//read pin15
		case 15 :
			return PINJ & (1 << PJ0);
		break;
		
		//read pin16
		case 16 :
			return PINH & (1 << PH1);
		break;
		
		//read pin17
		case 17 :
			return PINH & (1 << PH0);
		break;
		
		//read pin18
		case 18 :
			return PIND & (1 << PD3);
		break;
		
		//read pin19
		case 19 :
			return PIND & (1 << PD2);
		break;
		
		//read pin20
		case 20 :
			return PIND & (1 << PD1);
		break;
		
		//read pin21
		case 21 :
			return PIND & (1 << PD0);
		break;
		
		//read pin22
		case 22 :
			return PINA & (1 << PA0);
		break;
		
		//read pin23
		case 23 :
			return PINA & (1 << PA1);
		break;
		
		//set pin24
		case 24 :
			return PINA & (1 << PA2);
		break;
		
		//read pin25
		case 25 :
			return PINA & (1 << PA3);
		break;
		
		//read pin26
		case 26 :
			return PINA & (1 << PA4);
		break;
		
		//read pin27
		case 27 :
			return PINA & (1 << PA5);
		break;
		
		//read pin28
		case 28 :
			return PINA & (1 << PA6);
		break;
		
		//read pin29
		case 29 :
			return PINA & (1 << PA7);
		break;
		
		//read pin30
		case 30 :
			return PINC & (1 << PC7);
		break;
		
		//read pin31
		case 31 :
			return PINC & (1 << PC6);
		break;
		
		//read pin32
		case 32 :
			return PINC & (1 << PC5);
		break;
		
		//read pin33
		case 33 :
			return PINC & (1 << PC4);
		break;
		
		//read pin34
		case 34 :
			return PINC & (1 << PC3);
		break;
		
		//read pin35
		case 35 :
			return PINC & (1 << PC2);
		break;
		
		//read pin36
		case 36 :
			return PINC & (1 << PC1);
		break;
		
		//read pin37
		case 37 :
			return PINC & (1 << PC0);
		break;
		
		//read pin38
		case 38 :
			return PIND & (1 << PD7);
		break;
		
		//read pin39
		case 39 :
			return PING & (1 << PG2);
		break;
		
		//read pin40
		case 40 :
			return PING & (1 << PG1);
		break;
		
		//read pin41
		case 41 :
			return PING & (1 << PG0);
		break;
		
		//read pin42
		case 42 :
			return PINL & (1 << PL7);
		break;
		
		//read pin43
		case 43 :
			return PINL & (1 << PL6);
		break;
		
		//read pin44
		case 44 :
			return PINE & (1 << PE5);
		break;
		
		//read pin45
		case 45 :
			return PINL & (1 << PL4);
		break;
		
		//read pin46
		case 46 :
			return PINL & (1 << PL3);
		break;
		
		//read pin47
		case 47 :
			return PINL & (1 << PL2);
		break;
		
		//read pin48
		case 48 :
			return PINL & (1 << PL1);
		break;
		
		//read pin49
		case 49 :
			return PINL & (1 << PL0);
		break;
		
		//read pin50
		case 50 :
			return PINB & (1 << PB3);
		break;
		
		//read pin51
		case 51 :
			return PINB & (1 << PB2);
		break;
		
		//read pin52
		case 52 :
			return PINB & (1 << PB1);
		break;
		
		//read pin53
		case 53 :
			return PINB & (1 << PB0);
		break;
		
		default :
		return -1;
		break;
	}
	return -1;
}


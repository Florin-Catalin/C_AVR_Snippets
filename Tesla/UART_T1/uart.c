/*
 * uart_driver_homeMade.c
 *
 * Created: 4/6/2021 10:07:43 PM
 * Author : florin.ungureanu
 */ 

#include "uart.h"

void UART_vSerialBegin(uint16_t ui16Baudrate)
{
	uint16_t u16_UBRR  = F_CPU/(16L* ui16Baudrate) - 1 ;
	UBRR0H = (uint8_t)(u16_UBRR >> 8);
	UBRR0L = (uint8_t)(u16_UBRR);
	/* Enable receiver and transmitter */
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

  UCSR0C |= (1 << UCSZ01)|(1 << UCSZ00);// Set frame: 1 byte, 1 stop bit.
 
}

uint8_t UART_ui8SerialReadByte()
{
	while (!(UCSR0A & (1 << RXC0)));// waiting for receive flag to be set in the UART control register
	return UDR0;
}
void UART_vSerialWriteByte (uint8_t u8ByteToWrite)
{
	while ( !( UCSR0A & (1<<UDRE0)) ); // waiting for data empty enable flag to be set in the UART control register
	UDR0 = u8ByteToWrite;
}

void UART_vFlush()
{
	uint8_t u8Dummy;
	while ( UCSR0A & (1<<RXC0) ) 
	{
		u8Dummy = UDR0;
	}
}
void UART_vSerialWriteString(uint8_t *u8String)
{
	while (*u8String != '\0')
	{
		UART_vSerialWriteByte(*u8String);
		++u8String;
	}
}

void UART_vSerialWriteNumber(uint32_t u32Number) 
{
	if(u32Number >= 10) // break down numbers in individual digits
	{
		UART_vSerialWriteNumber(u32Number / 10) ;
		u32Number %= 10;
	}
	UART_vSerialWriteByte(u32Number + 48 ); // convert the digit to text by adding the ASCII code for 0
}

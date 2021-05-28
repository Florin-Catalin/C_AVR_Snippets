#include "uart.h"


void uart_vInitUart( uint16_t u16Baund) {
	
	uint8_t u8UBRR = (u32F_CPU/(16UL*u16Baund))-1;		//--- calculated UBRR for Async Normal mode
	
	UBRR0H = 0x00;		//--- initialization register High with 0 on every bit
	UBRR0L = u8UBRR;	//--- initialization register Low with UBRR 
	
	UCSR0B = (3<<TXEN0);	//--- activated TX & activated RX
	
	UCSR0C = (3<<UCSZ00);	//--- set bit 1 and 2 from UCSR0C with 1 (set allocate data space with 8 bit)
	
}

void uart_vTransmit(uint8_t u8data){
	while ( !(UCSR0A & (1 << UDRE0)));	//--- Wait for empty transmit buffer, if bit its 1 buffer in full 
	UDR0 = u8data;						//--- Put data into buffer, sends the data 
}

uint8_t uart_u8Received(){
	while ( !(UCSR0A & (1<<RXCIE0)));		//--- Wait for data to be received
	return UDR0;							//--- Get and return received data from buffer
}

void uart_vTransmitMsg(uint8_t *u8Msg){
	while (*u8Msg != 0)						//--- Check for null
	uart_vTransmit(*u8Msg++);				//--- Increment the pointer
}

void uart_vTransmitNumber(uint32_t u32Num){
	if (u32Num >= extractlastdigit) {
		uart_vTransmitNumber(u32Num/extractlastdigit);	//--- call recursive without the last digit
		u32Num = u32Num%extractlastdigit;				
	}
	uart_vTransmit(u32Num+AsciNr);		//--- transmit last digit 
}






void uart_vTestFunctionalitys(){
	
	//uint16_t const b = 9600; // set baud rate with 9600
	//uart_vInitUart(b); // Initializing Uart with baud rate
	
	uint8_t *u8tx_data= "test";  // increment pointer with value string
	uart_vTransmitMsg(u8tx_data); //transmit string and result is "test"
	
	uart_vTransmit(0x0d); // next line
	uart_vTransmitNumber(23); // transmit number and result, in this case number 23
	
	uart_vTransmit(0x0d); // next line
	uint8_t* u8tx_data2 = uart_u8Received(); // send 1 char from keyboard and return value in u8tx_data2
	uart_vTransmit(u8tx_data2); // transmit variable (size 1 char)
	
	uart_vTransmit(0x0d); // next line
	uart_vTransmitMsg("All Tests is working");
	
}
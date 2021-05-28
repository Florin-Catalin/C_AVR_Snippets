
#include "USART0.h"
#define MAX_LENGTH 5


static volatile uint8_t USART0_u8Tx_index;
static volatile uint8_t USART0_u8Rx_index;

static volatile uint8_t USART0_u8Tx_counter;
static volatile uint8_t USART0_u8Rx_counter;


static volatile uint8_t USART0_u8Buf_transmit[MAX_LENGTH];
static volatile uint8_t USART0_u8Buf_receive[MAX_LENGTH];



ISR(USART0_UDRE_vect){
	if(!(USART0_u8Tx_counter == USART0_u8Tx_index)){
		UDR0 = USART0_u8Buf_transmit[USART0_u8Tx_counter];
		USART0_u8Tx_counter=(USART0_u8Tx_counter + 1) % MAX_LENGTH; //nr caractere scoase
	}
	else{
		UCSR0B &= ~(1u << UDRIE0);
	}
}


ISR(USART0_RX_vect){

	USART0_u8Buf_receive[USART0_u8Rx_index] = UDR0;
	USART0_u8Rx_index = (USART0_u8Rx_index+1) % MAX_LENGTH;
}


ISR(USART0_TX_vect){
		if(USART0_u8Tx_index == USART0_u8Tx_counter){
			UCSR0B &= ~(1u << UDRIE0);
		}
}


void USART0_vInit(uint32_t u32Baudrate){
	uint32_t u32Ubrr = (F_CPU/16/u32Baudrate-1);
	UCSR0B = 0x00;
	UCSR0C = 0x00;
	
	UBRR0L = (uint8_t) u32Ubrr;
	UBRR0H = (uint8_t) u32Ubrr >> 8u;
	
	UCSR0B = (1u<<RXEN0) | (1u<<TXEN0) | (1u<<TXCIE0) | (1u<<RXCIE0); //enables USART receiver and transmitter; enables transmit and receive interrupt
	UCSR0C = (1u<<USBS0) | (1u<<UCSZ00) | (1u<<UCSZ01); //number of stop bits(0->1, 1->2bits) and data bits(11->8bits)
	
}


void USART0_vTransmit(uint8_t data){
	USART0_u8Buf_transmit[USART0_u8Tx_index]=data;
	USART0_u8Tx_index = (USART0_u8Tx_index + 1) % MAX_LENGTH;

	UCSR0B|=(1u<<UDRIE0);
}


uint8_t USART0_uReceive(void){
	uint8_t u8Receive_char;
	
	while(USART0_u8Rx_index == USART0_u8Rx_counter); 
	u8Receive_char = USART0_u8Buf_receive[USART0_u8Rx_counter];
	USART0_u8Rx_counter = (USART0_u8Rx_counter+1) % MAX_LENGTH; //if rx_counter reaches max_length -> reset
	
	return u8Receive_char;
		
}


void USART0_vStringTransmit(uint8_t *u8String_to_transmit){
	uint8_t u8Transmit_index = 0;
	
	while(*(u8String_to_transmit + u8Transmit_index) != '\0'){  //while str not empty, transmit next character
		USART0_vTransmit(*(u8String_to_transmit + u8Transmit_index));
		u8Transmit_index++;
	}
}


uint8_t *USART0_uStringReceive(void){
	uint8_t* u8Received_string = "";
	uint8_t u8Receive_index = 0;
	u8Received_string[u8Receive_index] = USART0_uReceive();
	
	while(u8Received_string[u8Receive_index] != '\0'){
		++u8Receive_index;
		u8Received_string[u8Receive_index] = USART0_uReceive();	
	}
	return u8Received_string;
}


void UART0_vTransmitNumber(uint32_t u32Number)
{
	/* While the number has at least two digits left, 'erase' one digit */
	if(u32Number>=10)
	{
		UART0_vTransmitNumber(u32Number/10);
		u32Number = u32Number%10;
	}
	/* Transmit each digit as a character on the back-trace call */
	USART0_vTransmit(u32Number + '0');
}
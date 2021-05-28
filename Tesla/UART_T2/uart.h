/*
 * uart.h
 *
 */

#include <avr/io.h>
#define u32F_CPU 16000000UL // CPU frequency
#define AsciNr 48 // 48 = 0 in asci code
#define extractlastdigit 10


/*
We set the UART communication protocol
Input: Baund_Rate
Output: None
*/
void uart_vInitUart( uint16_t u16Baund);

/* 
 We transmit a character
 Input: one_char
 Output: None
*/
void uart_vTransmit(uint8_t u8data);

/*
Receives a character
Input: none
Output: one_char
*/
uint8_t uart_u8Received();

/*
We transmit a string
Input: string
Output: none
*/
void uart_vTransmitMsg(uint8_t *u8Msg);

/*
We transmit  a number
Input: int_number
Output: none
*/
void uart_vTransmitNumber(uint32_t u32Num);



/* 
 Test Functionalitys
 */
void uart_vTestFunctionalitys();

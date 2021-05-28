/*
 * uart.h
 *
 * Created: 4/8/2021 11:49:33 AM
 *  Author: florin.ungureanu
 */ 
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

/* reassure that F_CPU is defined */
#ifndef F_CPU
#define F_CPU 16000000UL
#endif


/*
 * Function: UART_vSerialBegin
 * ----------------------------
 *   The simplest configuration function for working with 8 bits of dataframe with a stop bit without interrupts. 
 *   The value for UBRR ( Baud Rate Register ) consisting in the low byte and high byte is computed according 
 *   to the formula (= fosc/(UBRR0+1))
 *   This value will be used to compute the baud rate generator clock output
 *   The Transmitter divides the baud rate generator clock output by 16 because the state machine for  Asynchronous Normal mode (U2X0 = 0) has 16 states 
	 BAUD =  fosc/(UBRR0 * 16) + 1
	 BAUD - Baud rate (in bits per second, bps).
	 fOSC - System Oscillator clock frequency.
	 UBRRn - Contents of the UBRRHn and UBRRLn Registers
 *  The last part of initialization is setting frame format and enabling the Transmitter and the Receiver
	 
 *   ui16Baudrates: the desired baud rate for UART 
 * 
 *
 *   returns: null 
 */
void UART_vSerialBegin(uint16_t ui16Baudrates);

/*
 * Function: UART_ui8SerialReadByte
 * ----------------------------
   *   The function based on polling the Receive Enable (RXEN0) Flag in the UART control register A,
   The function simply waits for data to be present in the receive buffer by checking the RXC0 Flag, before reading
   the buffer and returning the value.
   
 *
 *   no parameters 
 *
 *   returns: the read byte from the serial bus 
 */
uint8_t UART_ui8SerialReadByte(void);

/*
 * Function: UART_vSerialWriteByte
 * ----------------------------
  *   The function based on polling the Data Register Empty (UDRE0) Flag in the UART control register A,
  simply waits for the transmit buffer to be empty by checking the UDRE0 Flag, before loading it with
  new data to be transmitted.
 *
 *   u8ByteToWrite represents the data to be transmitted  
 *
 *   returns: null
 */
void UART_vSerialWriteByte (uint8_t u8ByteToWrite);


/*
 * Function: UART_vSerialWriteNumber
 * ----------------------------
    The recursive calls breaks number in digits, converts ASCII number to text by knowing that the numbers starts at 48(0)
 *  Finally it will call  UART_vSerialWriteByte for individual digits
 
 *   u32Number number to be printed on the serial console 
 *
 *   returns: the read byte from the serial bus 
 */
void UART_vSerialWriteNumber(uint32_t u32Number);

/*
 * Function: UART_vSerialWriteString
 * ----------------------------
 *   Function that takes every byte from the input string till it reaches the null termination '\0'
     that marks the end of the string and calls the UART_vSerialWriteByte for each individual byte to print it to the serial console
 *
 *   u8String pointer to the starting address of the string 
 *
 *   returns: null
 */
void UART_vSerialWriteString(uint8_t *u8String);

/*
 * Function: UART_vFlush
 * ----------------------------
 *   Cleanup code in case of an error
     it simply reads the UDR0 I/O location until the RXC0 Flag is cleared.
 *
 *   no parameters 
 *
 *   returns: null
 */
void UART_vFlush();








#ifndef USART0_H_
#define USART0_H_
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL


void USART0_vInit(uint32_t u32Baudrate);
void USART0_vTransmit(uint8_t data);
uint8_t USART0_uReceive(void);
void USART0_vStringTransmit(uint8_t *u8String_to_transmit);
uint8_t *USART0_uStringReceive(void);
void USART0_vNumberTransmit(uint16_t n);





#endif /* USART0_H_ */
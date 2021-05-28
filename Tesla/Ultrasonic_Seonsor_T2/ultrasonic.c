
#include "ultrasonic.h"


uint16_t u16rising, u16falling;
volatile uint32_t u32counts;
volatile uint32_t u32distance;
uint16_t u16_us_per_count;




ISR (TIMER4_CAPT_vect) // Implement Interrupt Service Routine 
{
	if (TCCR4B & (1<<ICES4)) // On rising edge
	{
		TCCR4B &= ~(1<<ICES1); // Next time detect falling edge
		u16rising = ICR1; // Save current count
	}
	else // On falling edge
	{
		TCCR4B |= (1<<ICES4); // Next time detect falling edge
		u16falling = ICR4; // Save current count
		u32counts = (uint32_t)u16falling - (uint32_t)u16rising; 
		u32distance = (uint32_t)u16_us_per_count * u32counts/ dist; // useconds / 58 to get distance in cm
	
	}
}

ISR (TIMER4_COMPA_vect) // Implement Interrupt Service Routine for transmit signal from pin 33
{
	//Digital pin 33 set High and Low
	GPIO_vDigitalWrite(triggerPin33, 1); // Transmit signal from trigger
	_delay_us(us10); // 10 microseconds
	GPIO_vDigitalWrite(triggerPin33, 0); // Close transmition
	
}

void ultrasonic_vinit_timer4() 
{

	TCCR4B |= (1 << WGM42) | (1 << ICNC4); // WGenerationMode is set and control the counting sequence of the counter
	TCCR4B |= 1 << CS41 | 1 << CS40; // Set prescaler with 64

	TIMSK4 |= 1 << OCIE4A | 1 << ICIE4;  // Output Compare A Match Interrupt Enable and Input Capture Interrupt Enable
	
	
	TCCR4B |= 1 << ICES4; // Input capture on rising edge
	
	OCR4A = TOPOCR; // Set TOP with 17500 op
	
	sei(); // Activated global interrupt
	u16_us_per_count = us_op; // 1.000.000/250.000=us_op   1 second / op after prescale, 1op = 4 microseconds
}

uint16_t ultrasonic_u16get_distance(){
	
	if (u32distance<HighDistance){
		return u32distance; // after compare result return distance
	}
	else{
		return 0; // is not in this interval, return 0
	}
}
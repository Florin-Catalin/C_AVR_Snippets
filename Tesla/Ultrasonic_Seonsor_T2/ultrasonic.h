/*
 * ultrasonic.h
 *
 * Created: 4/22/2021 2:20:15 PM
 *  Author: cristian.morar
 */ 


#define triggerPin33 33 // define pin 33 for trigger
#define echoPin49 49 // define pin 49 for echo
#define F_CPU 16000000UL // CPU frequency
#define TOPOCR 17500 // (16M(CPUf)/48(prescale)/10) * 70ms /100 set TOP
#define us_op 4 // 1.000.000/250.000=4   1 second / op after prescale, 1op = 4 microseconds

#define HighDistance 60 // 60 centimeters
#define dist 58 // calculate distance 29*2
#define us10 10 // 10 microseconds

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



/*
	Function for set Timer4
	INPUT: none
	OUTPUT: Timer 4 its set with "us per count"=4 and Compare Register A with 17500 op
*/
void ultrasonic_vinit_timer4();

/*
	Function that returns the distance from sensor to object
	INPUT: none
	OUTPUT: return distance from sensor to object, if is out of interval 10-30 cm return 0
*/
uint16_t ultrasonic_u16get_distance();

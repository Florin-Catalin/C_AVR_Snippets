/*
 * ultrasonic.c
 *
 * Created: 4/23/2021 2:59:23 PM
 *  Author: florin.ungureanu
 */ 
#include "ultrasonic.h"

static volatile uint32_t ultrasonic_u32RisingEdgeCount;
static volatile uint32_t ultrasonic_u32FallingEdgeCount;
static volatile uint32_t	ultrasonic_u32Distance;

uint32_t Ultrasonic_u32GetDistance(){
	return ( ( (Ultrasonic_SENSOR_UPPER_BOUND < ultrasonic_u32Distance) || (Ultrasonic_SENSOR_LOWER_BOUND > ultrasonic_u32Distance )) ? Ultrasonic_SENSOR_OUT_OF_BOUNDS : ultrasonic_u32Distance) ;
}

void Ultrasonic_vSetPins(){
	gpio_vPinMode(Ultrasonic_TRIGGER_PIN,Ultrasonic_OUTPUT);
	gpio_vPinMode(Ultrasonic_ECHO_PIN,Ultrasonic_INPUT);
	
}
void Ultrasonic_vTimerInit()
{
  Ultrasonic_SET_INPUT_CAPTURE_NOISE_CANCELER;  
  Ultrasonic_SET_PRESCALAR_64;
  Ultrasonic_SET_INPUT_CAPTURE_INTERRUPT_ENABLE;
  Ultrasonic_SET_INPUT_CAPTURE_ON_RISING_EDGE; 
  Ultrasonic_SET_OUTPUT_COMPARE_REGISTER;
  Ultrasonic_SET_GLOBAL_INTERRUPTS;
}

inline void Ultrasonic_vHandleTimer() {
	gpio_vSetState(Ultrasonic_TRIGGER_PIN,Ultrasonic_HIGH);
	_delay_us(Ultrasonic_Trigger_Period);
	gpio_vSetState(Ultrasonic_TRIGGER_PIN,Ultrasonic_LOW);
}
inline void Ultrasonic_vHandleInterruptCaptureRoutine()
{
  if (Ultrasonic_DETECTED_RISING_EDGE) 
  {
     Ultrasonic_NEXT_TIME_DETECT_FALLING_EDGE; 
	Ultrasonic_SAVE_CURRENT_COUNT(ultrasonic_u32RisingEdgeCount);
  }
  else // we are on falling edge
  {
   Ultrasonic_NEXT_TIME_DETECT_RISING_EDGE;
   Ultrasonic_SAVE_CURRENT_COUNT(ultrasonic_u32FallingEdgeCount);
   ultrasonic_u32Distance = (((uint32_t)ultrasonic_u32FallingEdgeCount - (uint32_t)ultrasonic_u32RisingEdgeCount) * Ultrasonic_MICROSEC_PER_TICK ) / Ultrasonic_SPEED_OF_SOUND_DIVIDED_BY_TWO_INVERSED ; 
  }
	
}
ISR(TIMER4_COMPA_vect)
{
	Ultrasonic_vHandleTimer();
}

ISR(TIMER4_CAPT_vect)
{
	Ultrasonic_vHandleInterruptCaptureRoutine();
}
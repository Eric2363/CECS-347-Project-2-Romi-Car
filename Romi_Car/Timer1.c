#include "Timer1.h"

void Timer1_Init(){
	
	SYSCTL_RCGCTIMER_R |= TIMER1; // Enable GPT1
	while((SYSCTL_RCGCTIMER_R & TIMER1) != TIMER1); // wait for timer to enable
	TIMER1_CFG_R = MODE_16bit; // Configure to 16 bit mode
	Timer1A_Init(); // Init Timer1A
}

void Timer1A_Init(){
	
	TIMER1_CTL_R &=~ TIMER1A_MASK; // Disable timer during setup
	TIMER1_TAMR_R = PERIODIC_MODE; // Set to Periodic mode
	TIMER1_TAILR_R = RELOAD - 1; // Reload value of 1ms
	TIMER1_TAPR_R = PRESCALE; // Prescale 
	
}

void Delay(uint16_t ms){
	
	uint16_t i;
	TIMER1_TAILR_R = RELOAD - 1;
	
	// will wait 1ms * x times
	for(i = 0; i < ms; i++){
		TIMER1_CTL_R |= TIMER1A_MASK; // Start Timer
		while(TIMER1_TAR_R != 0); // wait for timer to count down to zero
		
	}
	
}
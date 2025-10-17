#include "tm4c123gh6pm.h"
#include "stdbool.h"

#include "PortF.h"
#include "PWM.h"

#include "Timer1.h"

#define DUTY50 8000 
#define DUTY30 4800
#define DUTY20 3200
#define OFF 0

//load values for 1 second delay using 16bit timer mode. total loaded value = 16,000,000
#define Load1000ms 0xFFFF   // max load for 16bit load is 0xFFFF
#define Prescale1000ms 0xF4 // 16000000/(0xFFFF - 1) = 244 -> 0xF4 in hex

bool START_FLAG = false; // flag to control when to start the motors using switch 1

int main(){
	
	PortF_Init();
  PWM_Init();
	Timer1_Init();
	

	GPIO_PORTF_DATA_R = RED;
	Duty(OFF,OFF);
 
	
	while(1){
		GPIO_PORTF_DATA_R = RED;
		Duty(OFF,OFF);



		while(START_FLAG){
			//Start Flag is true so start PWM
			GPIO_PORTF_DATA_R = GREEN;
			
			
			// Directions
			
			//Forward 50% Duty
			GPIO_PORTB_DATA_R |= FORWARD;
			Duty(DUTY50,DUTY50);
			gpio_delay(Load1000ms, Prescale1000ms);
			
			//Backwards 50% Duty
			GPIO_PORTF_DATA_R = BLUE;
			GPIO_PORTB_DATA_R &=~FORWARD;
			Duty(DUTY50,DUTY50);
			gpio_delay(Load1000ms, Prescale1000ms);
			
			//Forwards Left Turn 20% Duty
			GPIO_PORTF_DATA_R = PURPLE;
			GPIO_PORTB_DATA_R |= FORWARD;
			Duty(DUTY30,DUTY20);
			gpio_delay(Load1000ms, Prescale1000ms);
			
			//Forwards Right Turn 20% Duty
			GPIO_PORTF_DATA_R = YELLOW;
			GPIO_PORTB_DATA_R |= FORWARD;
			Duty(DUTY20,DUTY30);
			gpio_delay(Load1000ms, Prescale1000ms);
			
			//Backwards Left Turn 20% Duty
			GPIO_PORTF_DATA_R = TEAL;
			GPIO_PORTB_DATA_R &=~ FORWARD;
			Duty(DUTY30,DUTY20);
			gpio_delay(Load1000ms, Prescale1000ms);
			
			//Backwards Right Turn 20% Duty
			GPIO_PORTF_DATA_R = WHITE;
			GPIO_PORTB_DATA_R &=~ FORWARD;
			Duty(DUTY20,DUTY30);
			gpio_delay(Load1000ms, Prescale1000ms);
			

			
			//LEFT Pivot 50% Duty
			GPIO_PORTF_DATA_R = BLUE;
			GPIO_PORTB_DATA_R |=DIR_LEFT;
			GPIO_PORTB_DATA_R &=~DIR_RIGHT;
			Duty(DUTY50,DUTY50);
			gpio_delay(Load1000ms, Prescale1000ms);
			
			//RIGHT Pivot 50% Duty
			GPIO_PORTF_DATA_R = BLUE;
			GPIO_PORTB_DATA_R &=~ DIR_LEFT;
			GPIO_PORTB_DATA_R |= DIR_RIGHT;
			Duty(DUTY50,DUTY50);
			gpio_delay(Load1000ms, Prescale1000ms);
			
		}
		
	
	}
	
	
	return 0;
	
}

void GPIOPortF_Handler(){
	GPIO_PORTF_ICR_R = SW1;
	for(volatile int i=0; i<160000; i++); // ~10ms delay at 16MHz

	if(START_FLAG == true){
		START_FLAG = false;
	}
	else{
		START_FLAG = true;
	}
	
}

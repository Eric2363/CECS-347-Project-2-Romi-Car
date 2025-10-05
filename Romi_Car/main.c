#include "tm4c123gh6pm.h"
#include "stdbool.h"

#include "PortF.h"
#include "PWM.h"
#include "PLL.h"
#include "Timer1.h"

#define DUTY50 8000
#define DUTY30 4800
#define DUTY20 3200
#define OFF 0
void PortF_Init();
void DelayMs(uint32_t ms);

uint32_t ONE_SEC = 1000;
bool START_FLAG = false;

int main(){
	
	//PLL_Init();
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
			DelayMs(250);
			
			//Backwards 50% Duty
			GPIO_PORTF_DATA_R = BLUE;
			GPIO_PORTB_DATA_R &=~FORWARD;
			Duty(DUTY50,DUTY50);
			DelayMs(250);
			
			//Forwards Left Turn 20% Duty
			GPIO_PORTF_DATA_R = PURPLE;
			GPIO_PORTB_DATA_R |= FORWARD;
			Duty(DUTY30,DUTY20);
			DelayMs(250);
			
			//Forwards Right Turn 20% Duty
			GPIO_PORTF_DATA_R = YELLOW;
			GPIO_PORTB_DATA_R |= FORWARD;
			Duty(DUTY20,DUTY30);
			DelayMs(250);
			
			//Backwards Left Turn 20% Duty
			GPIO_PORTF_DATA_R = TEAL;
			GPIO_PORTB_DATA_R &=~ FORWARD;
			Duty(DUTY30,DUTY20);
			DelayMs(250);
			
			//Backwards Right Turn 20% Duty
			GPIO_PORTF_DATA_R = WHITE;
			GPIO_PORTB_DATA_R &=~ FORWARD;
			Duty(DUTY20,DUTY30);
			DelayMs(250);
			
			//Left Pivot 50% Duty
			GPIO_PORTF_DATA_R = RED;
			GPIO_PORTB_DATA_R |= FORWARD;
			Duty(DUTY50,0);
			DelayMs(250);
			
			//Right Pivot 50% Duty
			GPIO_PORTF_DATA_R = RED;
			GPIO_PORTB_DATA_R |=FORWARD;
			Duty(0,DUTY50);
			DelayMs(250);
			
			//OFF
			Duty(0,0);
			START_FLAG = false;
			break;
		}
		
	
	}
	
	
	return 0;
	
}

void GPIOPortF_Handler(){
	GPIO_PORTF_ICR_R = SW1;
	
	if(START_FLAG == true){
		START_FLAG = false;
	}
	else{
		START_FLAG = true;
	}
	
}
// Software Delay
void DelayMs(uint32_t ms){
    volatile uint32_t i, j;
    for(j = 0; j < ms; j++){
        for(i = 0; i < 13000; i++);   // 1 ms @ 80 MHz
    }
}


	
	

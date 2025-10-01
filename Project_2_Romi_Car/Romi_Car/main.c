#include "tm4c123gh6pm.h"

#include "PortF.h"
#include "PWM.h"


void PortF_Init();

int main(){
	
	PortF_Init();
	PWM_Init();
	
	GPIO_PORTF_DATA_R |= 0x02;
	
	Duty(3200,3200);
	
	while(1){

	}
	
	return 0;
	
}

void GPIOPortF_Handler(){
	GPIO_PORTF_ICR_R = SW1;
	GPIO_PORTF_DATA_R ^= 0x02;

}

	
	

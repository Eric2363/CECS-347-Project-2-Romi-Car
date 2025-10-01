#include "tm4c123gh6pm.h"


#define PORTB 0x02
#define MOTORS 0x30
#define LEFT_DIR 0x0C
#define RIGHT_DIR 0xC0
#define DIR_MASK 0xCC

#define PCTL_PWM_CODE 0x00440000

#define FORWARD 0x0C00


#define FIFTY 8000
#define TWENTY 3200

void PWM_Init();
void Duty(unsigned long duty_L, unsigned long duty_R);
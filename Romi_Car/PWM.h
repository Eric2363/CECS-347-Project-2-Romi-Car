#include "tm4c123gh6pm.h"

//Port B Bits
//==================================
#define PORTB 0x02
#define MOTORS 0x30 //B5,B4 PWM
#define DIR_MASK 0x88//B7,B3
#define DIR_LEFT 0x08
#define DIR_RIGHT 0x80
#define SLP_MASK 0x44// B6,B2
//==================================

//Direction Codes
//==================================
#define FORWARD 0x88
#define OFF 0
//==================================

#define PCTL_PWM_CODE 0x00440000



void PWM_Init();
void Duty(unsigned long duty_L, unsigned long duty_R);
void Start_Pwm(void);
void Stop_Pwm(void);
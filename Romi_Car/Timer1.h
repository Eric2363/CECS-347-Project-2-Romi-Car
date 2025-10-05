#include "tm4c123gh6pm.h"
#include <stdint.h>

#define TIMER1 0x02
#define MODE_16bit 0x00000004
#define PERIODIC_MODE 0x00000002

#define TIMER1A_MASK 0x00000001
#define RELOAD 80000
#define PRESCALE 1

void Timer1_Init(void);
void Timer1A_Init(void);
void Delay(uint16_t ms);

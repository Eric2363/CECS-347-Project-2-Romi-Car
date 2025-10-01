/*
Group:4
Eric Santana
Hector Polanco
Kero Samaan
Mason Doan
ORG: CSULB
Class: CECS 347 Embedded System II
--------------------------
Description: PortF switch 1 configuration
*/

#include "tm4c123gh6pm.h"


#define PORTF 0x20

// Interupt Level
#define LEVEL1 0x00200000

// Port F pins
#define LEDS 0x0E
#define SW1 0x10

void PortF_Init(void);
#include "tm4c123gh6pm.h"

void PortF_Init(void);
#ifndef _ADC_H
#define _ADC_H


#include "stm8s.h"

void bsp_InitAdc(void);
void bsp_AdcPro(void);
uint16_t GetADC();
u16 Get_Temp();

#endif
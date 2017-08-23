#ifndef _TIMER_H
#define _TIMER_H
#include "stm8s.h"
typedef struct
{
  u8 BeeCnt;
  u8 flag;
  u8 typ;
  u16 TimeCnt;
  u16 BeeOnTime;
  u16 BeeOffTime;
}BEESTU;



void TIM4Init();
void TIM2Init();
void BeeON(u16 Frequency );
void BeeOFF();
void TIM1Init();
void Out_PWM(u16 duty);
void IWDGInit();



#endif 

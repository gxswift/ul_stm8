#include "timer.h"


//BEEF   TIM2_CH1//700Hz   500Hz   2400Hz


//PWM2   TIM1_CH1_AFR0 //PWM
//PWM1   TIM2_CH1_AFR0   //HL

//TIM4  interrupt  1ms
BEESTU Bee;

void TIM4Init()
{
//  TIM4_TimeBaseInit(TIM4_PRESCALER_64, 250);
//  TIM4_SetCounter(0x00);
//  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
//  TIM4_Cmd(ENABLE);
  //TIM4->CR1 |= (1 << 0);
  TIM4->ARR = 250;
  TIM4->CNTR = 0;
  TIM4->PSCR = 6;
  TIM4->IER |= 0X01;
  TIM4->CR1 |= 0X01;
}

//beef  TIM2_CH1
void TIM2Init()
{
  TIM2_DeInit();
  TIM2_TimeBaseInit(TIM2_PRESCALER_16, 0x0000);
  TIM2_OC1Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 0x0000, TIM2_OCPOLARITY_HIGH);
  TIM2_OC1PreloadConfig(ENABLE);
  TIM2_Cmd(ENABLE);
}


void BeeON(u16 Frequency )
{
  u16 cnt= 1000000/Frequency ;
  TIM2->ARRH = cnt>>8;
  TIM2->ARRL = cnt;
    cnt/=2;
  TIM2->CCR1H = cnt>>8;
  TIM2->CCR1L = cnt;
}

void BeeOFF()
{
  TIM2->CCR1H = 0;
  TIM2->CCR1L = 0;
}
//BEEP_Init(BEEP_FREQUENCY_2KHZ);


//700Hz  ding    500Hz   dong    2400Hz   di
//1428            2000            416
//ARR   CCR=ARR/2
//    TIM2->ARRH = (uint8_t)(TIM2_Period >> 8);
//    TIM2->ARRL = (uint8_t)(TIM2_Period);
//TIM2_PWMIConfig(TIM2_CHANNEL_1, TIM2_ICPOLARITY_RISING, TIM2_ICSELECTION_DIRECTTI, TIM2_ICPSC_DIV1, 0x00);


//TIM1_CH1   PWM2
void TIM1Init()
{
  TIM1_DeInit();
  TIM1_TimeBaseInit(15, TIM1_COUNTERMODE_UP, 1000, 0x00);
  TIM1_OC1Init(TIM1_OCMODE_PWM1, 
               TIM1_OUTPUTSTATE_ENABLE, 
               TIM1_OUTPUTNSTATE_ENABLE, 
               0x0000, 
               TIM1_OCPOLARITY_HIGH, 
               TIM1_OCNPOLARITY_HIGH, 
               TIM1_OCIDLESTATE_RESET, 
               TIM1_OCNIDLESTATE_SET);

  TIM1_OC1PreloadConfig(ENABLE);
  TIM1_CtrlPWMOutputs(ENABLE);
  TIM1_Cmd(ENABLE);

}


void Out_PWM(u16 duty)
{
  TIM1->CCR1H = duty>>8;
  TIM1->CCR1L = duty;
}

void IWDGInit()
{
  IWDG_Enable();                                //使能看?狗
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //?允?
  IWDG_SetReload(0xff);                         //?定重?值
  IWDG_ReloadCounter();                         //重???值，喂狗
  IWDG_SetPrescaler(IWDG_Prescaler_256);         //?置分?
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Disable);//?禁止
}

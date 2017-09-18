#include "ctrl.h"
/*
PD3 ----->  SIG
PD2 ----->  CHECK
PC6 ----->  T1
PC5 ----->  T2
PA3 ----->  REV         输入中断
PD4 ----->  T_PWR
*/



uint8_t Flag;   //输出标志 1：有输出   0：无输出
uint16_t t;     //主循环粗略计时
extern uint8_t Fall_Cnt;
void main()
{
//   uint16_t t;
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    GPIOInit();
    enableInterrupts();
    PWR_OFF;    
    while(1)
    {
      Delay_ms(1);
      if (Flag)//有输出计时
      {
        t++;
        if (t>30)//设置上限30ms 距离约 15*340 = 5100mm = 5.1m
        {
          t = 0;
          Flag = 0;
          Fall_Cnt = 0;
          SIG_OFF;
          Delay_ms(2);
          GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//A3开启中断
          
          GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//改变输出方向
          EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_ONLY);
        }
      }
      else
      {
       t = 0;    
      }
    }
}


//void InitDevice()
//{
//  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
//  TIM1Init();
//  TIM2Init();
//  TIM4Init();
//  bsp_InitAdc();
//  GPIOInit();
////  IWDGInit();
//  //  delay_init(16);
//}





#ifdef USE_FULL_ASSERT


void assert_failed(u8* file, u32 line)
{ 
  
  while (1)
  {
  }
}
#endif

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

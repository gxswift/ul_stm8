#include "ctrl.h"
/*
PD3 ----->  SIG
PD2 ----->  CHECK
PC6 ----->  T1
PC5 ----->  T2
REV ----->  PA3
PD4 ----->  T_PWR
*/
void Delay_us()
{
    asm("nop"); 
    asm("nop");   
    asm("nop");   
    asm("nop"); 
}

void Delay_ms(unsigned int time)  //ms计时 
{   
   unsigned int i;   
    while(time--)     
    for(i=900;i>0;i--)   
    Delay_us();    
} 


uint8_t Flag;   //输出标志 1：有输出   0：无输出
uint16_t t;     //主循环粗略计时

void main()
{
    uint16_t t;
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    GPIOInit();

    PWR_ON;    
    while(1)
    {
      Delay_ms(1);
      if (Flag)//有输出计时
      {
        t++;
        if (t>300)//设置上限200ms 距离约 150*340 = 5100mm = 5.1m
        {
          t = 0;
          Flag = 0;
          SIG_OFF;
          GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//改变输出方向
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

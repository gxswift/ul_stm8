#include "ctrl.h"
#include "timer.h"
#include "delay.h"
#include "Adc.h"
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
    asm("nop"); //一个asm("nop")函数经过示波器测试代表100ns   
    asm("nop");   
    asm("nop");   
    asm("nop"); 
}
void Delay_125us()
{
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 

}//176   
void Delay_ms(unsigned int time)   
{   
   unsigned int i;   
    while(time--)     
    for(i=900;i>0;i--)   
    Delay_us();    
} 
#define LED_ON          GPIO_WriteHigh(GPIOA, GPIO_PIN_3)
#define LED_OFF         GPIO_WriteLow (GPIOA, GPIO_PIN_3)
void main()
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
    while(1)
    {
      LED_ON;
      Delay_125us();
      LED_OFF;
      Delay_125us();
      
    }
}
void InitDevice()
{
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  TIM1Init();
  TIM2Init();
  TIM4Init();
  Uart1_Init();
  Filter_Init();
  bsp_InitAdc();
  GPIOInit();
//  IWDGInit();
  //  delay_init(16);
}

volatile u8 Run_Cnt;
/*void main(void)
{
  u8 count;
  u32 t;
  //  u16 i;
  InitDevice();
  //   for (i =0;i<1500;i++)
  //  {
  //    BeeON(3500-i);
  //    t=100000/3000;
  //    while (t--);
  //  }
  //   for (i =0;i<1500;i++)
  //  {
  //    BeeON(3500-i);
  //    t=100000/3000;
  //    while (t--);
  //  }
  
  
  BeeON(2430);
  //  delay_ms(500);
  t=100000;
  while (t--);
  //  
  //SetBee(1,100,100,0);
  
  BeeOFF();
  rim();
  while(1)
  {
//    IWDG_ReloadCounter();

    if (Run_Cnt ==20)
    {
      Run_Cnt = 0 ;
      Get_Data();
      Key_Fun();
      bsp_AdcPro();
      count++;
      if(count==5)
      {
        count = 0;
        Ctrl();
      }
    }
  } 
}
*/




#ifdef USE_FULL_ASSERT


void assert_failed(u8* file, u32 line)
{ 
  
  while (1)
  {
  }
}
#endif

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

#include "ctrl.h"

/*
PD3 ----->  SIG         输入中断、输出
PD2 ----->  CHECK       
PC6 ----->  T1          输出
PC5 ----->  T2          输出
PA3 ----->  REV         输入中断
PD4 ----->  T_PWR       输出
*/
//--------------------功能对应IO口------------------------------------
void GPIOInit()
{
  
  GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);//输出控制
  GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_OUT_PP_LOW_FAST);//输出控制
  
//  GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST);//比较检测
  
  GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST);//232输出控制
  
  GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//超声波接收
  
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//触发
  
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOA, EXTI_SENSITIVITY_FALL_ONLY);//超声波接收信号   下降沿中断
  
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_ONLY);//触发信号   上升沿中断
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
  
//  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
//  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
//  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
//  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
//  asm("nop"); asm("nop"); asm("nop"); asm("nop");
  
//  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
//  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
//  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 
//  asm("nop"); asm("nop"); asm("nop"); asm("nop"); 

}//176  个机器周期 ？

//一次 for 循环8个周期 
//16*12.5 = 200 ??
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

void Delay_100us(unsigned int time)  //发出后的延时
{   
   unsigned int i;   
    while(time--)     
  //  for(i=90;i>0;i--)  
      for(i=120;i>0;i--)  
    Delay_us();    
} 

//mode 0,1:互补翻转   2：两端口置低
void Port(uint8_t mode)
{
  if (mode == 2)
  {
    T1_OFF;
    T2_OFF;
  }
  else if (mode)
  {
    T1_ON;
    T2_OFF;
  }
  else
  {
    T1_OFF;
    T2_ON;
  }  
}

void TIM2Init()//ARF_1    //PD2  PWM
{
  TIM2_DeInit();
  TIM2_TimeBaseInit(TIM2_PRESCALER_16, 0x0000);
  TIM2_OC3Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 0x0000, TIM2_OCPOLARITY_HIGH);
  TIM2_OC3PreloadConfig(ENABLE);
  TIM2_Cmd(ENABLE);
}


void PWM_Start(u16 Frequency ,u16 Duty)//频率   占空比设置
{
  u16 cnt= 1000000/Frequency ;
  TIM2->ARRH = cnt>>8;
  TIM2->ARRL = cnt;

  TIM2->CCR3H = Duty>>8;
  TIM2->CCR3L = Duty;
}

//  TIM4_PRESCALER_1  = ((uint8_t)0x00),
//  TIM4_PRESCALER_2    = ((uint8_t)0x01),
//  TIM4_PRESCALER_4    = ((uint8_t)0x02),
//  TIM4_PRESCALER_8     = ((uint8_t)0x03),
//  TIM4_PRESCALER_16   = ((uint8_t)0x04),
//  TIM4_PRESCALER_32     = ((uint8_t)0x05),
//  TIM4_PRESCALER_64    = ((uint8_t)0x06),
//  TIM4_PRESCALER_128   = ((uint8_t)0x07)
void TIM4Init()
{
//  TIM4_TimeBaseInit(TIM4_PRESCALER_64, 250);
//  TIM4_SetCounter(0x00);
//  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
//  TIM4_Cmd(ENABLE);
  //TIM4->CR1 |= (1 << 0);
  TIM4->ARR = 250;
  TIM4->CNTR = 0;
  TIM4->PSCR = 4;//TIM4_PRESCALER_16
  TIM4->IER |= 0X01;
  TIM4->CR1 |= 0X01;
}
/*/us中断
void TIM4Init()
{
//  TIM4_TimeBaseInit(TIM4_PRESCALER_64, 250);
//  TIM4_SetCounter(0x00);
//  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
//  TIM4_Cmd(ENABLE);
  //TIM4->CR1 |= (1 << 0);
  TIM4->ARR = 8;
  TIM4->CNTR = 0;
  TIM4->PSCR = 1;//TIM4_PRESCALER_2
  TIM4->IER |= 0X01;
  TIM4->CR1 |= 0X01;
}
*/
//TIM4->IER = 0;
/*
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
*/
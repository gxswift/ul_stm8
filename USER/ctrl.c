#include "ctrl.h"

/*
PD3 ----->  SIG         �����жϡ����
PD2 ----->  CHECK       
PC6 ----->  T1          ���
PC5 ----->  T2          ���
PA3 ----->  REV         �����ж�
PD4 ----->  T_PWR       ���
*/
//--------------------���ܶ�ӦIO��------------------------------------
void GPIOInit()
{
  
  GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);//�������
  GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_OUT_PP_LOW_FAST);//�������
  
  GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST);//�Ƚϼ��
  
  GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST);//232�������
  
  GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//����������
  
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//����
  
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOA, EXTI_SENSITIVITY_FALL_ONLY);//�����������ź�   �½����ж�
  
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_ONLY);//�����ź�   �������ж�
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

}//176  ���������� ��

//һ�� for ѭ��8������ 
//16*12.5 = 200 ??
void Delay_us()
{
    asm("nop"); 
    asm("nop");   
    asm("nop");   
    asm("nop"); 
}

void Delay_ms(unsigned int time)  //ms��ʱ 
{   
   unsigned int i;   
    while(time--)     
    for(i=900;i>0;i--)   
    Delay_us();    
} 

void Delay_100us(unsigned int time)  //���������ʱ
{   
   unsigned int i;   
    while(time--)     
  //  for(i=90;i>0;i--)  
      for(i=120;i>0;i--)  
    Delay_us();    
} 

//mode 0,1:������ת   2�����˿��õ�
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


void PWM_Start(u16 Frequency ,u16 Duty)//Ƶ��   ռ�ձ�����
{
  u16 cnt= 1000000/Frequency ;
  TIM2->ARRH = cnt>>8;
  TIM2->ARRL = cnt;

  TIM2->CCR3H = Duty>>8;
  TIM2->CCR3L = Duty;
}
#include "ctrl.h"
/*
PD3 ----->  SIG
PD2 ----->  CHECK
PC6 ----->  T1
PC5 ----->  T2
PA3 ----->  REV         �����ж�
PD4 ----->  T_PWR
*/



uint8_t Flag;   //�����־ 1�������   0�������
uint16_t t;     //��ѭ�����Լ�ʱ
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
      if (Flag)//�������ʱ
      {
        t++;
        if (t>30)//��������30ms ����Լ 15*340 = 5100mm = 5.1m
        {
          t = 0;
          Flag = 0;
          Fall_Cnt = 0;
          SIG_OFF;
          Delay_ms(2);
          GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//A3�����ж�
          
          GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//�ı��������
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

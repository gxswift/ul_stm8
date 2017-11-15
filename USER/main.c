#include "ctrl.h"
/*
PD3 ----->  SIG
PD2 ----->  CHECK
PC6 ----->  T1
PC5 ----->  T2
PA3 ----->  REV         �����ж�
PD4 ----->  T_PWR
*/
//------------------------------------------------
/*
PWM�ṩ�ο���ѹ �Խ��ո���̫��
��CHECK���ø�   �����ѹ  �ṩ�ο���ƽ
*/
//------------------------------------------------

//#define COMP_V 580      //      С��1000000/Ƶ��

uint8_t Flag;   //�����־ 1�������   0�������
uint16_t t;     //��ѭ�����Լ�ʱ
extern uint8_t Fall_Cnt;
void main()
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
    GPIOInit();
    enableInterrupts();

    CHECK_ON;
    //----------------------------------------------
//   TIM2Init();    
//    PWM_Start(1060 ,COMP_V);//Ƶ�ʣ�����
//    PWR_OFF;   //����232 
    //----------------------------------------------
    while(1)
    {
      Delay_ms(1);
      if (Flag)//�������ʱ
      {
        t++;
        if (t>24)//��������24ms ����Լ 12*340 = 4080mm = 4m
        {
          t = 0;
          Flag = 0;
          Fall_Cnt = 0;
          SIG_OFF;      //����ź�����
          Delay_ms(1);
          //CHECK_OFF;//�Ƚϼ��ر�
         // GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//A3�����ж�
          GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);//�ı��������
          EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_ONLY);//�����������ж�  ���մ���
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

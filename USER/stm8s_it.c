/**
******************************************************************************
* @file     stm8s_it.c
* @author   MCD Application Team
* @version  V2.1.0
* @date     18-November-2011
* @brief    Main Interrupt Service Routines.
*           This file provides template for all peripherals interrupt service 
*           routine.
******************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
******************************************************************************
*/ 

/* Includes ------------------------------------------------------------------*/
#include "stm8s_it.h"
#include "timer.h"
#include "ctrl.h"

/** @addtogroup Template_Project
* @{
*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

#ifdef _COSMIC_
/**
* @brief Dummy Interrupt routine
* @par Parameters:
* None
* @retval
* None
*/
INTERRUPT_HANDLER(NonHandledInterrupt, 25)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*_COSMIC_*/

/**
* @brief TRAP Interrupt routine
* @param  None
* @retval None
*/
INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief Top Level Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TLI_IRQHandler, 0)

{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief Auto Wake Up Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(AWU_IRQHandler, 1)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief Clock Controller Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(CLK_IRQHandler, 2)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief External Interrupt PORTA Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief External Interrupt PORTB Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI_PORTB_IRQHandler, 4)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief External Interrupt PORTC Interrupt routine.
* @param  None
* @retval None
*/



extern u16 Out_Water_Cnt;

INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 5)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
  if (Out_Water_Cnt)
    Out_Water_Cnt--;
}

/**
* @brief External Interrupt PORTD Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief External Interrupt PORTE Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI_PORTE_IRQHandler, 7)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

#ifdef STM8S903
/**
* @brief External Interrupt PORTF Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EXTI_PORTF_IRQHandler, 8)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S903*/

#if defined (STM8S208) || defined (STM8AF52Ax)
/**
* @brief CAN RX Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(CAN_RX_IRQHandler, 8)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief CAN TX Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(CAN_TX_IRQHandler, 9)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S208 || STM8AF52Ax */

/**
* @brief SPI Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(SPI_IRQHandler, 10)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief Timer1 Update/Overflow/Trigger/Break Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_BRK_IRQHandler, 11)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief Timer1 Capture/Compare Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM1_CAP_COM_IRQHandler, 12)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

#ifdef STM8S903
/**
* @brief Timer5 Update/Overflow/Break/Trigger Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM5_UPD_OVF_BRK_TRG_IRQHandler, 13)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief Timer5 Capture/Compare Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM5_CAP_COM_IRQHandler, 14)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

#else /*STM8S208, STM8S207, STM8S105 or STM8S103 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */
/**
* @brief Timer2 Update/Overflow/Break Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM2_UPD_OVF_BRK_IRQHandler, 13)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief Timer2 Capture/Compare Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM2_CAP_COM_IRQHandler, 14)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S903*/

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8S105) || \
defined(STM8S005) ||  defined (STM8AF62Ax) || defined (STM8AF52Ax) || defined (STM8AF626x)
/**
* @brief Timer3 Update/Overflow/Break Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM3_UPD_OVF_BRK_IRQHandler, 15)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief Timer3 Capture/Compare Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM3_CAP_COM_IRQHandler, 16)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S208, STM8S207 or STM8S105 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8S103) || \
defined(STM8S003) ||  defined (STM8AF62Ax) || defined (STM8AF52Ax) || defined (STM8S903)
/**
* @brief UART1 TX Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(UART1_TX_IRQHandler, 17)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief UART1 RX Interrupt routine.
* @param  None
* @retval None
*/

u8 UART_BUF[16];
u8 UART_COUNT;
u16 Rec_Time;
u8 Rece_Flag;
static u8 data1;
uint8_t state = 0;
INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)//改为计时？？/标志
{
  //u8 data;
  //if(UART1_GetITStatus(UART1_IT_RXNE) != RESET)
  //  {
  //    UART1_ClearITPendingBit(UART1_IT_RXNE);
  
  if(UART1_GetFlagStatus(UART1_FLAG_RXNE) != RESET)
  {
    if(UART1->SR & UART1_SR_OR)
    {  UART1->SR &=(~UART1_SR_OR);
    //state = UART1->SR;
    
    }
    data1=UART1_ReceiveData8();
    if (UART_COUNT<12)
    {
      UART_BUF[UART_COUNT]=data1;//把数据存到数组
      UART_COUNT++;
      Rec_Time=0;
      Rece_Flag = 1;
    }
    else
    {
      UART_COUNT = 0;
    }
  }
  
}

#endif /*STM8S208 or STM8S207 or STM8S103 or STM8S903 or STM8AF62Ax or STM8AF52Ax */

/**
* @brief I2C Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(I2C_IRQHandler, 19)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

#if defined(STM8S105) || defined(STM8S005) ||  defined (STM8AF626x)
/**
* @brief UART2 TX interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(UART2_TX_IRQHandler, 20)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief UART2 RX interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(UART2_RX_IRQHandler, 21)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /* STM8S105 or STM8AF626x */

#if defined(STM8S207) || defined(STM8S007) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
* @brief UART3 TX interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(UART3_TX_IRQHandler, 20)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @brief UART3 RX interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(UART3_RX_IRQHandler, 21)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S208 or STM8S207 or STM8AF52Ax or STM8AF62Ax */

#if defined(STM8S207) || defined(STM8S007) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
* @brief ADC2 interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(ADC2_IRQHandler, 22)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#else /*STM8S105, STM8S103 or STM8S903 or STM8AF626x */
/**
* @brief ADC1 interrupt routine.
* @par Parameters:
* None
* @retval 
* None
*/
INTERRUPT_HANDLER(ADC1_IRQHandler, 22)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*STM8S208 or STM8S207 or STM8AF52Ax or STM8AF62Ax */

#ifdef STM8S903
/**
* @brief Timer6 Update/Overflow/Trigger Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(TIM6_UPD_OVF_TRG_IRQHandler, 23)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}
#else /*STM8S208, STM8S207, STM8S105 or STM8S103 or STM8AF52Ax or STM8AF62Ax or STM8AF626x */
/**
* @brief Timer4 Update/Overflow Interrupt routine.
* @param  None
* @retval None
*/

//extern uint16_t delayTime;
//extern uint16_t doubleclickTime;

extern volatile u8 Run_Cnt;
extern BEESTU Bee;
extern u8 Duty;
u8 PWM_Cnt;
INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
  
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  //   TIM4_ClearITPendingBit(TIM2_IT_UPDATE);
  //   UpdateTask();
  //updisplay((u8 *)&sendDisp.dat[1]);
  
  if (Run_Cnt<20)
    Run_Cnt ++;
  if (Rec_Time< 5000)
    Rec_Time++;
  
//---------------------------
    PWM_Cnt++;
  if (PWM_Cnt==100)
    PWM_Cnt = 0;  
  if ( PWM_Cnt < Duty)
    PWM2_ON;
  else PWM2_OFF;
//---------------------------  
  
  

  if(Bee.BeeCnt)
  {
    if(Bee.flag==0)
    {
      BeeON(2400);
      if(Bee.TimeCnt++>=Bee.BeeOnTime)
      {
        Bee.flag=1;
        Bee.TimeCnt=0;
        BeeOFF();
      }
    }
    else if(Bee.flag==1)
    {
      BeeOFF();
      if(Bee.TimeCnt++>=Bee.BeeOffTime)
      {
        Bee.flag=0;
        Bee.BeeCnt--;    
        Bee.TimeCnt=0;
      }
    }   
  } 
}
#endif /*STM8S903*/

/**
* @brief Eeprom EEC Interrupt routine.
* @param  None
* @retval None
*/
INTERRUPT_HANDLER(EEPROM_EEC_IRQHandler, 24)
{
  /* In order to detect unexpected events during development,
  it is recommended to set a breakpoint on the following instruction.
  */
}

/**
* @}
*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
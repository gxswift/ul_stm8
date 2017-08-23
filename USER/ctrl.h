#ifndef _CTRL_H
#define _CTRL_H
#include "stm8s.h"
#include "filter.h"
#include "key.h"
#include "uart.h"



//---------------按键定义----------------

#define KEY_SET         PRESS_KEY1
#define KEY_FLUSH       PRESS_KEY2
#define KEY_MODE        PRESS_KEY3
#define KEY_TEMP        PRESS_KEY4
#define KEY_VEG         PRESS_KEY5
#define KEY_OUT         PRESS_KEY6
#define KEY_HEAT        PRESS_KEY7
#define KEY_QUANT       PRESS_KEY8
#define KEY_POWER       PRESS_KEY9


//---------------LED亮灭闪---------------
#define OFF             0
#define ON              1
#define Flash          2

//---------------保存数据-----------------
//温度
//定量
//耗材1
//耗材2
//耗材3
//耗材4
//

//----------------------------------------
#define FLUSH_SET       3600

typedef enum _FlushTypeDef
{
  FNone,
  FFull,
  FNoWater,
  FStart,
  FForce,
  FRun,
  FNoFull,  
}FlushTypeDef;

typedef enum _StauseTypeDef
{
  SNone,
  SMakeWater,
  SNoWater,
  SFull,
  SRepair,
  SFlush,
}StauseTypeDef;

//-------------------IO口定义--------------------------------------
//#define BEEF    PD4     //   tim2ch1
//#define TXD     PD5     //UART1
//#define RXD     PD6
//#define VALUE2  PA1     //高电平有效
//#define VALUE1  PA2
//#deifne LED_C   PA3     
//#define NTC     PD3     //ADC_ETR
//#define CURRENT PD2     //输入
//#define SWIM    PD1
//#define PUMP    PC7     
//#define PWM2    PC6
//#define PWM1    PC5     //？
//#define HEAT    PC4     
//#define FLOW    PC3     //计数
//#define PLACE   PB4     //输入
//#define LEVEL   PB5
//GPIO_WriteHigh(GPIOA, GPIO_PIN_1);
//GPIO_WriteLow(GPIOA, GPIO_PIN_0);

//--------------------功能对应IO口------------------------------------
#define Out_Water_ON    GPIO_WriteHigh(GPIOA, GPIO_PIN_1)
#define Out_Water_OFF   GPIO_WriteLow (GPIOA, GPIO_PIN_1)

#define Out_V_Water_ON  GPIO_WriteHigh(GPIOA, GPIO_PIN_2)
#define Out_V_Water_OFF GPIO_WriteLow (GPIOA, GPIO_PIN_2)

#define LED_ON          GPIO_WriteHigh(GPIOA, GPIO_PIN_3)
#define LED_OFF         GPIO_WriteLow (GPIOA, GPIO_PIN_3)

#define PUMP_ON         GPIO_WriteHigh(GPIOC, GPIO_PIN_7)
#define PUMP_OFF        GPIO_WriteLow (GPIOC, GPIO_PIN_7)

#define PWM1_ON         GPIO_WriteHigh(GPIOC, GPIO_PIN_5)
#define PWM1_OFF        GPIO_WriteLow (GPIOC, GPIO_PIN_5)

#define HEAT_ON         GPIO_WriteHigh(GPIOC, GPIO_PIN_4)
#define HEAT_OFF        GPIO_WriteLow (GPIOC, GPIO_PIN_4)

#define PWM2_ON         GPIO_WriteHigh(GPIOC, GPIO_PIN_6)
#define PWM2_OFF        GPIO_WriteLow (GPIOC, GPIO_PIN_6)

//------------------------------------------------------------------
void Key_Fun();
void GPIOInit();
void Ctrl(void);
void SetBee(u8 cnt,u16 OnTime,u16 OffTime,u8 typ);
void Send_Data_Buf();

#endif  




//_CTRL_H
//volatile _Bool PA0 @PA_ODR:0;
//volatile _Bool PA1 @PA_ODR:1;
//volatile _Bool PA2 @PA_ODR:2;
//volatile _Bool PA3 @PA_ODR:3;
//volatile _Bool PA4 @PA_ODR:4;
//volatile _Bool PA5 @PA_ODR:5;
//volatile _Bool PA6 @PA_ODR:6;
//volatile _Bool PA7 @PA_ODR:7;
//
//volatile _Bool PB0 @PB_ODR:0;
//volatile _Bool PB1 @PB_ODR:1; 
//volatile _Bool PB2 @PB_ODR:2;
//volatile _Bool PB3 @PB_ODR:3;
//volatile _Bool PB4 @PB_ODR:4;
//volatile _Bool PB5 @PB_ODR:5;
//volatile _Bool PB6 @PB_ODR:6;
//volatile _Bool PB7 @PB_ODR:7;
//
//volatile _Bool PC0 @PC_ODR:0;
//volatile _Bool PC1 @PC_ODR:1;
//volatile _Bool PC2 @PC_ODR:2;
//volatile _Bool PC3 @PC_ODR:3;
//volatile _Bool PC4 @PC_ODR:4;
//volatile _Bool PC5 @PC_ODR:5;
//volatile _Bool PC6 @PC_ODR:6;
//volatile _Bool PC7 @PC_ODR:7;
//
//volatile _Bool PD0 @PD_ODR:0;
//volatile _Bool PD1 @PD_ODR:1; 
//volatile _Bool PD2 @PD_ODR:2;
//volatile _Bool PD3 @PD_ODR:3;
//volatile _Bool PD4 @PD_ODR:4;
//volatile _Bool PD5 @PD_ODR:5;
//volatile _Bool PD6 @PD_ODR:6;
//volatile _Bool PD7 @PD_ODR:7;

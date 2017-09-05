#ifndef _CTRL_H
#define _CTRL_H
#include "stm8s.h"

/*
PD3 ----->  SIG         输入中断、输出
PD2 ----->  CHECK       
PC6 ----->  T1          输出
PC5 ----->  T2          输出
PA3 ----->  REV         输入中断
PD4 ----->  T_PWR       输出
*/

//--------------------功能对应IO口------------------------------------
#define PWR_ON          GPIO_WriteHigh(GPIOD, GPIO_PIN_4)
#define PWR_OFF         GPIO_WriteLow (GPIOD, GPIO_PIN_4)

#define T1_ON           GPIO_WriteHigh(GPIOC, GPIO_PIN_5)
#define T1_OFF          GPIO_WriteLow (GPIOC, GPIO_PIN_5)

#define T2_ON          GPIO_WriteHigh(GPIOC, GPIO_PIN_6)
#define T2_OFF         GPIO_WriteLow (GPIOC, GPIO_PIN_6)

#define SIG_ON         GPIO_WriteHigh(GPIOD, GPIO_PIN_3)
#define SIG_OFF        GPIO_WriteLow (GPIOD, GPIO_PIN_3)

//------------------------------------------------------------------
void GPIOInit();
void Delay_125us();
void Port(uint8_t mode);

void Delay_us();
void Delay_ms(unsigned int time);  //ms计时 
void Delay_100us(unsigned int time);  //0.1ms计时 
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

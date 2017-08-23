#ifndef FILTER_H_
#define FILTER_H_
#include "stm8s.h"



#define A_MaxTime 6*30*24
#define B_MaxTime 6*30*24
#define C_MaxTime 6*30*24
#define D_MaxTime 18*30*24

#define A_Addr          0x4000
#define B_Addr          0x4002
#define C_Addr          0x4004
#define D_Addr          0x4006
#define Temp_Addr       0x4008
#define Cap_Addr        0x400A




u16 Read_Data(u16 address);
void Write_Data(u16 Address,u16 Data);
void Filter_Init();



#endif
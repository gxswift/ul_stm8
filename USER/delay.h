#ifndef _DELAY_H_
#define _DELAY_H_
#include "stm8s.h"

void delay_init(u8 clk); //��ʱ������ʼ��
void delay_us(u16 nus);  //us����ʱ����,���65536us.
void delay_ms(u32 nms);  //ms����ʱ����

#endif

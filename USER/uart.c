#include "uart.h"


extern u8 Rece_Flag;

void Uart1_Init()
{
  UART1_DeInit();
  UART1_Init((u32)19200, 
             UART1_WORDLENGTH_8D, 
             UART1_STOPBITS_1, 
             UART1_PARITY_NO, 
             UART1_SYNCMODE_CLOCK_DISABLE, 
             UART1_MODE_TXRX_ENABLE);
  UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
//  UART1_ITConfig(UART1_IT_RXNE, ENABLE);
  UART1_Cmd(ENABLE );
}

void Send_Data(u8 data)
{
  while ( (UART1->SR&0x80)==0x00);
  UART1_SendData8(data);
   while ( (UART1->SR&0x40)==0x00);//发送寄存器数据是否转移完,RESET or SET
  
}

extern  u8 UART_BUF[]; 
extern  u8 UART_COUNT;
extern  u8 ReceErr_Flag;
extern  u8 Rece_Flag;
extern  u16 Rec_Time;
u8 Receive_Data[2];

void Get_Data()
{
  if (UART_BUF[0] == 0xFF &&UART_BUF[3] == 0xFE && (UART_BUF[2]&0xFE)==0 )
  {
  if ((Rec_Time >5 && Rec_Time<100 )&&Rece_Flag)
  {
    Receive_Data[0] = UART_BUF[1];
    Receive_Data[1] = UART_BUF[2];
    UART_COUNT=0;
    Rece_Flag = 0;
  }
  else if (Rec_Time >3000)
  {
    ReceErr_Flag=1;
  }
  }
}




/*
@far @interrupt void UART1_RX_IRQHandler(void)
{
if(UART1->SR&UART1_FLAG_RXNE)
{
rxbuf[rx_num++]=UART1_ReceiveData8();
UART1_SendData8(UART1_ReceiveData8());
      }
 }

*/



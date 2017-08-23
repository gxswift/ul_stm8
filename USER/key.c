#include "key.h"
#include "ctrl.h"
#include "filter.h"

extern u8 Receive_Data[];
u16 ReadKeyValue(void)
{
  static uint8_t Key_State;
  static uint8_t key_time;
  static uint16_t Key_LongCheck;
  static uint16_t Key_Prev    = 0;     
  
  u16 Key_press;
  u16 Key_return = 0;
  
  Key_press = Receive_Data[0] | Receive_Data[1]<<8 ;
  switch (Key_State)
  {
  case 0:
    if(Key_press != 0)
    {
      Key_Prev = Key_press;
      Key_State = 1;
    }
    
    break;
  case 1:
    if(Key_press == Key_Prev)
    {
      Key_return= Key_Prev | KEY_DOWN;
      if ((Key_press &0x01)== 1)
      {
        Key_State = 2;
      }
      else 
      {
        if (Key_press == PRESS_KEY4 ||Key_press == PRESS_KEY8)//
          Key_State = 4;//
        else //
        Key_State = 3;
      }
      return Key_return ;
    }
    else 																					//¡ã¡ä?¨¹¨¬¡ì?e,¨º????¡¥,2??¨¬¨®|¡ã¡ä?¨¹
    {
      Key_State = 0;
    }
    break;
  case 2:
    
    if(Key_press != Key_Prev)
    {
      Key_State = 0;
      Key_LongCheck = 0;
      Key_return = Key_Prev | KEY_UP;
      return Key_return;
    }
    
    if(Key_press == Key_Prev)
    {
      Key_LongCheck++;
      if(Key_LongCheck >= 100)                 
      {
        Key_LongCheck = 0;
        Key_State = 3;
        Key_return= Key_press |  KEY_LONG;
        return Key_return;
      }
    }
    break;
    
  case 3:
    if(Key_press != Key_Prev)
    {
      Key_State = 0;
    }
    break;
    
    
  case 4:
    if (Key_press == Key_Prev) 
    {
      Key_LongCheck++;
      if (Key_LongCheck >= 50) 
      {
        if (++key_time >= 10)
        {
          key_time = 0;                       
          Key_return = Key_press | KEY_LIAN;
          return Key_return;
        }
      }
    }
    else
    {
      Key_LongCheck = 0;
      Key_State = 3; 
    }
    break;
    
  }
  return  NO_KEY;
}








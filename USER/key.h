#ifndef _KEY_H
#define _KEY_H
#include "stm8s.h"

#define PRESS_KEY1      0x01
#define PRESS_KEY2      0x02
#define PRESS_KEY3      0x04
#define PRESS_KEY4      0x08
#define PRESS_KEY5      0x10
#define PRESS_KEY6      0x20
#define PRESS_KEY7      0x40
#define PRESS_KEY8      0x80
#define PRESS_KEY9      1<<8




#define NO_KEY          0x0000
#define KEY_DOWN        0x1000  	
#define KEY_UP          0x2000  
#define KEY_LIAN        0x4000   
#define KEY_LONG        0x8000



u16 ReadKeyValue(void);


#endif  //_KEY_H
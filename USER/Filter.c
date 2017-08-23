#include "filter.h"


u16 A_Time ,B_Time ,C_Time ,D_Time ;

extern u8 Temp_Set;
extern u16 Out_Water_Set;

u16 Read_Data(u16 address)
{
  u16 res_value;
  res_value = *((NEAR uint8_t*)address) | *((NEAR uint8_t*)address+1) ;
  return res_value ;
}



void Write_Data(u16 Address,u16 Data)
{
  FLASH_Unlock(FLASH_MEMTYPE_DATA);
  FLASH_ProgramByte(Address,Data);
  FLASH_ProgramByte(Address+1,Data>>8);
  FLASH_Lock(FLASH_MEMTYPE_DATA);
}
//FLASH_ProgramBlock();
void Filter_Init()
{
  A_Time = Read_Data(A_Addr);
  B_Time = Read_Data(B_Addr);
  C_Time = Read_Data(C_Addr);
  D_Time = Read_Data(D_Addr);
  Temp_Set      = Read_Data(Temp_Addr);
  if (Temp_Set<40 ||Temp_Set>95)
  Temp_Set = 40;
  Out_Water_Set = Read_Data(Cap_Addr );
  if (Out_Water_Set<200 || Out_Water_Set > 1000)
    Out_Water_Set= 200;
}



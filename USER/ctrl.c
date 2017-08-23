#include "ctrl.h"
#include "Adc.h"
#include "Filter.h"
#include "timer.h"
//-------------------IO口定义--------------------------------------
//#define BEEF    PD4     //   tim2ch1
//#define TXD     PD5     //UART1
//#define RXD     PD6           //UART1
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
void GPIOInit()
{
  
  GPIO_Init(GPIOA, GPIO_PIN_1, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOA, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
  
  GPIO_Init(GPIOB, GPIO_PIN_4, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_IN_FL_NO_IT);
  
  GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_IN_FL_IT);
  
  GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST); 
  GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_OUT_PP_LOW_FAST);//PWM2
  GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_OUT_PP_LOW_FAST);
  
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_ONLY);
  
}


u8 Duty;
void Analog_PWM(u8 m)
{
  Duty = m;
}





extern BEESTU Bee;
void SetBee(u8 cnt,u16 OnTime,u16 OffTime,u8 typ)
{
  Bee.BeeCnt          =       cnt;
  Bee.BeeOnTime       =       OnTime/2;
  Bee.BeeOffTime      =       OffTime/2;
  Bee.flag            =       0;
  Bee.TimeCnt         =       0;
  Bee.typ             =       typ;
}


u8 Filter_Sel;
u16 Filter_Time;
u8 temperature;
extern u16 A_Time ,B_Time ,C_Time ,D_Time ;
//-------------------------
u16 Flush_Time ;
u16 Out_Water_Cnt;
u16 Out_Water_Set;
u16 Capacity;
u16 Out_Cnt;

u16 Run_Time,Mode_Time;
u8  Temp_Set;
u8  H2_Mode = 0;
u16 Dis_Number;

u8 Veg_Flag,Standby_Flag,Warm_Flag,Heat_Flag,Power_Flag,Filter_Flag,Out_Flag;
u8 ReceErr_Flag,Nocup_Flag,Old_Heat_Flag;
//---------------------------------------
//显示数据，暂不用结构体
u8 A_Led=1,B_Led=1,C_Led=1,D_Led=1,

Fil_Led=1, Flu_Led=1,Veg_Led=1,Out_Led=1,

Heat_Led=1,Pow_Led=1,Temp_Led=1,Mode_Led=1,Qu_Led=1,Bao_Led=1,Li_Led=1;

u8 data[3];
//-------------------------

u8 Display_Mode = 2;
u8 Led1,Led2,Led3;
//GPIO_WriteHigh(GPIOA, GPIO_PIN_0);
void Led_Init()
{
  A_Led=1;B_Led=1;C_Led=1;D_Led=1;
  
  Fil_Led=1; Flu_Led=1;Veg_Led=1;Out_Led=1;
  
  Heat_Led=1;Pow_Led=1;Temp_Led=1;Mode_Led=1;Qu_Led=1;Bao_Led=1;Li_Led=1;
}


void Key_Fun()
{
  u16 key;
  key=ReadKeyValue();
  if (key != 0)
    Mode_Time = 0;
  switch (key)
  {    
  case KEY_SET| KEY_UP:
    if (Filter_Flag)
    {
      Filter_Sel++;
      if (Filter_Sel > 3)
        Filter_Sel = 0;
      SetBee(1,100,100,0);
    }
    break;
    
  case KEY_SET| KEY_LONG:
    Filter_Flag=!Filter_Flag;
    SetBee(1,300,100,0);
    break;
    
  case KEY_FLUSH| KEY_DOWN:
    if (Filter_Flag)
    {
      Write_Data(A_Addr + 2*Filter_Sel,0);
      //复位滤芯
      A_Time = Read_Data(A_Addr);
      B_Time = Read_Data(B_Addr);
      C_Time = Read_Data(C_Addr);
      D_Time = Read_Data(D_Addr);
      SetBee(1,100,100,0);
      break;
    }
    if((Out_Water_Cnt==0)&&(!Veg_Flag))
    {
      if (Flush_Time )
        Flush_Time = 0;
      else 
        Flush_Time = FLUSH_SET;
      SetBee(1,100,100,0);
      break;
    }
    break;
    
  case KEY_MODE| KEY_DOWN:
    H2_Mode = !H2_Mode; 
    SetBee(1,100,100,0);
    break;
    
  case KEY_TEMP| KEY_LIAN:
  case KEY_TEMP| KEY_DOWN:
    Temp_Set+=5;
    if (Temp_Set == 100)
      Temp_Set=40; 
    SetBee(1,100,100,0);
    Display_Mode = 2;
    break;
    
  case KEY_VEG| KEY_DOWN://果蔬
    if (!Out_Water_Cnt&& (!Standby_Flag))
    Veg_Flag =!Veg_Flag; 
    SetBee(1,100,100,0);
    break;
    
  case KEY_OUT| KEY_DOWN://出水
    

    if(Out_Water_Cnt)
      Out_Water_Cnt = 0;
    else
    {
      if (!Veg_Flag && (!Standby_Flag))
      {
      Out_Water_Cnt = Out_Water_Set;
      if (Out_Water_Set!=Read_Data (Cap_Addr));
      Write_Data(Cap_Addr,Out_Water_Set);
      //        Read(Set)出水定量保存
      }
    }
    SetBee(1,100,100,0);
    break;
    
  case KEY_HEAT| KEY_DOWN://加热
    if(Heat_Flag)
      Heat_Flag=0;
    else 
    {
      Warm_Flag = 0;
      Heat_Flag=2;
      if (Temp_Set!= Read_Data (Temp_Addr));
      Write_Data (Temp_Addr,Temp_Set);
      //        Read(Set)温度设置保存
    }
    Display_Mode = 2;
    SetBee(1,100,100,0);
    break;
    
  case KEY_QUANT| KEY_LIAN:
  case KEY_QUANT| KEY_DOWN:
    Out_Water_Set +=50;
    if (Out_Water_Set>950)
      Out_Water_Set = 200;
    SetBee(1,100,100,0);
    Display_Mode = 3;
    break;
    
  case KEY_POWER| KEY_DOWN:
    Power_Flag=!Power_Flag;
    SetBee(1,100,100,0);
    break;
    
  default : break;
  }
}


//===================================================================
void Ctrl(void)
{
  static u8 m;
  Led_Init();
  
  if ((Flush_Time == 0)&&(!Veg_Flag )&& (Out_Cnt==0 ))//不冲洗，不出水
  {
    if (Mode_Time<4000)
      Mode_Time ++;
  }
  else Mode_Time = 0;
  //无动作时间
  if (Mode_Time >10*60*5)
  {
    Standby_Flag=1;
  }
  else if (Mode_Time >300)
  {
    Display_Mode = 2;
  }

  else Standby_Flag=0;
  //--------------------------------------------------------------没水壶
  if (GetADC()>1000)
  {
    if (m<10)m++;
  }
   else m = 0;
  
  if (m == 10)
    Nocup_Flag = 1;
  else 
    Nocup_Flag = 0;
  //-------------------------------------------------------------
  if (Nocup_Flag )
  {
    Heat_Flag = 0;
  Out_Water_Cnt = 0;
  }
    
  //---------------------到达温度后保温一次-----------------------
  temperature=Get_Temp();
  if(( (Warm_Flag == 0)&&(temperature>=Temp_Set)) ||(Warm_Flag ==1&& temperature >=(Temp_Set-10)))
    Warm_Flag =1;
  else Warm_Flag = 0;
  
  //-----------------------------------------------
  /*if (Heat_Flag==1 && temperature <40)
    Heat_Flag = 0;*/

  //-------------------------------------------------
  if (Heat_Flag)
  {
    if ((!Out_Water_Cnt))
    {
      if(!Warm_Flag)
      {
        HEAT_ON;
        Heat_Led=2;
        Old_Heat_Flag = 1;
      }
      else//保温
      {
        if (Old_Heat_Flag)//加热状态转保温
        {
          Old_Heat_Flag = 0;
          Heat_Flag--; 
          SetBee(3,100,400,0);
        }               
        Heat_Led=1;
        HEAT_OFF ;
      }
    }
    else
    {
      Heat_Led = 2;
      HEAT_OFF ;
    }
  }
  //  else if (Heat_Flag&&(!Warm_Flag))
  //  {
  //    HEAT_ON;
  //    Heat_Led=1;
  //  }
  else 
  {
    HEAT_OFF ;
    Heat_Led=1;
  }
  //-----------------------------------------------
  if(Out_Water_Cnt)//定量出水
  {
    if (Flush_Time)
      Flush_Time = 0;
    Display_Mode = 4;
    Out_Led=2;
    Out_Water_ON;
  }
  else
  {
    Out_Led=1;
    Out_Water_OFF;
  }
  //-----------------------------------------------
  if(Veg_Flag)//果蔬出水
  {
    if (Flush_Time)
      Flush_Time = 0;
    H2_Mode=0;
    Veg_Led=2;
    Out_V_Water_ON;
  }
  else
  {
    Veg_Led=1;
    Out_V_Water_OFF;
  }
  //-----------------------------------------------
  if (Veg_Flag)//电极控制
  {
    Filter_Time++;
    PWM1_ON;
    //    Out_PWM(500);
    Analog_PWM(50);
    LED_ON;
  }
  else if (Out_Water_Cnt)
  {
    Filter_Time++;
    Display_Mode = 4;
    LED_ON;
    if (H2_Mode) 
    {
      PWM1_ON;
      //      Out_PWM(800);
      Analog_PWM(100);
    }
    
    else   
    {
      PWM1_ON;
      //      Out_PWM(500);
      Analog_PWM(80);
    }
  }
  else  if (Flush_Time)
  {//极性反转
    PWM1_OFF;
    Flu_Led = 2;
    Flush_Time--;
    //    Out_PWM(500);
    Analog_PWM(50);
    Display_Mode = 1;
    LED_ON;
  }
  else
  {
    PWM1_ON;
    //    Out_PWM(0);
    Analog_PWM(0);
    LED_OFF;
  }
  //模式显示
  //------------------------------------------------
  if (H2_Mode )
  {
    Bao_Led=0;
    Li_Led = 1;
  }
  else 
  {
    Bao_Led=1;
    Li_Led = 0;
  }
  //------------------------------------------------
  //耗材时间更新
  if (Filter_Time> 36000)
  {
    Filter_Time=0;
    A_Time++;
    B_Time++;
    C_Time++;
    D_Time++;
    Write_Data(A_Addr,A_Time);
    Write_Data(B_Addr,B_Time);
    Write_Data(C_Addr,C_Time);
    Write_Data(D_Addr,D_Time); 
  }
  //-----------------数码管显示---------------------
  switch (Display_Mode)
  {
  case 1:
    Dis_Number=Flush_Time;
    Led1= Flush_Time/1000;
    Led2=Flush_Time/100%10;
    Led3=Flush_Time/10%10;
    break;
  case 2:
    Dis_Number=Temp_Set;
    Led1 = Temp_Set/100;
    Led2 = Temp_Set/10%10;
    Led3 = Temp_Set%10;
    break;
  case 3:
    Dis_Number= Out_Water_Set;
    Led1 = Out_Water_Set/100;
    Led2 = Out_Water_Set/10%10;
    Led3 = Out_Water_Set%10;
    break;
  case 4:
    Dis_Number= Out_Water_Cnt;
    Led1 = Out_Water_Cnt/100;
    Led2 = Out_Water_Cnt/10%10;
    Led3 = Out_Water_Cnt%10;    
    break;
    
  default:break;
  }
  //------------------------------------------------------------
  //耗材显示 
  A_Led = A_MaxTime>A_Time ?1:2;
  B_Led = B_MaxTime>B_Time ?1:2;
  C_Led = C_MaxTime>C_Time ?1:2;
  D_Led = D_MaxTime>D_Time ?1:2;
  
  if (Filter_Flag)
  {
    switch (Filter_Sel)
    {
    case 0:A_Led=2;B_Led = 0;C_Led = 0;D_Led = 0;break;
    case 1:A_Led=0;B_Led = 2;C_Led = 0;D_Led = 0;break;
    case 2:A_Led=0;B_Led = 0;C_Led = 2;D_Led = 0;break;
    case 3:A_Led=0;B_Led = 0;C_Led = 0;D_Led = 2;break;  
    } 
  }
  
  //  Out_Led =2;
  //  Li_Led =1;//测试旋转
  //------------------------------------------------------------
  data[0]=A_Led<<6|B_Led<<4|C_Led<<2|D_Led;
  data[1]=Fil_Led<<6| Flu_Led<<4|Veg_Led<<2|Out_Led;
  data[2]=Heat_Led<<6|Pow_Led<<5|Temp_Led<<4|Mode_Led<<3|Qu_Led<<2|Bao_Led<<1|Li_Led<<0;  
  //------------------------------------------------------------  
  
  //------------------------------------------------------------ 
  
  if (Power_Flag)
  {
    Out_Water_OFF;
    Out_V_Water_OFF;
    LED_OFF;
    PUMP_OFF;
    PWM1_OFF;
    HEAT_OFF;
    
    Flush_Time=0;
    Out_Water_Cnt=0;
    Veg_Flag=0;
    Heat_Flag=0;
    Filter_Flag=0;
    
    Led1 = 0;
    Led2 = 0xF;
    Led3 = 0xF;
    data[0]=0;
    data[1]=0;
    data[2]=0;
  }
  else if (ReceErr_Flag)
  {
    //关闭功能和显示
    Out_Water_OFF;
    Out_V_Water_OFF;
    LED_OFF;
    PUMP_OFF;
    PWM1_OFF;
    HEAT_OFF;
    
    Flush_Time=0;
    Out_Water_Cnt=0;
    Veg_Flag=0;
    Heat_Flag=0;
    Filter_Flag=0;
    
    Led1 = 0xe;
    Led2 = 0;
    Led3 = 2;
    data[0]=0;
    data[1]=0;
    data[2]=0;
  }
  //待机状态
  else if(Standby_Flag)
  {
    //关闭功能和显示
    Out_Water_OFF;
    Out_V_Water_OFF;
    LED_OFF;
    PUMP_OFF;
    PWM1_OFF;
    HEAT_OFF;
    
    Flush_Time=0;
    Out_Water_Cnt=0;
    Veg_Flag=0;
    Heat_Flag=0;
    Filter_Flag=0;
    
    data[0]=0;
    data[1]=0;
    data[2]=0;
  }
  
  data[2]|=1<<5;
  
  Send_Data_Buf();
  
}




void Send_Data_Buf()
{
  Send_Data(0xFE);//后加帧头
  Send_Data(Led1);
  Send_Data(Led2);
  Send_Data(Led3);
  Send_Data(data[0]);
  Send_Data(data[1]);
  Send_Data(data[2]);
  Send_Data(0xFF);//后加帧尾
}

/*
u8 A_Led,B_Led,C_Led,D_Led,

Fil_Led, Flu_Led,Veg_Led,Out_Led,

Heat_Led,   Pow_Led,Temp_Led,Mode_Led,Qu_Led,Bao_Led,Li_Led;

u8 data[3];

data[0]=A_Led<<6+B_Led<<4+C_Led<<2+D_Led;
data[1]=Fil_Led<<6+ Flu_Led<<4+Veg_Led<<2+Out_Led;
data[2]=Heat_Led<<6+Pow_Led<<5+Temp_Led<<4+Mode_Led<<3+Qu_Led<<2+Bao_Led<<1+Li_Led;

*/

//-------------------------------------------数据格式-------------------------------------------
//
//      Led1    Led2    Led3    ABCD    滤芯冲洗果蔬出水        加热 电源温度功能定量保健理疗
//
//bit   8       8       8       2222    2    2   2   2          2     1   1   1   1   1   1 
//
//      0:灭      1:亮      2:闪
//---------------------------------------------------------------------------------------------


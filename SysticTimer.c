#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "types.h"
#include "bitwise_operation.h"
#include<stdio.h>
void SysTickDisable (){
    CLEAR_BIT(NVIC_ST_CTRL_R,0);
    CLEAR_BIT(NVIC_ST_CTRL_R,1);
    CLEAR_BIT(NVIC_ST_CTRL_R,2);
    CLEAR_BIT(NVIC_ST_CTRL_R,16);
}
void SysTickEnable(){
      SET_BIT(NVIC_ST_CTRL_R,0);
      SET_BIT(NVIC_ST_CTRL_R,2);
}

void SysTickPeriodSet (uint32 ui32Period) {
  uint32 Duration_Tick=(1/16000000);
  uint32 NumberOfTicks=((ui32Period)/Duration_Tick)-1;
  NVIC_ST_RELOAD_R=NumberOfTicks;
}
uint32 SysTickPeriodGet(){
   uint32 value=NVIC_ST_RELOAD_R;
   return value;
}
uint32 SysTickValueGet(){
     uint32 value=NVIC_ST_CURRENT_R;
        return value;
}
boolean SysTick_Is_Time_out(){
  uint8 value = GET_BIT(NVIC_ST_CTRL_R,16);
  if(value)
    return TRUE;
  else
    return FALSE;                     
}

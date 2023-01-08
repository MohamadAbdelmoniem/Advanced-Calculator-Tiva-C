#ifndef SysticTimer_H_
#define SysticTimer_H_
void SysTickDisable();
void SysTickEnable();
void SysTickPeriodSet (uint32 ui32Period);
uint32 SysTickPeriodGet();
uint32 SysTickValueGet();
boolean SysTick_Is_Time_out();
#endif
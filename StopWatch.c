#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/timer.h"
#include "bitwise_operation.h"
#include "LCD.h"
#include "KeyPad.h"
#include "types.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "Modes.h"

extern uint8 mode;
uint16 FirstDigit_Stopwatch=0;
uint16 SecondDigit_Stopwatch=0;
uint16 ThirdDigit_Stopwatch=0;
uint16 FourthDigit_Stopwatch=0;
uint8 StopWatch_Flag=0;

void Timer0Handler(){
  StopWatch_Flag=1;                                                            //the handler of the interrupt of timer0 is switching th flag into 1 
  TimerIntClear(TIMER0_BASE,TIMER_TIMA_TIMEOUT);                              // and the reset will be in a separte function to make the interrupt small 
  
}

void Stop_Start_Reset(){
  if(GPIOIntStatus(GPIO_PORTA_BASE,0x04)==0x04)
  {
    TimerDisable(TIMER0_BASE,TIMER_A);
    GPIOIntClear(GPIO_PORTA_BASE, GPIO_PIN_2);
    //enable the timer when the start button is pressed and clearing the interrupt
  }
  if(GPIOIntStatus(GPIO_PORTA_BASE,0x08)==0x08)
  {
    TimerEnable(TIMER0_BASE,TIMER_A);
    GPIOIntClear(GPIO_PORTA_BASE, GPIO_PIN_3);
    //disable the timer when the pause button is pressed and clearing the interrupt
    
  }
  if(GPIOIntStatus(GPIO_PORTA_BASE,0x10)==0x10)
  {
    FirstDigit_Stopwatch=0;
    SecondDigit_Stopwatch=0;
    ThirdDigit_Stopwatch=0;
    FourthDigit_Stopwatch=0;                                                       //making all the stopwatch variables to zero
    TimerDisable(TIMER0_BASE,TIMER_A);
    GPIOIntClear(GPIO_PORTA_BASE, GPIO_PIN_4);                                     //disable the timer when the reset button is pressed and clearing the interrupt
  }
  
}


void Timer0Init(){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0)){} 
  
  TimerIntDisable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
  TimerDisable(TIMER0_BASE,TIMER_A);
  
  
  TimerConfigure(TIMER0_BASE,TIMER_CFG_A_PERIODIC);
  TimerIntRegister(TIMER0_BASE,TIMER_A,Timer0Handler);
  TimerLoadSet(TIMER0_BASE, TIMER_A,16000000-1);
  
  //TimerIntRegister(TIMER0_BASE,TIMER_A,Timer0Handler);
  TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
  //the config of the timer but without timer enable 
}
void LCD_Hello(){                                                             
  LCD_command(1);                                                                     //printing the welcome screen of the stopwatch
  LCD_command(0x80);
  LCD_printString("StopWatch Mode");
  
  LCD_command(0xC0);
  LCD_printInt(0);
  
  LCD_command(0xC1);
  LCD_printInt(0);
  
  LCD_command(0xC2);
  LCD_printString(":");
  
  LCD_command(0xC3);
  LCD_printInt(0);
  
  LCD_command(0xC4);
  LCD_printInt(0);
}


void GPIO_INTILLIZE(){
  GPIOIntRegister(GPIO_PORTA_BASE, Stop_Start_Reset);
  
  GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_2, GPIO_FALLING_EDGE);
  GPIOIntEnable(GPIO_PORTA_BASE,GPIO_INT_PIN_2);                              //intitilzing every button to make an interrupt when pressed
  
  GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_3, GPIO_FALLING_EDGE);
  GPIOIntEnable(GPIO_PORTA_BASE,GPIO_INT_PIN_3);
  
  GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_PIN_4, GPIO_FALLING_EDGE);
  GPIOIntEnable(GPIO_PORTA_BASE,GPIO_INT_PIN_4);
  
  
}

void PORTA_INTILLIZE(){
  SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA);
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)){}         //opening clock to the port and making the pin2 to pin4 an input pins and pull down
  GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_2);
  GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_3);
  GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_4);
  GPIO_PORTA_PDR_R|=0x1C;  
}
void StopWatch(){
  LCD_Hello();
  Timer0Init();
  PORTA_INTILLIZE();
  GPIO_INTILLIZE();
  while(mode==2){
    if (StopWatch_Flag==1){                    //after the flag is set to 1 the following code is what happens each second to update the stopwatch
      if ( (FourthDigit_Stopwatch == 9) ){
        ThirdDigit_Stopwatch=ThirdDigit_Stopwatch+1;
        FourthDigit_Stopwatch=0;
      }
      else{
        FourthDigit_Stopwatch = FourthDigit_Stopwatch +1;
      }
      if ( (ThirdDigit_Stopwatch == 6) && (FourthDigit_Stopwatch == 0) ){
        SecondDigit_Stopwatch=SecondDigit_Stopwatch+1;
        ThirdDigit_Stopwatch=0;
        FourthDigit_Stopwatch=0;
      }
      
      if ((SecondDigit_Stopwatch == 9) && (ThirdDigit_Stopwatch == 6) && (FourthDigit_Stopwatch == 0)){
        FirstDigit_Stopwatch=FirstDigit_Stopwatch+1;
        SecondDigit_Stopwatch=0;
        ThirdDigit_Stopwatch=0;
        FourthDigit_Stopwatch=0;
      }
      StopWatch_Flag=0;
    }
    else{
      LCD_command(0xC0);
      LCD_printInt(FirstDigit_Stopwatch);
      
      LCD_command(0xC1);
      LCD_printInt(SecondDigit_Stopwatch);                  //after the increament of the values print the new values
      
      
      LCD_command(0xC3);
      LCD_printInt(ThirdDigit_Stopwatch);
      
      LCD_command(0xC4);
      LCD_printInt(FourthDigit_Stopwatch);
    }
    
  }
  FirstDigit_Stopwatch=0;
  SecondDigit_Stopwatch=0;
  ThirdDigit_Stopwatch=0;
  FourthDigit_Stopwatch=0;
  TimerDisable(TIMER0_BASE,TIMER_A);
  
}



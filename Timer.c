#include "Timer.h"
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "Calculator.h"
#include "LCD.h"
#include "KeyPad.h"
#include "types.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "Modes.h"

extern uint8 mode;
uint8 Flag_Timer=0;
uint16 FirstDigit=0;
uint16 SecondDigit=0;
uint16 ThirdDigit=0;
uint16 FourthDigit=0;


void Handler(){
  Flag_Timer=1;                                              //the interupt handler of the systick timer is to turn flag to 1
}

void LCD_Hello1(){
                                                            //welcome screen for timer mode
  LCD_command(1);
  
  LCD_command(0x80);
  LCD_printString("Timer Mode");
  
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
  
  LCD_command(0xC0);
  LCD_command(0x0F);//cursor blinking 
  
}

void GET_Digits(){                                                      //the process of getting the values from the user
  uint8 value;
  value=Get_Pad_Value(); 
  FirstDigit=value-48;
  delayMs(400);
  LCD_data(value);
  // Get First Digit
  
  value=Get_Pad_Value();
  SecondDigit=value-48;
  delayMs(400);
  LCD_data(value);
  // Get second digit
  
  LCD_command(0xC3);                                            //The third digit on c3 as c2 contains ':'
  value=Get_Pad_Value();
  ThirdDigit=value-48;
  delayMs(400);
  LCD_data(value);
  // Get Third digit
  
  value=Get_Pad_Value();
  FourthDigit=value-48;
  delayMs(400);
  LCD_data(value);
  // Get Fourth digit
}
void Systick_Intillize(){
  SysTickDisable();                                             //intillize the systick and giving the period 1sec
  SysTickIntDisable();
  SysTickPeriodSet(16000000-1);
  SysTickIntRegister(Handler);                                 //when interrupt happens go to the function handler
  SysTickIntEnable();
  SysTickEnable();
}
void Timer(){
  uint8 value;
  DIO_Init_port(PORTF,0x0E);
  LCD_Hello1();
  GET_Digits();
  value=Get_Pad_Value();
  if (value=='=')
    Systick_Intillize();                                                  
  
  while(mode==1)
  {
    if(Flag_Timer==1)                                        //after the flag is set to 1 the following code is what happens each second to update the Timer
    {
      Flag_Timer=0;
      if ((FourthDigit == 0) && (ThirdDigit == 0) && (SecondDigit == 0) && (FirstDigit == 0) )
      {                                         
        SysTickDisable();                                    //after the timer is out make all digits assigned to 0 and turn red LED 5 sec
        FirstDigit=0;
        SecondDigit=0;
        ThirdDigit=0;
        FourthDigit=0;
        DIO_WritePin(PORTF,PIN1,1);
        delayMs(5000);
        DIO_WritePin(PORTF,PIN1,0);
        break;
      }
      else if ( (SecondDigit == 0) && (ThirdDigit == 0) && (FourthDigit == 0) )
      {
        FirstDigit=FirstDigit-1;
        SecondDigit=9;
        ThirdDigit=5;
        FourthDigit=9;
        
      }
      else if((ThirdDigit == 0) && (FourthDigit == 0)) {
        SecondDigit=SecondDigit-1;
        ThirdDigit=5;
        FourthDigit=9;
        
      }
      else if (FourthDigit== 0)
      {
        ThirdDigit=ThirdDigit-1;
        FourthDigit=9;
      }
      else{
        FourthDigit=FourthDigit-1;
      }
    }
    else{
                                                //after each second print the new values of the timer
      LCD_command(0xC0);
      LCD_printInt(FirstDigit);
      
      LCD_command(0xC1);
      LCD_printInt(SecondDigit);
      
      
      LCD_command(0xC3);
      LCD_printInt(ThirdDigit);
      
      LCD_command(0xC4);
      LCD_printInt(FourthDigit); 
      
    }
  }
}
  
  
  
  
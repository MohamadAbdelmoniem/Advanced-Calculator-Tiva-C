#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "KeyPad.h"
#include "LCD.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "Modes.h"
uint32 result;
extern uint8 mode;

uint32 calc(uint32 num1, uint32 num2, uint8 op)
{
  switch(op){
  case '+':
    result=num1+num2;
    break;
  case '-':
    result=num1-num2;
    break;
  case '*':
    result=num1*num2;
    break;
  case '/':
    result=num1/num2;
    break;
  default:
    result=0;
    break;
  }
  return result;
}
void Calculator(){
  while(mode==3){
    uint8 Operator;
    uint32 answerz;
    uint8 value;
    uint32 sum1=0;
    uint32 sum2=0;
    LCD_command(1);
    LCD_init();
                                                                                //Sum1 is the first number that is before the Operator sign
                                                                                //Sum2 is the number that is after the Operator sign
    value=Get_Pad_Value();
    delayMs(500);
    
    while (!((value=='/')||(value== '*') ||(value=='+') || (value=='-' ) )&& (mode==3))
    {
      // value is not an operator
      sum1=(sum1*10)+(value-48);
      LCD_data(value);
      delayMs(100);
      value =Get_Pad_Value();
    }
                                                                                 //getting the value of the first number by *10 and then adding the number
    if(mode==3)
    {
      //operator assigning
      Operator=value;
      LCD_data(Operator);
      delayMs(500);
      value= Get_Pad_Value();
    }
                                                                                //getting the value of the operator which is the first operator that the user enters after the number
    while (!(value == ('='))&& mode==3){
      //second value before equal
      if(value == ('='))
        break;
      else{
        sum2=(sum2*10)+(value-48);
        LCD_data(value);
        delayMs(100);
        value =Get_Pad_Value();
      }
    }
    delayMs(100);
    if (mode==3){
      LCD_data(value);
      delayMs(100);
    }
                                                                                //getting value of the second number by the same way of the first number
    if (sum2==0 && Operator=='/'&&mode==3){
      LCD_printString("Math Error");
      delayMs(5000);
    }
    else if (!((sum1%sum2)==0)&& Operator=='/'){
      answerz=calc(sum1,sum2,Operator);
      LCD_command(0xC0);
      LCD_printInt(answerz);
      LCD_printString(".");
      LCD_printInt((10*(sum1%sum2))/sum2);
      delayMs(5000);
    }
                                                                                //the condition of the result is a float number after the divsion 
    else if(mode==3) {
      answerz=calc(sum1,sum2,Operator);
      LCD_command(0xC0);
      LCD_printInt(answerz);
      delayMs(5000);
                                                                                //getting the result
    }
  }
}

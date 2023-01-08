#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "types.h"
#include<stdio.h>

void SegmentDisplayInit(){
  SYSCTL_RCGCGPIO_R|=0x02;
  GPIO_PORTB_LOCK_R = UNLOCK;
  GPIO_PORTB_CR_R = 0xFF;
  GPIO_PORTB_DIR_R = 0xFF;
  GPIO_PORTB_DEN_R = 0xFF;
}

void Display_Number(uint8 key){
  uint8 segment_num[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  
  switch(key){
    case '0':
        key=0;
        break;
    case '1':
        key=1;
    break;
    case '2':
        key=2;
        break;
    case '3':
        key=3;
        break;
    case '4':
        key=4;
        break;
    case '5':
        key=5;
        break;
    case '6':
        key=6;
        break;
    case '7':
        key=7;
        break;
    case '8':
        key=8;
        break;
    case '9':
        key=9;
        break;
     default:
          
    break;
  }
     DIO_WritePort(PORTB,segment_num[key]);
  }
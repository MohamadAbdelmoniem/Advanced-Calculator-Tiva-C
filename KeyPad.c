#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "Modes.h"
#include "LCD.h"
#include<stdio.h>


uint8 arr[4][4]={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','/'},
  {'*','0','#','='}
};
void KeyPad_Init(){
  SYSCTL_RCGCGPIO_R|=0x14;
  //system clock
  
  GPIO_PORTE_LOCK_R = UNLOCK;
  GPIO_PORTE_CR_R = 0x0F;
  GPIO_PORTE_PDR_R = 0x0F;
  GPIO_PORTE_DEN_R = 0x0F;
  //PORTE init
  
  GPIO_PORTC_LOCK_R = UNLOCK;
  GPIO_PORTC_CR_R = 0xF0;
  GPIO_PORTC_DIR_R = 0xF0;
  GPIO_PORTC_DEN_R = 0xF0;
  //PORTC init
  
}
extern volatile uint8 modes;

uint8 Get_Pad_Value(){
  while (mode==1 || mode==3){
    for(int i=4;i<=7;i++){
      DIO_WritePin(PORTC,i,LOGIC_HIGH);
      delayMs(40);
      for(int j=0;j<=3;j++){
        if (DIO_ReadPin(PORTE,j)){
          DIO_WritePin(PORTC,i,LOGIC_LOW);
          delayMs(40);
          return arr[j][i-4];
        }
      }
      DIO_WritePin(PORTC,i,LOGIC_LOW);
    }
    
  }
}



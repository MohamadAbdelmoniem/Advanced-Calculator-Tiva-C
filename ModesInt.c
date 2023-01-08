#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"

#include "KeyPad.h"
#include "types.h"
#include "DIO.h"
#include "LCD.h"
#include "Timer.h"
#include "StopWatch.h"
#include "Calculator.h"
#include "Modes.h"

extern volatile uint8 modes;

void SwitchModes(){
  if(GPIOIntStatus(GPIO_PORTF_BASE,0x10)==0x10)                        //transfer between modes when pressed and then clear interupt
  {
    delayMs(50);
    mode++;
    if (mode>3)
      mode=0;
  }
      GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4);
}

void GPIO_PORTF_Init(){
  GPIOIntRegister(GPIO_PORTF_BASE, SwitchModes);
                                                                      //when the pin4 is pressed go to the GPIO interupt which is SwitchModes
  GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_4, GPIO_FALLING_EDGE);
  GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_4);
}


void PORTF_INTILLIZE(){
  SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOF);                         //intillize the portf by opening clock and making pin4 input pull up
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){}
  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
  GPIO_PORTF_PDR_R |=0x10;  
}
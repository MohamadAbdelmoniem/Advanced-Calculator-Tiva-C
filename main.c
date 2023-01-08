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
#include "ModesInt.h"

extern volatile uint8 modes;

int main(){
  LCD_init();
  KeyPad_Init();
  PORTF_INTILLIZE();
  GPIO_PORTF_Init();
  LCD_printString("Welcome Team 4");
  delayMs(4000);
  __asm("CPSIE I");
  while(1)
  {
    switch (mode)
    {
    case 1:
      Timer();
    case 2:
      StopWatch();
    case 3:
      Calculator();
    }
  }
}
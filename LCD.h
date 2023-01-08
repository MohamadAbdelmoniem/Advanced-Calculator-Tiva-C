#include "types.h"
#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <stdlib.h> 

#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */

void delayMs(uint32 n);
void delayUs(uint32 n);

void LCD_command (uint8 command) ;
void LCD_data(uint8 data);
void LCD_printInt(uint32 no);
void LCD_printString(char* str);
void LCD_init (void);
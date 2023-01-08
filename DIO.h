#ifndef DIO_H_
#define DIO_H_

#include "types.h"

/*******************************************************************************
*                                Definitions                                  *
*******************************************************************************/
#define NUM_OF_PORTS            6
#define NUM_OF_PINS_PER_PORT    8

#define PORTA	    	        0
#define PORTB   	        1
#define PORTC       	        2
#define PORTD           	3
#define PORTE			4
#define PORTF			5

#define PIN0                	0
#define PIN1                	1
#define PIN2                	2
#define PIN3                	3
#define PIN4            	4
#define PIN5        	        5
#define PIN6    	        6
#define PIN7	                7

#define UNLOCK 		        0x4C4F434B

#define Low                     0
#define High                    1
typedef enum
{
  PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

void DIO_Init_pin (uint8 port_num, uint8 pin_num, GPIO_PinDirectionType Pin_dir);

void DIO_Init_port (uint8 port_num, uint8 port_dir);

void DIO_WritePin (uint8 port_num, uint8 pin_num, uint8 value);

uint8 DIO_ReadPin (uint8 port_num, uint8 pin_num);

void DIO_WritePort(uint8 port_num, uint8 value);

void delay(int num);

void DIO_TogglePin(uint8 port_num, uint8 pin_num);

uint8 DIO_ReadPort (uint8 port_num);


#endif /* DIO_H_ */

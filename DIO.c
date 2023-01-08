#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
void DIO_Init_pin (uint8 port_num, uint8 pin_num, GPIO_PinDirectionType pin_dir)
{
  if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
  {
    
  }
  else
  {
    SET_BIT(SYSCTL_RCGCGPIO_R,port_num);
    while ( BIT_IS_CLEAR(SYSCTL_RCGCGPIO_R,port_num));
    switch(port_num)
    {
    case PORTA:
      GPIO_PORTA_LOCK_R = UNLOCK;
      SET_BIT(GPIO_PORTA_CR_R,pin_num);
      if(pin_dir == PIN_OUTPUT)
      {
        SET_BIT(GPIO_PORTA_DIR_R ,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTA_DIR_R,pin_num);
      }
      SET_BIT(GPIO_PORTA_DEN_R,pin_num);
      break;
    case PORTB:
      GPIO_PORTB_LOCK_R = UNLOCK;
      SET_BIT(GPIO_PORTB_CR_R,pin_num);
      if(pin_dir == PIN_OUTPUT)
      {
        SET_BIT(GPIO_PORTB_DIR_R ,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTB_DIR_R,pin_num);
      }
      SET_BIT(GPIO_PORTB_DEN_R,pin_num);
      break;
    case PORTC:
      GPIO_PORTC_LOCK_R = UNLOCK;
      SET_BIT(GPIO_PORTC_CR_R,pin_num);
      if(pin_dir == PIN_OUTPUT)
      {
        SET_BIT(GPIO_PORTC_DIR_R ,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTC_DIR_R,pin_num);
      }
      SET_BIT(GPIO_PORTC_DEN_R,pin_num);
      break;
    case PORTD:
      GPIO_PORTD_LOCK_R = UNLOCK;
      SET_BIT(GPIO_PORTD_CR_R,pin_num);
      if(pin_dir == PIN_OUTPUT)
      {
        SET_BIT(GPIO_PORTD_DIR_R ,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTD_DIR_R,pin_num);
      }
      SET_BIT(GPIO_PORTD_DEN_R,pin_num);
      break;
    case PORTE:
      GPIO_PORTE_LOCK_R = UNLOCK;
      SET_BIT(GPIO_PORTE_CR_R,pin_num);
      if(pin_dir == PIN_OUTPUT)
      {
        SET_BIT(GPIO_PORTE_DIR_R ,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTE_DIR_R,pin_num);
      }
      SET_BIT(GPIO_PORTE_DEN_R,pin_num);
      break;
    case PORTF:
      GPIO_PORTF_LOCK_R = UNLOCK;
      SET_BIT(GPIO_PORTF_CR_R,pin_num);
      if(pin_dir == PIN_OUTPUT)
      {
        SET_BIT(GPIO_PORTF_DIR_R ,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTF_DIR_R,pin_num);
      }
      SET_BIT(GPIO_PORTF_DEN_R,pin_num);
      break;
    }
  }
}
void DIO_Init_port (uint8 port_num, uint8 port_dir)
//port_dir may be equal 0x0E 
//in PORTF to active the lED
//port_num may be equal GPIOF
{
  if((port_num >= NUM_OF_PORTS))
  {
    
  }
  else
  {
    SET_BIT(SYSCTL_RCGCGPIO_R,port_num);
    SET_BIT(NVIC_ST_CTRL_R,port_num);

    while ( BIT_IS_CLEAR(SYSCTL_RCGCGPIO_R,port_num));
    switch(port_num)
      //GPIOF
    {
    case PORTA:
      GPIO_PORTA_LOCK_R = UNLOCK;
      GPIO_PORTA_CR_R = 0xFF;
      GPIO_PORTA_DIR_R = port_dir;
      GPIO_PORTA_PUR_R = (~port_dir);
      GPIO_PORTA_DEN_R = 0xFF;
      
      break;
    case PORTB:
      GPIO_PORTB_LOCK_R = UNLOCK;
      GPIO_PORTB_CR_R = 0xFF;
      GPIO_PORTB_DIR_R = port_dir;
      GPIO_PORTB_PUR_R = (~port_dir);
      GPIO_PORTB_DEN_R = 0xFF;
      
      break;
    case PORTC:
           GPIO_PORTC_LOCK_R = UNLOCK;
      GPIO_PORTC_CR_R = 0xFF;
      GPIO_PORTC_DIR_R = port_dir;
      GPIO_PORTC_PUR_R = (~port_dir);
     GPIO_PORTC_DEN_R = 0xFF;
      break;
    case PORTD:
     GPIO_PORTD_LOCK_R = UNLOCK;
      GPIO_PORTD_CR_R = 0xFF;
      GPIO_PORTD_DIR_R = port_dir;
      GPIO_PORTD_PUR_R = (~port_dir);
      GPIO_PORTD_DEN_R = 0xFF;
      
      break;
    case PORTE:
      GPIO_PORTE_LOCK_R = UNLOCK;
      GPIO_PORTE_CR_R = 0xFF;
      GPIO_PORTE_DIR_R = port_dir;
      GPIO_PORTE_PUR_R = (~port_dir);
      GPIO_PORTE_DEN_R = 0xFF;
      
      break;
    case PORTF:
      GPIO_PORTF_LOCK_R = UNLOCK;
      GPIO_PORTF_CR_R = 0xFF;
      GPIO_PORTF_DIR_R = port_dir;
      GPIO_PORTF_PUR_R = (~port_dir);
      GPIO_PORTF_DEN_R = 0xFF;
      
      break;
    }
  }
}


void DIO_WritePin (uint8 port_num, uint8 pin_num, uint8 value)
{
  if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
  {
    
  }
  else
  {
    switch(port_num)
    {
    case PORTA:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTA_DATA_R,pin_num);
        //SET_BIT(NVIC_ST_CTRL_R,pin_num);
        //SET_BIT(NVIC_ST_CTRL_ENABLE,pin_num);
        
      }
      else
      {
        CLEAR_BIT(GPIO_PORTA_DATA_R,pin_num);
      }
      break;
    case PORTB:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTB_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTB_DATA_R,pin_num);
      }
      break;
    case PORTC:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTC_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTC_DATA_R,pin_num);
      }
      break;
    case PORTD:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTD_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTD_DATA_R,pin_num);
      }
      break;
    case PORTE:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTE_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTE_DATA_R,pin_num);
      }
      break;
    case PORTF:
      if(value == LOGIC_HIGH)
      {
        SET_BIT(GPIO_PORTF_DATA_R,pin_num);
      }
      else
      {
        CLEAR_BIT(GPIO_PORTF_DATA_R,pin_num);
      }
      break;
    }
  }
}

uint8 DIO_ReadPin (uint8 port_num, uint8 pin_num)
{
  uint8 pin_value = 0;
  
  
  if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
  {
  }
  else
  {
    switch(port_num)
    {
    case PORTA:
      pin_value = GET_BIT(GPIO_PORTA_DATA_R,pin_num);
      break;
    case PORTB:
      pin_value = GET_BIT(GPIO_PORTB_DATA_R,pin_num);
      break;
    case PORTC:
      pin_value = GET_BIT(GPIO_PORTC_DATA_R,pin_num);
      break;
    case PORTD:
      pin_value = GET_BIT(GPIO_PORTD_DATA_R,pin_num);
      break;
    case PORTE:
      pin_value = GET_BIT(GPIO_PORTE_DATA_R,pin_num);
      break;
    case PORTF:
      pin_value = GET_BIT(GPIO_PORTF_DATA_R,pin_num);
      break;
    }
  }
  return pin_value;
}

void DIO_WritePort(uint8 port_num, uint8 value)
//the same as write DIO_WritePin but we give the exact value already
{
  
  
  if(port_num >= NUM_OF_PORTS)
  {
    /* Do Nothing */
  }
  else
  {
    switch(port_num)
    {
    case PORTA:
      GPIO_PORTA_DATA_R = value;
      break;
    case PORTB:
      GPIO_PORTB_DATA_R= value;
      break;
    case PORTC:
      GPIO_PORTC_DATA_R = value;
      break;
    case PORTD:
      GPIO_PORTD_DATA_R = value;
      break;
    case PORTE:
      GPIO_PORTE_DATA_R = value;
      break;
    case PORTF:
      GPIO_PORTF_DATA_R = value;
      break;
    }
  }
}

uint8 DIO_ReadPort (uint8 port_num)
{
  uint8 value = LOGIC_LOW;
  
  
  if(port_num >= NUM_OF_PORTS)
  {
    
  }
  else
  {
    switch(port_num)
    {
    case PORTA:
      value = (uint8)GPIO_PORTA_DATA_R;
      break;
    case PORTB:
      value =(uint8) GPIO_PORTB_DATA_R;
      break;
    case PORTC:
      value = (uint8)GPIO_PORTC_DATA_R;
      break;
    case PORTD:
      value = (uint8)GPIO_PORTD_DATA_R;
      break;
    case PORTE:
      value = (uint8)GPIO_PORTE_DATA_R;
      break;
    case PORTF:
      value =(uint8) GPIO_PORTF_DATA_R;
      break;
    }
  }
  
  return value;
}

void delay(int num)
{
  for(int i =0;i<num;i++);
}
void DIO_TogglePin(uint8 port_num, uint8 pin_num)
{
  if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
  {
    
  }
  else
  {
    switch(port_num)
    {
    case PORTA:
      TOGGLE_BIT(GPIO_PORTA_DATA_R,pin_num);
     
      break;
    case PORTB:
      TOGGLE_BIT(GPIO_PORTB_DATA_R,pin_num);
     
      break;
    case PORTC:
      TOGGLE_BIT(GPIO_PORTC_DATA_R,pin_num);
     
      break;
    case PORTD:
      TOGGLE_BIT(GPIO_PORTD_DATA_R,pin_num);
      
      break;
    case PORTE:
      TOGGLE_BIT(GPIO_PORTE_DATA_R,pin_num);
     
      break;
    case PORTF:
      TOGGLE_BIT(GPIO_PORTF_DATA_R,pin_num);
      break;
    }
  }
  
}
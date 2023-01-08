#ifndef BITWISE_OPERATION
#define BITWISE_OPERATION

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
//BIT can be any number from 0 to 7

#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))


#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )

#endif

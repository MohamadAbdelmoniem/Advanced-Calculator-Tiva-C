/*
 * types.h
 *
 *  
 *      
 */
#ifndef TYPES_H_
#define TYPES_H_
/* Boolean Data Type */
typedef unsigned char boolean;
/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL_PTR    ((void*)0)

typedef unsigned char         	uint8;          /*           0 .. 255              */
typedef unsigned char*         	uint8_ptr;
typedef signed char           	int8;          /*        -128 .. +127             */
typedef signed char*           	int8_ptr;
typedef unsigned short        	uint16;         /*           0 .. 65535            */
typedef unsigned short*        	uint16_ptr;
typedef signed short          	int16;         /*      -32768 .. +32767           */
typedef signed short*         	int16_ptr;
typedef unsigned int         	uint32;         /*           0 .. 4294967295       */
typedef unsigned int*         	uint32_ptr;
typedef signed int           	int32;         /* -2147483648 .. +2147483647      */
typedef signed int*           	int32_ptr;
typedef unsigned long long    	uint64;         /*       0 .. 18446744073709551615  */
typedef unsigned long long*    	uint64_ptr;
typedef signed long long      	int64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef signed long long*      	int64_ptr;
typedef float                 	float32;
typedef float*                 	float32_ptr;
typedef double                	float64;
typedef double*                	float64_ptr;
#endif /* TYPES_H_ */

/*
typedef give symbolic names to a data type, but #define is just a text replacment
so for example when declaring 2 pointer to integer variables in one line
Using typedef: the 2 variables will be pointer to integer
Using #define: the 1st variable will be pointer to integer and the 2nd variable will be an integer
*/

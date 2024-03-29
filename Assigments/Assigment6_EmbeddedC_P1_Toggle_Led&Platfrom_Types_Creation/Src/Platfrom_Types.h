#ifndef PLATFROM_TYPES_H
#define PLATFROM_TYPES_H
#endif
/*AUTOSAR specifcation version 4.3.1*/
#define PLATFROM_TYPES_AR_REALSE_MAJOR_VERSION 4
#define PLATFROM_TYPES_AR_REALSE_MINOR_VERSION 3
#define PLATFROM_TYPES_AR_REALSE_REVISION_VERSION 1

/*
Bit order defination
*/
#define LSB_FIRST 1 /*Littile endian bit ordering*/
#define MSB_FIRST 0  /* Big endian bit ordering */


/*
Byte order defination
*/
#define LOW_BYTE_FIRST 1 /*Littile endian byte ordering*/
#define HIGH_BYTE_FIRST 0  /* Big endian byte ordering  */

/*
*Typde defenations
*/
typedef signed char sint8;          /*-128 to 127*/  
typedef unsigned char uint8;        /* 0 to 255*/ 
typedef signed short sint16;        /* -32768 to 32767*/
typedef unsigned short uint16;      /* 0 to 65535*/
typedef signed long sint32;         /* -2147483648 to 2147483647*/
typedef unsigned long uint32;       /* 0 to 4294967295 */
typedef signed long long sint64;    
typedef unsigned long long uint64;
typedef float float32;
typedef double float64;
typedef unsigned char boolean;

#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE    0
#endif



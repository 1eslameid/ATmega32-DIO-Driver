/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : STD_TYPES.h                                     */
/* Description ............ : Standard Data Types & General Definitions       */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/* ============================================================================================== */
/*                                      Standard Data Types                                       */
/* ============================================================================================== */

typedef unsigned char        u8;   /* 8-bit Unsigned  : 0 to 255                                 */
typedef unsigned short int   u16;  /* 16-bit Unsigned : 0 to 65,535                              */
typedef unsigned long int    u32;  /* 32-bit Unsigned : 0 to 4,294,967,295                      */
typedef unsigned long long   u64;  /* 64-bit Unsigned                                           */

typedef signed char          s8;   /* 8-bit Signed    : -128 to 127                              */
typedef signed short int     s16;  /* 16-bit Signed   : -32,768 to 32,767                        */
typedef signed long int      s32;  /* 32-bit Signed   : -2,147,483,648 to 2,147,483,647          */
typedef signed long long     s64;  /* 64-bit Signed                                             */

typedef float                f32;  /* 32-bit Single Precision Floating Point                     */
typedef double               f64;  /* 64-bit Double Precision Floating Point                     */

/* ============================================================================================== */
/*                                      Standard Definitions                                      */
/* ============================================================================================== */

#endif /* STD_TYPES_H */
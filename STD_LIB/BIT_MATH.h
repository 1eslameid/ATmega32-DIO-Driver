/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : BIT_MATH.h                                      */
/* Description ............ : Bit Manipulation Macros & Concatenation Utility */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

/* ========================================================================== */
/*                           Bit Manipulation Macros                          */
/* ========================================================================== */

#define SET_BIT(REG, BITNUM)               ((REG) |=  (1 << (BITNUM)))
#define CLR_BIT(REG, BITNUM)               ((REG) &= ~(1 << (BITNUM)))
#define TOGGLE_BIT(REG, BITNUM)            ((REG) ^=  (1 << (BITNUM)))
#define GET_BIT(REG, BITNUM)               (((REG) >> (BITNUM)) & 0x01)

/* ========================================================================== */
/*                         Register Manipulation Macros                       */
/* ========================================================================== */

#define SET_BYTE(REG, VALUE)               ((REG) = (VALUE))
#define SET_REG(REG)                       ((REG) = 0xFF)
#define CLR_REG(REG)                       ((REG) = 0x00)

/* ========================================================================== */
/*                         Bit Concatenation Macros                           */
/* ========================================================================== */

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0) CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0)

#endif /* BIT_MATH_H */
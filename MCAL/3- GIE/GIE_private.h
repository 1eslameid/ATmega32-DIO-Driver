/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : GIE PRIVATE FILE                                */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

/* Status Register - SREG */
#define SREG        *((volatile u8*)0x5F)

/* Global Interrupt Enable Bit */
#define SREG_I      7

#endif /* GIE_REGISTER_H_ */
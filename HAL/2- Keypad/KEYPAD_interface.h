/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : KEYPAD_INTERFACE.h                                */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef KEYPAD_PRIVATE_H
#define KEYPAD_PRIVATE_H
/*********************************************************************/
/*                      Functions Prototypes                         */
/*********************************************************************/
void KEYPAD_voidInit(void);
u8 KEYPAD_u8GetPressedKey(void);

#endif // KEYPAD_INTERFACE_H
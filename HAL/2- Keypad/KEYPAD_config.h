/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : KEYPAD_CONFIG.h                                */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H
/* ========================================================================= */
/*                        KEYPAD Hardware Configurations                     */
/* ========================================================================= */
    /*KEYPAD PORT*/
#define KEYPAD_PORT  PORT_C
    /*ROW PINS*/
#define KEYPAD_R0_PIN  PIN0
#define KEYPAD_R1_PIN  PIN1
#define KEYPAD_R2_PIN  PIN2
#define KEYPAD_R3_PIN  PIN3

    /*COLUMN PINS*/
#define KEYPAD_C0_PIN  PIN4
#define KEYPAD_C1_PIN  PIN5
#define KEYPAD_C2_PIN  PIN6
#define KEYPAD_C3_PIN  PIN7

#define KEYPAD_NO_PRESSED_KEY 0xFF


#endif // KEYPAD_CONFIG_H


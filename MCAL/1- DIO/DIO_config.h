/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : DIO_config.h                                    */
/* Description ............ : Static Configuration Header for DIO Driver      */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/* ========================================================================== */
/*                             PORTA Configuration                            */
/* ========================================================================== */

#define DIO_PORTA_PIN0_DIR    OUTPUT
#define DIO_PORTA_PIN1_DIR    OUTPUT
#define DIO_PORTA_PIN2_DIR    OUTPUT
#define DIO_PORTA_PIN3_DIR    OUTPUT
#define DIO_PORTA_PIN4_DIR    INPUT
#define DIO_PORTA_PIN5_DIR    INPUT
#define DIO_PORTA_PIN6_DIR    INPUT
#define DIO_PORTA_PIN7_DIR    INPUT

#define DIO_PORTA_DIR         CONC_HELP(DIO_PORTA_PIN7_DIR, DIO_PORTA_PIN6_DIR, DIO_PORTA_PIN5_DIR, DIO_PORTA_PIN4_DIR, DIO_PORTA_PIN3_DIR, DIO_PORTA_PIN2_DIR, DIO_PORTA_PIN1_DIR, DIO_PORTA_PIN0_DIR)

/* ========================================================================== */
/*                             PORTB Configuration                            */
/* ========================================================================== */

#define DIO_PORTB_PIN0_DIR    OUTPUT
#define DIO_PORTB_PIN1_DIR    OUTPUT
#define DIO_PORTB_PIN2_DIR    OUTPUT
#define DIO_PORTB_PIN3_DIR    OUTPUT
#define DIO_PORTB_PIN4_DIR    OUTPUT
#define DIO_PORTB_PIN5_DIR    OUTPUT
#define DIO_PORTB_PIN6_DIR    OUTPUT
#define DIO_PORTB_PIN7_DIR    OUTPUT

#define DIO_PORTB_DIR         CONC_HELP(DIO_PORTB_PIN7_DIR, DIO_PORTB_PIN6_DIR, DIO_PORTB_PIN5_DIR, DIO_PORTB_PIN4_DIR, DIO_PORTB_PIN3_DIR, DIO_PORTB_PIN2_DIR, DIO_PORTB_PIN1_DIR, DIO_PORTB_PIN0_DIR)

/* ========================================================================== */
/*                             PORTC Configuration                            */
/* ========================================================================== */

#define DIO_PORTC_PIN0_DIR    OUTPUT
#define DIO_PORTC_PIN1_DIR    OUTPUT
#define DIO_PORTC_PIN2_DIR    OUTPUT
#define DIO_PORTC_PIN3_DIR    OUTPUT
#define DIO_PORTC_PIN4_DIR    OUTPUT
#define DIO_PORTC_PIN5_DIR    OUTPUT
#define DIO_PORTC_PIN6_DIR    OUTPUT
#define DIO_PORTC_PIN7_DIR    OUTPUT

#define DIO_PORTC_DIR         CONC_HELP(DIO_PORTC_PIN7_DIR, DIO_PORTC_PIN6_DIR, DIO_PORTC_PIN5_DIR, DIO_PORTC_PIN4_DIR, DIO_PORTC_PIN3_DIR, DIO_PORTC_PIN2_DIR, DIO_PORTC_PIN1_DIR, DIO_PORTC_PIN0_DIR)

/* ========================================================================== */
/*                             PORTD Configuration                            */
/* ========================================================================== */

#define DIO_PORTD_PIN0_DIR    INPUT
#define DIO_PORTD_PIN1_DIR    INPUT
#define DIO_PORTD_PIN2_DIR    INPUT
#define DIO_PORTD_PIN3_DIR    INPUT
#define DIO_PORTD_PIN4_DIR    INPUT
#define DIO_PORTD_PIN5_DIR    INPUT
#define DIO_PORTD_PIN6_DIR    INPUT
#define DIO_PORTD_PIN7_DIR    INPUT

#define DIO_PORTD_DIR         CONC_HELP(DIO_PORTD_PIN7_DIR, DIO_PORTD_PIN6_DIR, DIO_PORTD_PIN5_DIR, DIO_PORTD_PIN4_DIR, DIO_PORTD_PIN3_DIR, DIO_PORTD_PIN2_DIR, DIO_PORTD_PIN1_DIR, DIO_PORTD_PIN0_DIR)

#endif /* DIO_CONFIG_H */
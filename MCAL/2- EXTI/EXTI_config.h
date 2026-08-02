/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : EXTI CONFIGURATION FILE                         */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/*SENSE CONTROL FOR INT0 and INT 1:*/
/*1. EXTI_LOW_LEVEL              */
/*2. EXTI_ON_LEVEL               */
/*3. EXTI_FALLING_SENSE          */
/*4. EXTI_RISING_SENSE           */
#define EXTI_INT0_SENSE         EXIT_FALLING_EDGE
#define EXTI_INT1_SENSE         EXIT_FALLING_EDGE

/*SENSE CONTROL FOR INT2:         */
/*1. EXTI_FALLING_SENSE          */
/*2. EXTI_RISING_SENSE           */
#define EXTI_INT2_SENSE             EXIT_FALLING_EDGE

/*INITIAL STATE                  */
/*1. EXIT_ENABLE                 */
/*2. EXIT_DISABLE                */

#define EXTI_INT0_INITIAL_STATE     EXTI_ENABLE   
#define EXTI_INT1_INITIAL_STATE     EXTI_DISABLE 
#define EXTI_INT2_INITIAL_STATE     EXTI_DISABLE 

#endif
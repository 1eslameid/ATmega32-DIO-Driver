/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : ADC PRIVATE  FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Hardware Register Addresses (ATmega32) */
#define ADMUX       (*((volatile u8*)0x27))
#define ADCSRA      (*((volatile u8*)0x26))
#define ADCH        (*((volatile u8*)0x25))
#define ADCL        (*((volatile u8*)0x24))
#define ADC_DATA    (*((volatile u16*)0x24)) /* Reads ADCL and ADCH together */
#define SFIOR       (*((volatile u8*)0x50))

/* VREF Configuration Options */
#define AREF_REF              0
#define AVCC_REF              1
#define INTERNAL_2_56V_REF    2

/* Adjustment Options */
#define RIGHT_ADJUSTMENT      0
#define LEFT_ADJUSTMENT       1

/* Prescaler Division Options */
#define PRESCALER_DIV_2       1
#define PRESCALER_DIV_4       2
#define PRESCALER_DIV_8       3
#define PRESCALER_DIV_16      4
#define PRESCALER_DIV_32      5
#define PRESCALER_DIV_64      6
#define PRESCALER_DIV_128     7

#endif
/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : ADC CONFIG FILE                                 */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*
 * Select Voltage Reference (VREF):
 * 1. AREF_REF
 * 2. AVCC_REF
 * 3. INTERNAL_2_56V_REF
 */
#define ADC_VREF_SELECTION     AVCC_REF

/*
 * Select Data Adjustment:
 * 1. RIGHT_ADJUSTMENT
 * 2. LEFT_ADJUSTMENT
 */
#define ADC_ADJUSTMENT         RIGHT_ADJUSTMENT

/*
 * Select Clock Prescaler:
 * PRESCALER_DIV_2, PRESCALER_DIV_4, PRESCALER_DIV_8,
 * PRESCALER_DIV_16, PRESCALER_DIV_32, PRESCALER_DIV_64, PRESCALER_DIV_128
 */
#define ADC_PRESCALER          PRESCALER_DIV_64

/* Timeout loop counter to prevent infinite blocking in Synchronous Functions */
#define ADC_TIMEOUT            50000UL

#endif
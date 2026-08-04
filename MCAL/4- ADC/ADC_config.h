/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : ADC CONFIG FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*
 Select Voltage Reference (VREF):
 - AREF_REF
 -AVCC_REF
 - INTERNAL_2_56V_REF
 */
#define ADC_VREF_SELECTION     AVCC_REF

/*
 Select Data Adjustment:
- RIGHT_ADJUSTMENT
- LEFT_ADJUSTMENT
 */
#define ADC_ADJUSTMENT         RIGHT_ADJUSTMENT

/*
  Select Clock Prescaler:
- PRESCALER_DIV_2
  -PRESCALER_DIV_4
 -PRESCALER_DIV_8
 -PRESCALER_DIV_16
 -PRESCALER_DIV_32
 -PRESCALER_DIV_64
 -PRESCALER_DIV_128
 */
#define ADC_PRESCALER          PRESCALER_DIV_64

/* Timeout loop counter */
#define ADC_TIMEOUT            50000UL

#endif
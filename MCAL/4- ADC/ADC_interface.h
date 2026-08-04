/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : ADC INTERFACE FILE                             */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "STD_TYPES.h"

/* ADC Channel  */
#define ADC_CHANNEL0    0
#define ADC_CHANNEL1    1
#define ADC_CHANNEL2    2
#define ADC_CHANNEL3    3
#define ADC_CHANNEL4    4
#define ADC_CHANNEL5    5
#define ADC_CHANNEL6    6
#define ADC_CHANNEL7    7

/************************/

void ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
void ADC_voidStartConversion(u8 u8Channel);

/* Synchronous Read FunctioN */
u16  ADC_u16ReadSynchronous(u8 u8Channel);

/* Asynchronous Read Function */
void ADC_voidReadAsynchronous(u8 u8Channel, pf pfNotificationFunc);

void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);
void ADC_voidSetCallBack(pf pfFunctionAddress);

#endif
/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : TIM0 INTERFACE FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_

#include "STD_TYPES.h"

/* Pointer to Function */
typedef void (*pf)(void);

/*******************************************************************************
 *                            Prototypes                                 *
 *******************************************************************************/

/* Initialization */
void TIM0_voidInit(void);

/* Normal Mode */
void TIM0_voidEnableOVInterrupt(void);
void TIM0_voidDisableOVInterrupt(void);
void TIM0_voidSetPreloadReg(u8 u8PreloadValue);
u8   TIM0_u8ReadTimerReg(void);
void TIM0_voidOVSetCallBack(pf pvOVFunctionAddress);

/* CTC Mode */
void TIM0_voidEnableCOMPInterrupt(void);
void TIM0_voidDisableCOMPInterrupt(void);
void TIM0_voidSetCompareReg(u8 u8CompareValue);
void TIM0_voidCOMPSetCallBack(pf pvCOMPFunctionAddress);

/*PWM*/
void TIM0_voidGeneratePWM(u8 u8DutyCycle);

#endif /* TIM0_INTERFACE_H_ */

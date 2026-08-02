/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : EXTI INTERFACE FILE                             */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* EXTI Interrupt Channels */
#define EXTI_INT0           0
#define EXTI_INT1           1
#define EXTI_INT2           2

/* EXTI Sense Control Modes */
#define EXTI_LOW_LEVEL      0
#define EXTI_ON_CHANGE      1
#define EXTI_FALLING_EDGE   2
#define EXTI_RISING_EDGE    3

/* EXTI Initial States */
#define EXTI_ENABLE         1
#define EXTI_DISABLE        0

/* Function Prototypes */
void EXTI_voidInit(void);
void EXTI_voidSetSenseControl(u8 u8IntNumber, u8 u8SenseControl);
void EXTI_voidEnableInterrupt(u8 u8IntNumber);
void EXTI_voidDisableInterrupt(u8 u8IntNumber);

/* CallBack Function Setup */
void EXTI_voidSetCallBack(u8 u8IntNumber, void(*pf)(void));

#endif
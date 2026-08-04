/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : TIM0 PRIVATE FILE                                */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef TIM0_PRIVATE_H_
#define TIM0_PRIVATE_H_

/* Timer 0 Hardware Registers */
#define TCCR0    *((volatile u8*)0x53)
#define TCNT0    *((volatile u8*)0x52)
#define OCR0     *((volatile u8*)0x5C)
#define TIMSK    *((volatile u8*)0x59)
#define TIFR     *((volatile u8*)0x58)

/* TCCR0 Register Bits */
#define CS00     0
#define CS01     1
#define CS02     2
#define WGM01    3
#define COM00    4
#define COM01    5
#define WGM00    6
#define FOC0     7

/* TIMSK  Bits */
#define TOIE0    0
#define OCIE0    1

/* TIFR  Bits */
#define TOV0     0
#define OCF0     1

/* Timer0 Modes  */
#define TIM0_NORMAL_MODE    0
#define TIM0_CTC_MODE       2
#define TIM0_FAST_PWM_MODE  3


/* Prescaler Options */
#define TIM0_NO_CLOCK          0
#define TIM0_PRESCALER_1       1
#define TIM0_PRESCALER_8       2
#define TIM0_PRESCALER_64      3
#define TIM0_PRESCALER_256     4
#define TIM0_PRESCALER_1024    5
#define TIM0_EXT_CLOCK_FALLING 6
#define TIM0_EXT_CLOCK_RISING  7

/* Fast PWM OC0 PINS MODES*/
#define TIM0_PWM_DISCONNECTED     0
#define TIM0_PWM_NON_INVERTING    2
#define TIM0_PWM_INVERTING        3



#endif /* TIM0_PRIVATE_H_ */

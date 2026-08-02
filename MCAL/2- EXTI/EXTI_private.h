/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : EXTI PRIVATE FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef NULL
#define NULL    ((void*)0)
#endif

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


/*SENSE CONTROL REG*/
#define MCUCR   *((volatile u8*)0x55)
#define MCUCSR   *((volatile u8*)0x54)

/*EXTI ENABLE REG*/
#define GICR *((volatile u8*)0x5B)

/*GIF REG*/
#define GIFR *((volatile u8*)0x5A)

/* Linker Script */
#define EXTI_INT0_VECT    __vector_1
#define EXTI_INT1_VECT    __vector_2
#define EXTI_INT2_VECT    __vector_3

/** ISR */
#define ISR(vector)    void vector (void) __attribute__ ((signal, used)); \
                       void vector (void)





#endif
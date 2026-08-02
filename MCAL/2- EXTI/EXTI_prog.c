/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : EXTI PROGRAM FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#include "STD_TYPES.H"
#include "BIT_MATH.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"

/* Global Pointers to Functions for CallBack Mechanism */
static void (*EXTI_pvInt0CallBackFunc)(void) = NULL;
static void (*EXTI_pvInt1CallBackFunc)(void) = NULL;
static void (*EXTI_pvInt2CallBackFunc)(void) = NULL;

/* 1- Static Initialization Function (Config Driven) */
void EXTI_voidInit(void)
{
    /* INT0 Sense Control */
    #if EXTI_INT0_SENSE == EXTI_LOW_LEVEL
        CLR_BIT(MCUCR, 0); CLR_BIT(MCUCR, 1);
    #elif EXTI_INT0_SENSE == EXTI_ON_CHANGE
        SET_BIT(MCUCR, 0); CLR_BIT(MCUCR, 1);
    #elif EXTI_INT0_SENSE == EXTI_FALLING_EDGE
        CLR_BIT(MCUCR, 0); SET_BIT(MCUCR, 1);
    #elif EXTI_INT0_SENSE == EXTI_RISING_EDGE
        SET_BIT(MCUCR, 0); SET_BIT(MCUCR, 1);
    #endif

    /* INT0 Initial State */
    #if EXTI_INT0_INITIAL_STATE == EXTI_ENABLE
        SET_BIT(GICR, 6);
    #elif EXTI_INT0_INITIAL_STATE == EXTI_DISABLE
        CLR_BIT(GICR, 6);
    #endif

    /* INT1 Sense Control */
    #if EXTI_INT1_SENSE == EXTI_LOW_LEVEL
        CLR_BIT(MCUCR, 2); CLR_BIT(MCUCR, 3);
    #elif EXTI_INT1_SENSE == EXTI_ON_CHANGE
        SET_BIT(MCUCR, 2); CLR_BIT(MCUCR, 3);
    #elif EXTI_INT1_SENSE == EXTI_FALLING_EDGE
        CLR_BIT(MCUCR, 2); SET_BIT(MCUCR, 3);
    #elif EXTI_INT1_SENSE == EXTI_RISING_EDGE
        SET_BIT(MCUCR, 2); SET_BIT(MCUCR, 3);
    #endif

    /* INT1 Initial State */
    #if EXTI_INT1_INITIAL_STATE == EXTI_ENABLE
        SET_BIT(GICR, 7);
    #elif EXTI_INT1_INITIAL_STATE == EXTI_DISABLE
        CLR_BIT(GICR, 7);
    #endif

    /* INT2 Sense Control */
    #if EXTI_INT2_SENSE == EXTI_FALLING_EDGE
        CLR_BIT(MCUCSR, 6);
    #elif EXTI_INT2_SENSE == EXTI_RISING_EDGE
        SET_BIT(MCUCSR, 6);
    #endif

    /* INT2 Initial State */
    #if EXTI_INT2_INITIAL_STATE == EXTI_ENABLE
        SET_BIT(GICR, 5);
    #elif EXTI_INT2_INITIAL_STATE == EXTI_DISABLE
        CLR_BIT(GICR, 5);
    #endif
}

/* 2- Dynamic Sense Control Setup (Runtime Change) */
void EXTI_voidSetSenseControl(u8 u8IntNumber, u8 u8SenseControl)
{
    switch(u8IntNumber)
    {
        case EXTI_INT0:
            switch(u8SenseControl)
            {
                case EXTI_LOW_LEVEL:    CLR_BIT(MCUCR, 0); CLR_BIT(MCUCR, 1); break;
                case EXTI_ON_CHANGE:    SET_BIT(MCUCR, 0); CLR_BIT(MCUCR, 1); break;
                case EXTI_FALLING_EDGE: CLR_BIT(MCUCR, 0); SET_BIT(MCUCR, 1); break;
                case EXTI_RISING_EDGE:  SET_BIT(MCUCR, 0); SET_BIT(MCUCR, 1); break;
            }
            break;

        case EXTI_INT1:
            switch(u8SenseControl)
            {
                case EXTI_LOW_LEVEL:    CLR_BIT(MCUCR, 2); CLR_BIT(MCUCR, 3); break;
                case EXTI_ON_CHANGE:    SET_BIT(MCUCR, 2); CLR_BIT(MCUCR, 3); break;
                case EXTI_FALLING_EDGE: CLR_BIT(MCUCR, 2); SET_BIT(MCUCR, 3); break;
                case EXTI_RISING_EDGE:  SET_BIT(MCUCR, 2); SET_BIT(MCUCR, 3); break;
            }
            break;

        case EXTI_INT2:
            switch(u8SenseControl)
            {
                case EXTI_FALLING_EDGE: CLR_BIT(MCUCSR, 6); break;
                case EXTI_RISING_EDGE:  SET_BIT(MCUCSR, 6); break;
            }
            break;
    }
}

/* 3- Enable Specific Interrupt */
void EXTI_voidEnableInterrupt(u8 u8IntNumber)
{
    switch(u8IntNumber)
    {
        case EXTI_INT0: SET_BIT(GICR, 6); break;
        case EXTI_INT1: SET_BIT(GICR, 7); break;
        case EXTI_INT2: SET_BIT(GICR, 5); break;
    }
}

/* 4- Disable Specific Interrupt */
void EXTI_voidDisableInterrupt(u8 u8IntNumber)
{
    switch(u8IntNumber)
    {
        case EXTI_INT0: CLR_BIT(GICR, 6); break;
        case EXTI_INT1: CLR_BIT(GICR, 7); break;
        case EXTI_INT2: CLR_BIT(GICR, 5); break;
    }
}

/* 5- Set Call Back Function */
void EXTI_voidSetCallBack(u8 u8IntNumber, void (*pvNotificationFunction)(void))
{
    if(pvNotificationFunction != NULL)
    {
        switch(u8IntNumber)
        {
            case EXTI_INT0: EXTI_pvInt0CallBackFunc = pvNotificationFunction; break;
            case EXTI_INT1: EXTI_pvInt1CallBackFunc = pvNotificationFunction; break;
            case EXTI_INT2: EXTI_pvInt2CallBackFunc = pvNotificationFunction; break;
        }
    }
}

/* 6- Hardware ISR Drivers */

// IST ----> INT0
void __vector_1 (void) __attribute__ ((signal, used));
void __vector_1 (void)
{
	if(EXTI_pvInt0CallBackFunc != NULL)
	{
		EXTI_pvInt0CallBackFunc();
	}
}

// IST ----> INT1
void __vector_2 (void) __attribute__ ((signal, used));
void __vector_2 (void)
{
	if(EXTI_pvInt1CallBackFunc != NULL)
	{
		EXTI_pvInt1CallBackFunc();  
	}
}

// IST ----> INT2
void __vector_3 (void) __attribute__ ((signal, used));
void __vector_3 (void)
{
	if(EXTI_pvInt2CallBackFunc != NULL)
	{
		EXTI_pvInt2CallBackFunc();  
	}
}
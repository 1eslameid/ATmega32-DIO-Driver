/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : ADC PROGRAM FILE                                */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


static pf ADC_pvCallBackFunc = NULL;

void ADC_voidInit(void)
{
//  SELECTReference Voltage 
    #if ADC_VREF_SELECTION == AVCC_REF
        SET_BIT(ADMUX, 6);
        CLR_BIT(ADMUX, 7);
    #elif ADC_VREF_SELECTION == INTERNAL_2_56V_REF
        SET_BIT(ADMUX, 6);
        SET_BIT(ADMUX, 7);
    #elif ADC_VREF_SELECTION == AREF_REF
        CLR_BIT(ADMUX, 6);
        CLR_BIT(ADMUX, 7);
    #endif

// Select Result Adjustment 
    #if ADC_ADJUSTMENT == LEFT_ADJUSTMENT
        SET_BIT(ADMUX, 5);
    #elif ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
        CLR_BIT(ADMUX, 5);
    #endif

    /* Select Prescaler */
    ADCSRA &= 0xF8; 
    ADCSRA |= (ADC_PRESCALER & 0x07);

    /* Enable ADC */
    SET_BIT(ADCSRA, 7);
}

void ADC_voidEnable(void)
{
    SET_BIT(ADCSRA, 7);
}

void ADC_voidDisable(void)
{
    CLR_BIT(ADCSRA, 7);
}

void ADC_voidStartConversion(u8 u8Channel)
{
    /* Select Channel */
    ADMUX &= 0xE0;
    ADMUX |= (u8Channel & 0x1F);

    /* Start Conv*/
    SET_BIT(ADCSRA, 6);
}

u16 ADC_u16ReadSynchronous(u8 u8Channel)
{
    u32 u32Counter = 0;
    u16 u16DigitalResult = 0;

    /* Select Channel*/
    ADMUX &= 0xE0;
    ADMUX |= (u8Channel & 0x1F);

    /* Start Conv */
    SET_BIT(ADCSRA, 6);

    /* Polling*/
    while((GET_BIT(ADCSRA, 4) == 0) && (u32Counter < ADC_TIMEOUT))
    {
        u32Counter++;
    }

    SET_BIT(ADCSRA, 4);

    /* Read Result */
    #if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
        u16DigitalResult = ADC_DATA; // 10-bit 
    #elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
        u16DigitalResult = ADCH;     // 8-bit
    #endif

    return u16DigitalResult;
}

void ADC_voidReadAsynchronous(u8 u8Channel, pf pfNotificationFunc)
{
    if(pfNotificationFunc != NULL)
    {
        /* Save Callback Address */
        ADC_pvCallBackFunc = pfNotificationFunc;

        /* Enable ADC Interrupt */
        SET_BIT(ADCSRA, 3);

        /* START CONV */
        ADC_voidStartConversion(u8Channel);
    }
}

void ADC_voidInterruptEnable(void)
{
    SET_BIT(ADCSRA, 3);
}

void ADC_voidInterruptDisable(void)
{
    CLR_BIT(ADCSRA, 3);
}

void ADC_voidSetCallBack(pf pfFunctionAddress)
{
    if(pfFunctionAddress != NULL)
    {
        ADC_pvCallBackFunc = pfFunctionAddress;
    }
}

/* ADC ISR */
void __vector_16 (void) __attribute__((signal, used));
void __vector_16 (void)
{
    if(ADC_pvCallBackFunc != NULL)
    {
        ADC_pvCallBackFunc();
    }
}
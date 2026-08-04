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

/* Global pointer to hold the application callback function address */
static pf ADC_pvCallBackFunc = NULL;

void ADC_voidInit(void)
{
    /* 1. Select Reference Voltage */
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

    /* 2. Select Result Adjustment */
    #if ADC_ADJUSTMENT == LEFT_ADJUSTMENT
        SET_BIT(ADMUX, 5);
    #elif ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
        CLR_BIT(ADMUX, 5);
    #endif

    /* 3. Select Clock Prescaler */
    ADCSRA &= 0xF8; // Clear prescaler bits
    ADCSRA |= (ADC_PRESCALER & 0x07);

    /* 4. Enable ADC Hardware Peripheral */
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
    /* Select Channel (Bits 0..4 in ADMUX) */
    ADMUX &= 0xE0;
    ADMUX |= (u8Channel & 0x1F);

    /* Start Conversion */
    SET_BIT(ADCSRA, 6);
}

u16 ADC_u16ReadSynchronous(u8 u8Channel)
{
    u32 u32Counter = 0;
    u16 u16DigitalResult = 0;

    /* Select Channel */
    ADMUX &= 0xE0;
    ADMUX |= (u8Channel & 0x1F);

    /* Start Conversion */
    SET_BIT(ADCSRA, 6);

    /* Polling until Conversion Complete Flag is set or Timeout occurs */
    while((GET_BIT(ADCSRA, 4) == 0) && (u32Counter < ADC_TIMEOUT))
    {
        u32Counter++;
    }

    /* Clear Flag by writing 1 to it */
    SET_BIT(ADCSRA, 4);

    /* Read Result */
    #if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
        u16DigitalResult = ADC_DATA; // Read 10-bit value
    #elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
        u16DigitalResult = ADCH;     // Read 8-bit value
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

        /* Select Channel and Start Conversion */
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

/* ADC Interrupt Service Routine (Vector 16 for ATmega32 ADC) */
void __vector_16 (void) __attribute__((signal, used));
void __vector_16 (void)
{
    if(ADC_pvCallBackFunc != NULL)
    {
        ADC_pvCallBackFunc();
    }
}
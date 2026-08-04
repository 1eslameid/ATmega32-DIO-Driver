/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : TIM0 PROGRAM FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM0_Private.h"
#include "TIM0_Config.h"
#include "TIM0_Interface.h"




/*******************************************************************************
 *                      Functions Implementation                               *
 *******************************************************************************/

static pf TIM0_pvOVFCallBackFunc  = NULL;
static pf TIM0_pvCOMPCallBackFunc = NULL;

void TIM0_voidInit(void)
{
	#if TIM0_MODE == TIM0_NORMAL_MODE
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);

	#elif TIM0_MODE == TIM0_CTC_MODE
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);

	#elif TIM0_MODE == TIM0_FAST_PWM_MODE
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);

	#if FAST_PWM_MODE == TIM0_PWM_NON_INVERTING
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
	#elif FAST_PWM_MODE == TIM0_PWM_INVERTING
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
	#elif FAST_PWM_MODE == TIM0_PWM_DISCONNECTED
	CLR_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
	#endif
	#endif

	CLR_BIT(TIMSK, TOIE0);
	CLR_BIT(TIMSK, OCIE0);

	SET_BIT(TIFR, TOV0);
	SET_BIT(TIFR, OCF0);

	TCNT0 = 0x00;
	OCR0  = 0x00;

	TCCR0 = (TCCR0 & 0xF8) | (TIM0_PRESCALER & 0x07);
}

void TIM0_voidDisable(void)
{
	TCCR0 &= 0xF8;
}

/* Normal Mode */

void TIM0_voidEnableOVInterrupt(void)
{
	SET_BIT(TIMSK, TOIE0);
}

void TIM0_voidDisableOVInterrupt(void)
{
	CLR_BIT(TIMSK, TOIE0);
}

void TIM0_voidSetPreloadReg(u8 u8PreloadValue)
{
	TCNT0 = u8PreloadValue;
}

u8 TIM0_u8ReadTimerReg(void)
{
	return TCNT0;
}

void TIM0_voidOVSetCallBack(pf pvOVFunctionAddress)
{
	if (pvOVFunctionAddress != NULL)
	{
		TIM0_pvOVFCallBackFunc = pvOVFunctionAddress;
	}
}

/* CTC Mode */

void TIM0_voidEnableCOMPInterrupt(void)
{
	SET_BIT(TIMSK, OCIE0);
}

void TIM0_voidDisableCOMPInterrupt(void)
{
	CLR_BIT(TIMSK, OCIE0);
}

void TIM0_voidSetCompareReg(u8 u8CompareValue)
{
	OCR0 = u8CompareValue;
}

void TIM0_voidCOMPSetCallBack(pf pvCOMPFunctionAddress)
{
	if (pvCOMPFunctionAddress != NULL)
	{
		TIM0_pvCOMPCallBackFunc = pvCOMPFunctionAddress;
	}
}

/* Fast PWM Mode */

void TIM0_voidGeneratePWM(u8 u8DutyCycle)
{
	#if FAST_PWM_MODE == TIM0_PWM_NON_INVERTING
	OCR0 = (u8)(((u16)u8DutyCycle * 255) / 100);
	#elif FAST_PWM_MODE == TIM0_PWM_INVERTING
	OCR0 = 255 - (u8)(((u16)u8DutyCycle * 255) / 100);
	#endif
}

/* ISRs */

void __vector_10 (void) __attribute__ ((signal, used));
void __vector_10 (void)
{
	if (TIM0_pvCOMPCallBackFunc != NULL)
	{
		TIM0_pvCOMPCallBackFunc();
	}
}

void __vector_11 (void) __attribute__ ((signal, used));
void __vector_11 (void)
{
	if (TIM0_pvOVFCallBackFunc != NULL)
	{
		TIM0_pvOVFCallBackFunc();
	}
}
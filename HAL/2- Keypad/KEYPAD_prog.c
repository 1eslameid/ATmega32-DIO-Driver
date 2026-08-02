/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : KEYPAD_PROG.C                                */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#define  F_CPU 16000000UL
#include <util/delay.h>
/* 1. LIB Layer */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/* 2. MCAL Layer */
#include "DIO_interface.h"
/* 3. HAL Layer */
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"
/*********************************************************************/
/*                      Functions Implementation                     */
/*********************************************************************/
void KEYPAD_voidInit(void){
	// ROWS AS AN OUTPUTS
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_R0_PIN,OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_R1_PIN,OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_R2_PIN,OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_R3_PIN,OUTPUT);
	
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R0_PIN,HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R1_PIN,HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R2_PIN,HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R3_PIN,HIGH);
	
	// COULUMNS AS AN INPUTS
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_C0_PIN,INPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_C1_PIN,INPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_C2_PIN,INPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_C3_PIN,INPUT);
	
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_C0_PIN,HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_C1_PIN,HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_C2_PIN,HIGH);
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_C3_PIN,HIGH);
}

u8 KEYPAD_u8GetPressedKey(void){
	u8 local_u8PressedKey = KEYPAD_NO_PRESSED_KEY;
	static u8 local_u8IsPressedKey =0;
	
	
	// R0 IS ON
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R0_PIN,LOW);
	if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C0_PIN)== LOW){local_u8PressedKey='7';}
	else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C1_PIN)== LOW){local_u8PressedKey='8';}
	else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C2_PIN)== LOW){local_u8PressedKey='9';}
	else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C3_PIN)== LOW){local_u8PressedKey='/';}
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R0_PIN,HIGH);
	

	if(local_u8PressedKey == KEYPAD_NO_PRESSED_KEY){
		// R1 IS ON
		DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R1_PIN,LOW);
		if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C0_PIN)== LOW){local_u8PressedKey='4';}
		else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C1_PIN)== LOW){local_u8PressedKey='5';}
		else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C2_PIN)== LOW){local_u8PressedKey='6';}
		else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C3_PIN)== LOW){local_u8PressedKey='*';}
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R1_PIN,HIGH);}


	if(local_u8PressedKey == KEYPAD_NO_PRESSED_KEY){
		// R2 IS ON
		DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R2_PIN,LOW);

		if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C0_PIN)== LOW){local_u8PressedKey='1';}
		else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C1_PIN)== LOW){local_u8PressedKey='2';}
		else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C2_PIN)== LOW){local_u8PressedKey='3';}
		else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C3_PIN)== LOW){local_u8PressedKey='-';}
		DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R2_PIN,HIGH);}


	if(local_u8PressedKey == KEYPAD_NO_PRESSED_KEY){
		// R3 IS ON
		DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R3_PIN,LOW);

		if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C0_PIN)== LOW){local_u8PressedKey='#';}
		else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C1_PIN)== LOW){local_u8PressedKey='0';}
		else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C2_PIN)== LOW){local_u8PressedKey='=';}
		else if(DIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_C3_PIN)== LOW){local_u8PressedKey='+';}
	DIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_R3_PIN,HIGH);}

	if(local_u8PressedKey != KEYPAD_NO_PRESSED_KEY)
	{
		if(local_u8IsPressedKey == 0)
		{
			local_u8IsPressedKey = 1;
			_delay_ms(50);
			return local_u8PressedKey;
		}
		else
		{
			return KEYPAD_NO_PRESSED_KEY;
		}
	}
	else
	{
		_delay_ms(10);
		local_u8IsPressedKey = 0;
		return KEYPAD_NO_PRESSED_KEY;
	}
}



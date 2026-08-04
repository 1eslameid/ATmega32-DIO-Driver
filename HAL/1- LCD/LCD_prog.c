/*********************************************************************/
/*********************************************************************/
/******************   Author  : Eslam Eid            ****************/
/******************   Layer   : HAL                  ****************/
/******************   SWC     : LCD                  ****************/
/******************   Version : 1.00                 ****************/
/*********************************************************************/
/*********************************************************************/

#define F_CPU 16000000UL
#include <util/delay.h>

/* 1. LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* 2. MCAL Layer */
#include "DIO_interface.h"

/* 3. HAL Layer */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

/*********************************************************************/
/*                      Functions Implementation                     */
/*********************************************************************/

void LCD_voidInit(void)
{
    /* 1. Set Pins Direction to OUTPUT */
    DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT);

    /* 2. Initialization Sequence */
    _delay_ms(30);
    LCD_voidSendCommand(LCD_FUNCTIONSET_8BIT); 
    _delay_ms(1);
    LCD_voidSendCommand(LCD_DISPLAYON); 
    _delay_ms(1);
    LCD_voidSendCommand(LCD_CLEAR); 
    _delay_ms(2);
    LCD_voidSendCommand(LCD_ENTRY_MODE);
}

void LCD_voidSendCommand(u8 u8Command)
{
    /* RS = 0 (Command Mode) */
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
    
    /* Put Command on Data Bus */
    LCD_voidPutonBus(u8Command);
}

void LCD_voidSendData(u8 u8Data)
{
    /* RS = 1 (Data Mode) */
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
    
    /* Put Data on Data Bus */
    LCD_voidPutonBus(u8Data);
}

void LCD_GotoXY(u8 x, u8 y)
{
    u8 Local_u8Address = 0;

    if (x == 0)
    {
        Local_u8Address = LCD_SETCURSOR + y;       // 0x80 + y
    }
    else if (x == 1)
    {
        Local_u8Address = LCD_SETCURSOR + 0x40 + y; // 0xC0 + y
    }

    LCD_voidSendCommand(Local_u8Address);
}

void LCD_voidWriteString(u8 * u8string)
{
    while (*u8string != '\0')
    {
        LCD_voidSendData(*u8string);
        u8string++;
    }
}

void LCD_voidWriteNumber(u32 u32Number)
{
    u32 Local_u32Reversed = 1;

    if (u32Number == 0)
    {
        LCD_voidSendData('0');
        return;
    }

    /* Reverse the number to print digits from left to right */
    while (u32Number != 0)
    {
        Local_u32Reversed = (Local_u32Reversed * 10) + (u32Number % 10);
        u32Number /= 10;
    }

    /* Send reversed digits to LCD */
    while (Local_u32Reversed != 1)
    {
        LCD_voidSendData((Local_u32Reversed % 10) + '0');
        Local_u32Reversed /= 10;
    }
}

static void LCD_voidPutonBus(u8 u8Value)
{
    /* RW = 0 (Write Mode) */
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);

    /* Send Byte to Data Port */
    DIO_voidSetPortValue(LCD_DATA_PORT, u8Value);
    
    /* Enable Pulse */
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
    _delay_ms(2);
    DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}
/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : DIO_program.c                                   */
/* Description ............ : Program Implementation File for DIO Driver      */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

/* ========================================================================== */
/*                                Includes                                    */
/* ========================================================================== */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/* ========================================================================== */
/*                          Function Implementations                          */
/* ========================================================================== */

void DIO_voidInit(void)
{
    DDRA = DIO_PORTA_DIR;
    DDRB = DIO_PORTB_DIR;
    DDRC = DIO_PORTC_DIR;
    DDRD = DIO_PORTD_DIR;
}

void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction)
{
    if ((PortID <= PORT_D) && (PinID <= PIN7))
    {
        if (Direction == OUTPUT)
        {
            switch (PortID)
            {
                case PORT_A: SET_BIT(DDRA, PinID); break;
                case PORT_B: SET_BIT(DDRB, PinID); break;
                case PORT_C: SET_BIT(DDRC, PinID); break;
                case PORT_D: SET_BIT(DDRD, PinID); break;
            }
        }
        else if (Direction == INPUT)
        {
            switch (PortID)
            {
                case PORT_A: CLR_BIT(DDRA, PinID); break;
                case PORT_B: CLR_BIT(DDRB, PinID); break;
                case PORT_C: CLR_BIT(DDRC, PinID); break;
                case PORT_D: CLR_BIT(DDRD, PinID); break;
            }
        }
    }
}

void DIO_voidSetPinValue(u8 PortID, u8 PinID, u8 Value)
{
    if ((PortID <= PORT_D) && (PinID <= PIN7))
    {
        if (Value == HIGH)
        {
            switch (PortID)
            {
                case PORT_A: SET_BIT(PORTA, PinID); break;
                case PORT_B: SET_BIT(PORTB, PinID); break;
                case PORT_C: SET_BIT(PORTC, PinID); break;
                case PORT_D: SET_BIT(PORTD, PinID); break;
            }
        }
        else if (Value == LOW)
        {
            switch (PortID)
            {
                case PORT_A: CLR_BIT(PORTA, PinID); break;
                case PORT_B: CLR_BIT(PORTB, PinID); break;
                case PORT_C: CLR_BIT(PORTC, PinID); break;
                case PORT_D: CLR_BIT(PORTD, PinID); break;
            }
        }
    }
}

u8 DIO_u8GetPinValue(u8 PortID, u8 PinID)
{
    u8 value = LOW;

    if ((PortID <= PORT_D) && (PinID <= PIN7))
    {
        switch (PortID)
        {
            case PORT_A: value = GET_BIT(PINA, PinID); break;
            case PORT_B: value = GET_BIT(PINB, PinID); break;
            case PORT_C: value = GET_BIT(PINC, PinID); break;
            case PORT_D: value = GET_BIT(PIND, PinID); break;
        }
    }

    return value;
}

void DIO_voidTogglePin(u8 PortID, u8 PinID)
{
    if ((PortID <= PORT_D) && (PinID <= PIN7))
    {
        switch (PortID)
        {
            case PORT_A: TOGGLE_BIT(PORTA, PinID); break;
            case PORT_B: TOGGLE_BIT(PORTB, PinID); break;
            case PORT_C: TOGGLE_BIT(PORTC, PinID); break;
            case PORT_D: TOGGLE_BIT(PORTD, PinID); break;
        }
    }
}

void DIO_voidSetPortDirection(u8 PortID, u8 Direction)
{
    if (PortID <= PORT_D)
    {
        switch (PortID)
        {
            case PORT_A: SET_BYTE(DDRA, Direction); break;
            case PORT_B: SET_BYTE(DDRB, Direction); break;
            case PORT_C: SET_BYTE(DDRC, Direction); break;
            case PORT_D: SET_BYTE(DDRD, Direction); break;
        }
    }
}

void DIO_voidSetPortValue(u8 PortID, u8 Value)
{
    if (PortID <= PORT_D)
    {
        switch (PortID)
        {
            case PORT_A: SET_BYTE(PORTA, Value); break;
            case PORT_B: SET_BYTE(PORTB, Value); break;
            case PORT_C: SET_BYTE(PORTC, Value); break;
            case PORT_D: SET_BYTE(PORTD, Value); break;
        }
    }
}
/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : GIE PROGRAM FILE                                */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_private.h"
#include "GIE_interface.h"

void GIE_voidEnable(void)
{
    /* Enable Global Interrupts by setting Bit 7 (I-bit) in SREG */
    SET_BIT(SREG, SREG_I);
}

void GIE_voidDisable(void)
{
    /* Disable Global Interrupts by clearing Bit 7 (I-bit) in SREG */
    CLR_BIT(SREG, SREG_I);
}
/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : DIO_interface.h                                 */
/* Description ............ : Interface Header File for DIO Driver            */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* ========================================================================== */
/*                             Ports Definitions                              */
/* ========================================================================== */

#define PORT_A                   0
#define PORT_B                   1
#define PORT_C                   2
#define PORT_D                   3

/* ========================================================================== */
/*                             Pins Definitions                               */
/* ========================================================================== */

#define PIN0                     0
#define PIN1                     1
#define PIN2                     2
#define PIN3                     3
#define PIN4                     4
#define PIN5                     5
#define PIN6                     6
#define PIN7                     7

/* ========================================================================== */
/*                        Direction & Value Definitions                       */
/* ========================================================================== */

#define OUTPUT                   1
#define INPUT                    0

#define HIGH                     1
#define LOW                      0

/* ========================================================================== */
/*                             Function Prototypes                            */
/* ========================================================================== */

/**
 * @brief  Initializes all DIO ports directions based on DIO_config.h static settings.
 * @param  None
 * @return None
 */
void DIO_voidInit(void);

/**
 * @brief  Sets the direction of a specific pin (INPUT or OUTPUT).
 * @param  PortID    : Target Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param  PinID     : Target Pin  (PIN0 to PIN7)
 * @param  Direction : Direction   (INPUT or OUTPUT)
 * @return None
 */
void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction);

/**
 * @brief  Sets the output value of a specific pin (HIGH or LOW).
 * @param  PortID : Target Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param  PinID  : Target Pin  (PIN0 to PIN7)
 * @param  Value  : Output Value(HIGH or LOW)
 * @return None
 */
void DIO_voidSetPinValue(u8 PortID, u8 PinID, u8 Value);

/**
 * @brief  Reads the input logic value of a specific pin.
 * @param  PortID : Target Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param  PinID  : Target Pin  (PIN0 to PIN7)
 * @return u8     : Returned Pin Value (HIGH or LOW)
 */
u8 DIO_u8GetPinValue(u8 PortID, u8 PinID);

/**
 * @brief  Toggles the output logic value of a specific pin.
 * @param  PortID : Target Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param  PinID  : Target Pin  (PIN0 to PIN7)
 * @return None
 */
void DIO_voidTogglePin(u8 PortID, u8 PinID);

/**
 * @brief  Sets the direction for an entire port at once.
 * @param  PortID    : Target Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param  Direction : Direction Value (0x00 to 0xFF)
 * @return None
 */
void DIO_voidSetPortDirection(u8 PortID, u8 Direction);

/**
 * @brief  Sets the output value for an entire port at once.
 * @param  PortID : Target Port (PORT_A, PORT_B, PORT_C, PORT_D)
 * @param  Value  : Output Value    (0x00 to 0xFF)
 * @return None
 */
void DIO_voidSetPortValue(u8 PortID, u8 Value);

#endif /* DIO_INTERFACE_H */
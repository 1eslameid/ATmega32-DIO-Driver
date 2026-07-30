/*********************************************************************/
/*********************************************************************/
/******************   Author  : Eslam Eid            ****************/
/******************   Layer   : HAL                  ****************/
/******************   SWC     : LCD                  ****************/
/******************   Version : 1.00                 ****************/
/*********************************************************************/
/*********************************************************************/

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/* ========================================================================= */
/*                               LCD Commands                                */
/* ========================================================================= */

#define LCD_CLEAR               0x01  // Replace all Characters with ASCII 'space'
#define LCD_HOME                0x02  // Return Cursor to first Position on First Line
#define LCD_ENTRY_MODE          0x06  // Increment cursor automatically
#define LCD_DISPLAYOFF          0x08  // Turn Display off
#define LCD_DISPLAYON           0x0C  // Turn Display on, Cursor off, Blink off
#define LCD_FUNCTION_RESET      0x30  // Reset LCD
#define LCD_FUNCTIONSET_8BIT    0x38  // 2 line Display, 5x7 font, 8-bit mode
#define LCD_SETCURSOR           0x80  // Set Cursor Position (Base Address for Row 0)

/* ========================================================================= */
/*                          Private Helper Functions                         */
/* ========================================================================= */

static void LCD_voidPutonBus(u8 u8Char);

#endif /* LCD_PRIVATE_H_ */
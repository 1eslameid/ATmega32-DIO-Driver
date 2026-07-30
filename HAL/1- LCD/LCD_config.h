/*********************************************************************/
/*********************************************************************/
/******************   Author  : Eslam Eid            ****************/
/******************   Layer   : HAL                  ****************/
/******************   SWC     : LCD                  ****************/
/******************   Version : 1.00                 ****************/
/*********************************************************************/
/*********************************************************************/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* ========================================================================= */
/*                         LCD Hardware Configurations                       */
/* ========================================================================= */

/* Data Port Options: PORT_A, PORT_B, PORT_C, PORT_D */
#define LCD_DATA_PORT       PORT_C

/* Control Port Options: PORT_A, PORT_B, PORT_C, PORT_D */
#define LCD_CTRL_PORT       PORT_D

/* Control Pins Options: PIN0 -> PIN7 */
#define LCD_RS_PIN          PIN0
#define LCD_RW_PIN          PIN1
#define LCD_EN_PIN          PIN2

#endif /* LCD_CONFIG_H_ */
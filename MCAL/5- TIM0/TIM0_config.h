/******************************************************************************/
/* Author ................. : Eslam Eid                                       */
/* File Name .............. : TIM0 CONFIG FILE                               */
/* Version ................ : V1.0                                            */
/* Target MCU ............. : ATmega32                                        */
/******************************************************************************/
#ifndef TIM0_CONFIG_H_
#define TIM0_CONFIG_H_

/*
 Select Timer 0 Mode:
  - TIM0_NORMAL_MODE
 - TIM0_CTC_MODE
 - TIM0_FAST_PWM_MODE
 */
#define TIM0_MODE        TIM0_NORMAL_MODE

/*
  Select Timer 0 Prescaler:
 - TIM0_NO_CLOCK
 - TIM0_PRESCALER_1
 - TIM0_PRESCALER_8
 - TIM0_PRESCALER_64
 - TIM0_PRESCALER_256
 - TIM0_PRESCALER_1024
  - TIM0_EXT_CLOCK_FALLING
  - TIM0_EXT_CLOCK_RISING
 */
#define TIM0_PRESCALER    TIM0_PRESCALER_64

/*
PWM MODES:
TIM0_PWM_DISCONNECTED     
TIM0_PWM_NON_INVERTING    
TIM0_PWM_INVERTING        
*/
#define FAST_PWM_MODE   TIM0_PWM_NON_INVERTING

#endif /* TIM0_CONFIG_H_ */
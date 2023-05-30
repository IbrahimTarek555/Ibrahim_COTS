/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: PWM_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file PWM_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the PWM service functions.
 * @version 1.00
 */

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

#define PWM_u8Timer1ChA		0u
#define PWM_u8Timer1ChB		1u

void PWM_voidSetFreq(uint8 Copy_u8Freq);
uint8 PWM_u8SetDuty(uint8 Copy_u8Timer1Ch, uint8 Copy_u8Duty);
void PWM_voidDisableChA(void);
void PWM_voidDisableChB(void);
void PWM_voidDisable(void);

#endif

/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: ULTSONIC_program.c	**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file ULTSONIC_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the ULTSONIC sensor module functions.
 * @version 1.00
 */

#include "STD_TYPES.h"
#include "DEFINES.h"

#include "TIMERS_interface.h"

#include "ULTSONIC_config.h"
#include "ULTSONIC_private.h"
#include "ULTSONIC_interface.h"



/*********************************************/
//#include "STD_TYPES.h"
//#include "LIBRARY_interface.h"
//
//#include "DIO_interface.h"
//#include "PORT_interface.h"
//#include "TIMERS_interface.h"
//#include "GIE_interface.h"
//#include "ADC_interface.h"
//#include "EXTI_interface.h"
//
//#include "CLCD_interface.h"
//
//#include "PWM_interface.h"
//#include "ICU_interface.h"
//#include "SCHED_interface.h"
//
//#include <util/delay.h>
//
//void Main_voidMeasureDistance(void);
//static uint16 Main_u16Reading1;
//static uint16 Main_u16Reading2;
//
///*It is the main*/
//void main(void)
//{
//	/*Peripherals Initialization*/
//	PORT_voidInit();
//	CLCD_voidInit();
//	GIE_voidEnable();
//	uint16 Local_u16Distance;
//
//	TIMER1_CFG_t Local_stTimer1;
//	Local_stTimer1.ClkSelect = TIMER1_u8SYS_CLK_BY_8;
//	Local_stTimer1.OCAMode = OC_DISCONNECTED;
//	Local_stTimer1.OCBMode = OC_DISCONNECTED;
//	Local_stTimer1.WGM = NORMAL_16_BITS;
//	TIMER1_u8Init(&Local_stTimer1);
//
//	TIMERS_u8IntEnable(TIMER1_CAPT);
//	TIMER1_u8SetInputCaptTriggerSrc(TIMER1_u8ICU_RISING_EDGE);
//	TIMERS_u8SetCallBack(TIMER1_CAPT, Main_voidMeasureDistance);
//
//	/*Super Loop*/
//	while(1)
//	{
//		_delay_ms(200);
//		CLCD_voidClearDisplay();
//		DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_HIGH);
//		_delay_ms(100);
//		DIO_u8SetPinValue(DIO_u8PORTC, DIO_u8PIN0, DIO_u8PIN_LOW);
//
//		while((Main_u16Reading1 == 0u) || (Main_u16Reading2 == 0u));
//		Local_u16Distance = Main_u16Reading2 - Main_u16Reading1;
//		CLCD_u8GoToXY(0, 0);
//		CLCD_voidSendDecimalNumber(Local_u16Distance);
//		Main_u16Reading1 = 0u;
//		Main_u16Reading2 = 0u;
//		TIMER1_u8SetInputCaptTriggerSrc(TIMER1_u8ICU_RISING_EDGE);
//	}
//}
//void Main_voidMeasureDistance(void)
//{
//	static uint8 Local_u8Counter = 0u;
//	if(Local_u8Counter == 0u)
//	{
//		TIMER1_u8SetInputCaptTriggerSrc(TIMER1_u8ICU_FALLING_EDGE);
//		Main_u16Reading1 = TIMER1_u16GetInputCaptValue();
//		Local_u8Counter++;
//	}
//	else if(Local_u8Counter == 1u)
//	{
//		Main_u16Reading2 = TIMER1_u16GetInputCaptValue();
//		Local_u8Counter = 0u;
//	}
//}

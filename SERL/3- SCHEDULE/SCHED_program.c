/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: SCHED_program.c		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file SCHED_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the SCHED service functions.
 * @version 1.00
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DEFINES.h"

#include "SCHED_interface.h"
#include "SCHED_config.h"
#include "SCHED_private.h"

#include "TIMERS_interface.h"

static void SCHED_voidCompISR(void);
static uint32 SCHED_u32CompEventCounter = 0u;
static void (*SCHED_pvFunction)(void) = NULL;
static uint8 SCHED_u8RepeatFlag;
static uint8 SCHED_u8BusyFlag = IDLE;

uint8 SCHED_u8ScheduleMs(uint32 Copy_u32Time, uint8 Copy_u8Repeat, void (*Copy_pvFunction)(void))
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;
	uint16 Local_u16CompareValue = 0u;
	TIMER1_CFG_t Local_stTimer1Cfg;
	uint8 Local_u8ErrorFounder = OK;

	/*Validate the pointer*/
	if(Copy_pvFunction != NULL)
	{
		/*Check if IDLE or not*/
		if(SCHED_u8BusyFlag == IDLE)
		{
			/*Inform that timer is busy now*/
			SCHED_u8BusyFlag = BUSY;

			/*Validate the argument Copy_u8Repeat*/
			if((Copy_u8Repeat == SCHED_u8ONCE) || (Copy_u8Repeat == SCHED_u8Repeat))
			{
				/*Move Copy_u8Repeat to be global*/
				SCHED_u8RepeatFlag = Copy_u8Repeat;

				/*Set the clock and compare value*/
				if((Copy_u32Time % 10000) == 0)
				{
					Local_stTimer1Cfg.ClkSelect = TIMER1_u8SYS_CLK_BY_64;
					Local_u16CompareValue = 1250;
					SCHED_u32CompEventCounter = Copy_u32Time / 10000;
				}
				else if((Copy_u32Time % 1000) == 0)
				{
					Local_stTimer1Cfg.ClkSelect = TIMER1_u8SYS_CLK_BY_64;
					Local_u16CompareValue = 125;
					SCHED_u32CompEventCounter = Copy_u32Time / 1000;
				}
				if((Copy_u32Time % 50) == 0)
				{
					Local_stTimer1Cfg.ClkSelect = TIMER1_u8SYS_CLK_BY_8;
					Local_u16CompareValue = 50000;
					SCHED_u32CompEventCounter = Copy_u32Time / 50;
				}
				else if((Copy_u32Time % 25) == 0)
				{
					Local_stTimer1Cfg.ClkSelect = TIMER1_u8SYS_CLK_BY_8;
					Local_u16CompareValue = 25000;
					SCHED_u32CompEventCounter = Copy_u32Time / 25;
				}
				else
				{
					Local_stTimer1Cfg.ClkSelect = TIMER1_u8SYS_CLK_BY_8;
					Local_u16CompareValue = 1000;
					SCHED_u32CompEventCounter = Copy_u32Time;
				}

				SCHED_pvFunction = Copy_pvFunction;

				Local_stTimer1Cfg.WGM = CTC_OCR1A;
				Local_stTimer1Cfg.OCAMode = OC_DISCONNECTED;
				Local_stTimer1Cfg.OCBMode = OC_DISCONNECTED;
				Local_u8ErrorFounder = TIMER1_u8Init(&Local_stTimer1Cfg);

				if(Local_u8ErrorFounder == OK)
				{
					TIMERS_u8SetCallBack(TIMER1_COMPA, SCHED_voidCompISR);
					TIMER1_voidSetCompValueChA(Local_u16CompareValue);
					TIMERS_u8IntEnable(TIMER1_COMPA);
				}
				else
				{
					Local_u8ErrorState = NOK;
				}
			}
			else
			{
				Local_u8ErrorState = NOK;
			}
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE_ERR;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}

void SCHED_voidCompISR(void)
{
	static uint32 Local_u32CompEventCounter = 0u;
	Local_u32CompEventCounter++;

	if(Local_u32CompEventCounter == SCHED_u32CompEventCounter)
	{
		if(SCHED_pvFunction != NULL)
		{
			SCHED_pvFunction();
		}
		else
		{
			/*Do nothing*/
		}
		Local_u32CompEventCounter = 0u;

		if(SCHED_u8RepeatFlag == SCHED_u8ONCE)
		{
			TIMERS_u8Disable(TIMER1);
			TIMERS_u8IntDisable(TIMER1_COMPA);
			SCHED_u8BusyFlag = IDLE;
		}
		else
		{
			/*Do nothing*/
		}
	}

}

uint8 SCHED_u8Disable(void)
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;

	if(SCHED_u8BusyFlag == BUSY)
	{
		TIMERS_u8Disable(TIMER1);
		TIMERS_u8IntDisable(TIMER1_COMPA);
		SCHED_u8BusyFlag = IDLE;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}

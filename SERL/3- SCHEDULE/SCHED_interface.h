/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: SCHED_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file SCHED_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the SCHED service functions.
 * @version 1.00
 */

#ifndef SCHED_INTERFACE_H_
#define SCHED_INTERFACE_H_

#define SCHED_u8ONCE	0u
#define SCHED_u8Repeat	1u

uint8 SCHED_u8ScheduleMs(uint32 Copy_u32Time, uint8 Copy_u8Repeat, void (*Copy_pvFunction)(void));
uint8 SCHED_u8Disable(void);

#endif

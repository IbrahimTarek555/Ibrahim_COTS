/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: DAC_program.c			**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file DAC_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the DAC module functions.
 * @version 1.00
 */

#include "STD_TYPES.h"
#include "DEFINES.h"
#include "LIBRARY_interface.h"

#include "DIO_interface.h"

#include "DAC_config.h"
#include "DAC_private.h"
#include "DAC_interface.h"


/**
 * @brief This function to set analog volt to 8 bit DAC pins.
 * @param Copy_u8Volt Analog volt to be the output of the DAC.
 * @param Copy_u8Port The port to which DAC pins are attached.
 * @return Error State.
 */
uint8 DAC_voidSetAnalogVolt(uint16 Copy_u8Volt, uint8 Copy_u8Port)
{
	/*Define Variables*/
	uint8 Local_u8ErrorState = OK;
	uint8 Local_u8DigitalBits = 0;

	/*Map from the analog volt to the required bits*/
	Local_u8DigitalBits = (uint8) LIBRARY_s32Mapping(0, 5000, 0, 255, Copy_u8Volt);

	/*Set the bits to the DIO pins attached with DAC*/
	switch(Copy_u8Port)
	{
	case DAC_u8DIO_PORTA: DIO_u8SetPortValue(DIO_u8PORTA, Copy_u8Volt);	break;
	case DAC_u8DIO_PORTB: DIO_u8SetPortValue(DIO_u8PORTB, Copy_u8Volt);	break;
	case DAC_u8DIO_PORTC: DIO_u8SetPortValue(DIO_u8PORTC, Copy_u8Volt);	break;
	case DAC_u8DIO_PORTD: DIO_u8SetPortValue(DIO_u8PORTD, Copy_u8Volt);	break;
	default: Local_u8ErrorState = NOK;	break;
	}

	/*Return Error State*/
	return Local_u8ErrorState;
}

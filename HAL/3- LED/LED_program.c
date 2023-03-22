/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: LED_program.c			**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/


#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LED_config.h"
#include "LED_private.h"
#include "LED_interface.h"

uint8 LED_u8On(const LED_t *Copy_pledtLEDInformation)
{
	uint8 Local_u8ErrorState = OK;

	/*Validate the pointer address*/
	if(Copy_pledtLEDInformation != NULL)
	{
		if(Copy_pledtLEDInformation -> Type == LED_u8ACTIVE_HIGH)
		{
			DIO_u8SetPinValue(Copy_pledtLEDInformation -> Port, Copy_pledtLEDInformation -> Pin, DIO_u8PIN_HIGH);
		}
		else if(Copy_pledtLEDInformation -> Type == LED_u8ACTIVE_LOW)
		{
			DIO_u8SetPinValue(Copy_pledtLEDInformation -> Port, Copy_pledtLEDInformation -> Pin, DIO_u8PIN_LOW);
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8 LED_u8Off(const LED_t *Copy_pledtLEDInformation)
{
	uint8 Local_u8ErrorState = OK;

	/*Validate the pointer address*/
	if(Copy_pledtLEDInformation != NULL)
	{
		if(Copy_pledtLEDInformation -> Type == LED_u8ACTIVE_HIGH)
		{
			DIO_u8SetPinValue(Copy_pledtLEDInformation -> Port, Copy_pledtLEDInformation -> Pin, DIO_u8PIN_LOW);
		}
		else if(Copy_pledtLEDInformation -> Type == LED_u8ACTIVE_LOW)
		{
			DIO_u8SetPinValue(Copy_pledtLEDInformation -> Port, Copy_pledtLEDInformation -> Pin, DIO_u8PIN_HIGH);
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8 LED_u8Toggle(const LED_t *Copy_pledtLEDInformation)
{
	uint8 Local_u8ErrorState = OK;

	/*Validate the pointer address*/
	if(Copy_pledtLEDInformation != NULL)
	{
		DIO_u8TogglePinValue(Copy_pledtLEDInformation -> Port, Copy_pledtLEDInformation -> Pin);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}



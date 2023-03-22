/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: LED_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_u8ACTIVE_HIGH	1u
#define LED_u8ACTIVE_LOW	2u

typedef struct LED_t
{
	uint8 Type;
	uint8 Port;
	uint8 Pin;
}LED_t;

uint8 LED_u8Off(const LED_t *Copy_pledtLEDInformation);

uint8 LED_u8On(const LED_t *Copy_pledtLEDInformation);

uint8 LED_u8Toggle(const LED_t *Copy_pledtLEDInformation);

#endif

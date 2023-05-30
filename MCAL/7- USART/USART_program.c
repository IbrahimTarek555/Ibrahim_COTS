/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: USART_program.c		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file USART_program.c
 * @author Ibrahim Tarek
 * @brief This file implements the USART module functions.
 * @version 1.00
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DEFINES.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"
#include "UART_register.h"


void USART_voidInit(void)
{
	/*Define Temporary Variable*/
	uint8 Local_u8TempUCSRC = 0u;

	CLR_BIT(UCSRA,UCSRA_U2X);

	/*Enable Receiver*/
	SET_BIT(UCSRB,UCSRB_RXEN);

	/*Enable Transmitter*/
	SET_BIT(UCSRB,UCSRB_TXEN);

	/*Data Character Size is 8 bits*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	/*Select the mode*/
	CLR_BIT(Local_u8TempUCSRC,UCSRC_UMSEL);

	/*Disable Parity*/
	CLR_BIT(Local_u8TempUCSRC,UCSRC_UPM0);
	CLR_BIT(Local_u8TempUCSRC,UCSRC_UPM1);

	/*1 Stop Bit*/
	CLR_BIT(Local_u8TempUCSRC,UCSRC_USBS);

	/*Select Data character size*/
	SET_BIT(Local_u8TempUCSRC,UCSRC_UCSZ0);
	SET_BIT(Local_u8TempUCSRC,UCSRC_UCSZ1);

	/*Mode Select for UCSRC Register to write on it*/
	SET_BIT(Local_u8TempUCSRC,UCSRC_URSEL);
	UCSRC = Local_u8TempUCSRC;

	/*Select Baud Rate*/
	UBRRL = 51u;
}

void USART_voidTransmit(uint8 Copy_u8Data)
{
	/*Polling until Transmit Buffer is ready*/
	while((GET_BIT(UCSRA,UCSRA_UDRE)) == 0);

	/*Set the transmit data*/
	UDR = Copy_u8Data;
}

uint8 USART_u8Receive(void)
{
	/*Polling until USART Receive Data in receive buffer*/
	while((GET_BIT(UCSRA,UCSRA_RXC)) == 0);

	/*Return UDR*/
	return UDR;
}

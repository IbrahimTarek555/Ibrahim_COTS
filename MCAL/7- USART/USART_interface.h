/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: USART_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file USART_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the USART module functions.
 * @version 1.00
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);
void USART_voidTransmit(uint8 Copy_u8Data);
uint8 USART_u8Receive(void);

#endif

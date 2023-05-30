/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: DAC_interface.h		**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

/**
 * @file DAC_interface.h
 * @author Ibrahim Tarek
 * @brief This file interfaces the DAC module functions.
 * @version 1.00
 */

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_

/*Copy_u8Port Selection*/
#define DAC_u8DIO_PORTA			0u
#define DAC_u8DIO_PORTB			1u
#define DAC_u8DIO_PORTC			2u
#define DAC_u8DIO_PORTD			3u

/**
 * @brief This function to set analog volt to 8 bit DAC pins.
 * @param Copy_u8Volt Analog volt to be the output of the DAC.
 * @param Copy_u8Port The port to which DAC pins are attached.
 * @return Error State.
 */
uint8 DAC_voidSetAnalogVolt(uint16 Copy_u8Volt, uint8 Copy_u8Port);

#endif

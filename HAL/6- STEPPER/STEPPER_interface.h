/*********************************************************************************/
/*********************************************************************************/
/**********************			Author: Ibrahim Tarek		**********************/
/**********************			File: STEPPER_interface.h	**********************/
/**********************			Version: 1.00				**********************/
/*********************************************************************************/
/*********************************************************************************/

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_


#define STEPPER_u8ROTATE_CW		1
#define STEPPER_u8ROTATE_CCW	2


typedef struct STEPPER_t
{
	uint8 Port;
	uint8 BluePin;
	uint8 PinkPin;
	uint8 YellowPin;
	uint8 OrangePin;
}STEPPER_t;


uint8 STEPPER_u8Rotate(const STEPPER_t *Copy_psteppertMotorInfo, uint8 Copy_u16Angle, uint8 Copy_u8Direction);


#endif

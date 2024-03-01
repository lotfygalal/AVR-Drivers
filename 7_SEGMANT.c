/*
* _7_SEGMANT.c
*
* Created: 3/1/2024 10:03:44 PM
*  Author: LOTFY
*/
#include "7_SEGMANT_Interface.h"
#include "7_SEGMANT_Cfg.h"
#include "Bit_Math.h"
#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Interface.h"

void Segmant_init()
{
	
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(COM1_PORT,COM1_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(COM2_PORT,COM2_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(COM3_PORT,COM3_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(COM4_PORT,COM4_PIN,DIO_PIN_OUTPUT);
}
void Segmant_print_num(u8 copy_u8num)
{
	switch (copy_u8num)
	{
		case(0):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
		break;
		case(1):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
		break;
		case(2):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
		break;
		case(3):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
		break;
		case(4):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
		break;
		case(5):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
		break;
		case(6):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
		break;
		case(7):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
		break;
		case(8):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
		break;
		case(9):
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
		break;
		
	}
}
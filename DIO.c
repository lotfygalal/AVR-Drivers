#include "StdTypes.h"
#include "MemMap.h"
#include "Bit_Math.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"



#ifndef	NULL
#define	NULL		(void *)0
#endif
/***********************************     *** Set Pin Direction ***     ****************************************/

void DIO_voidSetPinDirection            (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	volatile u8 *local_pu8DDR = NULL;
	u8 local_u8pinNumber = 0;
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8DDR = &DDRA;
		break;
		
		case DIO_PORTB:
		local_pu8DDR = &DDRB;
		break;
		
		case DIO_PORTC:
		local_pu8DDR = &DDRC;
		break;
		
		case DIO_PORTD:
		local_pu8DDR = &DDRD;
		break;
		
		default:
		return;
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{
		local_u8pinNumber = copy_u8PinId;
	}
	
	if(copy_u8PinDirection == DIO_PIN_INPUT)
	{
		CLR_BIT(*local_pu8DDR, local_u8pinNumber);
	}
	else if(copy_u8PinDirection == DIO_PIN_OUTPUT)
	{
		SET_BIT(*local_pu8DDR, local_u8pinNumber);
	}
}

/***********************************     *** Set Pin Value ***     ****************************************/
void DIO_voidSetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	volatile u8 *local_pu8Port = NULL;
	u8 local_u8pinNumber = 0;
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8Port = &PORTA;
		break;
		
		case DIO_PORTB:
		local_pu8Port = &PORTB;
		break;
		
		case DIO_PORTC:
		local_pu8Port = &PORTC;
		break;
		
		case DIO_PORTD:
		local_pu8Port = &PORTD;
		break;
		
		default:
		return;
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{
		local_u8pinNumber = copy_u8PinId;
	}
	
	if(copy_u8PinValue == DIO_PIN_LOW)
	{
		CLR_BIT(*local_pu8Port, local_u8pinNumber);
	}
	else if(copy_u8PinValue == DIO_PIN_HIGH)
	{
		SET_BIT(*local_pu8Port, local_u8pinNumber);
	}
}
/***********************************     *** GET Pin Value ***     ****************************************/

void DIO_voidGetPinValue                (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	volatile u8 *local_pu8PIN = NULL;
	u8 local_u8pinNumber = 0;
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8PIN = &PINA;
		break;
		
		case DIO_PORTB:
		local_pu8PIN = &PINB;
		break;
		
		case DIO_PORTC:
		local_pu8PIN = &PINC;
		break;
		
		case DIO_PORTD:
		local_pu8PIN = &PIND;
		break;
		
		default:
		return;
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{
		local_u8pinNumber = copy_u8PinId;
	}
	
	*copy_pu8PinValue = READ_BIT(*local_pu8PIN, local_u8pinNumber);
}
/***********************************     *** TOGGLE Pin Value ***     ****************************************/
void DIO_voidTogglePinValue             (u8 copy_u8PortId, u8 copy_u8PinId)
{
	volatile u8 *local_pu8Port = NULL;
	u8 local_u8pinNumber = 0;
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8Port = &PORTA;
		break;
		
		case DIO_PORTB:
		local_pu8Port = &PORTB;
		break;
		
		case DIO_PORTC:
		local_pu8Port = &PORTC;
		break;
		
		case DIO_PORTD:
		local_pu8Port = &PORTD;
		break;
		
		default:
		return;
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{
		local_u8pinNumber = copy_u8PinId;
	}
	
	TOG_BIT(*local_pu8Port, local_u8pinNumber);
}
/***********************************     *** ActivePinInPullUpResistance ***     ****************************************/

void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	volatile u8 *local_pu8Port = NULL;
	u8 local_u8pinNumber = 0;
	switch (copy_u8PortId)
	{
		case DIO_PORTA:
		local_pu8Port = &PORTA;
		break;
		
		case DIO_PORTB:
		local_pu8Port = &PORTB;
		break;
		
		case DIO_PORTC:
		local_pu8Port = &PORTC;
		break;
		
		case DIO_PORTD:
		local_pu8Port = &PORTD;
		break;
		
		default:
		return;
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{
		local_u8pinNumber = copy_u8PinId;
	}
	
	SET_BIT(*local_pu8Port, local_u8pinNumber);
}
/**************************************************************************     *** PORT ***     *******************************************************************************/
/***********************************     *** Set Port Direction ***     ****************************************/
void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection) {
	
	if (copy_u8PortId > PORTD) {
		return;
	}
	

	volatile u8 *direction_register;
	if (copy_u8PortId == PORTA) {
		direction_register = &DDRA;
		} else if (copy_u8PortId == PORTB) {
		direction_register = &DDRB;
		} else if (copy_u8PortId == PORTC) {
		direction_register = &DDRC;
		} else { // PORTD
		direction_register = &DDRD;
	}
	
	// Update the direction register for the entire port
	if (copy_u8PortDirection == DIO_PORT_OUTPUT) {
		*direction_register = 0xFF; // Set all pins as output
		} else {
		*direction_register = 0x00; // Set all pins as input
	}
}
/***********************************     *** Set Port VALUE ***     ****************************************/
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue) {

	if (copy_u8PortId > PORTD) {

		return;
	}

	volatile u8 *port_register;
	if (copy_u8PortId == PORTA) {
		port_register = &PORTA;
		} else if (copy_u8PortId == PORTB) {
		port_register = &PORTB;
		} else if (copy_u8PortId == PORTC) {
		port_register = &PORTC;
		} else {
		port_register = &PORTD;
	}

	// Set the value of the entire port
	*port_register = copy_u8PortValue;
}
/***********************************     *** Get Port Value ***     ****************************************/
void DIO_voidGetPortValue                (u8 copy_u8PortId, u8* copy_pu8PortValue)
{

	if (copy_u8PortId > PORTD || copy_pu8PortValue == NULL) {

		return;
	}


	volatile u8 *port_register;
	if (copy_u8PortId == PORTA) {
		port_register = &PORTA;
		} else if (copy_u8PortId == PORTB) {
		port_register = &PORTB;
		} else if (copy_u8PortId == PORTC) {
		port_register = &PORTC;
		} else {
		port_register = &PORTD;
	}

	// Read the value of the entire port
	*copy_pu8PortValue = *port_register;
}
/***********************************     *** Toggle Port Value ***     ****************************************/
void DIO_voidTogglePortValue(u8 copy_u8PortId)
{
	switch (copy_u8PortId) {
		case DIO_PORTA:
		PORTA ^= 0xFF;
		break;
		case DIO_PORTB:
		PORTB ^= 0xFF;
		break;
		case DIO_PORTC:
		PORTC ^= 0xFF;
		break;
		case DIO_PORTD:
		PORTD ^= 0xFF;
		break;
	}
}
/***********************************     ***Active Port In PullUp Resistanc ***     ****************************************/
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	if (copy_u8PortId > PORTD) {

		return;
	}

	volatile u8 *port_register;
	if (copy_u8PortId == PORTA) {
		port_register = &PORTA;
		} else if (copy_u8PortId == PORTB) {
		port_register = &PORTB;
		} else if (copy_u8PortId == PORTC) {
		port_register = &PORTC;
		} else { 
		port_register = &PORTD;
	}

	// Activate pull-up resistors for the entire port
	*port_register |= 0xFF;
}

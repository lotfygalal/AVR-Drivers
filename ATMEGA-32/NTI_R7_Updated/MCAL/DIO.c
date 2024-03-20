/************************************************************************/
/*                  Digital Input Output Driver                         */
/*					AVR - ATMEGA32										*/
/*					How to use this driver:								*/
/*						- Include DIO_interface.h						*/
/*						- Use APIs according to its description			*/
/************************************************************************/
#include "All_Utiles.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"


/***********************************     *** INITIALIZATION ALL PINS ***     ****************************************/
void DIO_voidInit(void)
{
	DIO_Pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_voidInitPin(i,DIO_PinsStatusArray[i]);	
	}
}
/***********************************     *** INITIALIZATION SPECIFIED PINS ***     ****************************************/
static void DIO_voidInitPin	(DIO_Pin_type copy_u8PinId , DIO_PinStatus_type status)
{
	u8 copy_u8PinNum = copy_u8PinId %8 ;   //r=0-7
	DIO_Port_type copy_u8PortId =copy_u8PinId /8 ; //r=0-3
	switch (status)
	{
		case OUTPUT:
		switch (copy_u8PortId)
		{
			case PA:
			SET_BIT(DDRA,copy_u8PinNum);
			CLR_BIT(PORTA,copy_u8PinNum);
			break;
			case PB:
			SET_BIT(DDRB,copy_u8PinNum);
			CLR_BIT(PORTB,copy_u8PinNum);
			break;
			case PC:
			SET_BIT(DDRC,copy_u8PinNum);
			CLR_BIT(PORTC,copy_u8PinNum);
			break;
			case PD:
			SET_BIT(DDRD,copy_u8PinNum);
			CLR_BIT(PORTD,copy_u8PinNum);
			break;
		}
		break;
		case INFREE:
		switch (copy_u8PortId)
		{
			case PA:
			CLR_BIT(DDRA,copy_u8PinNum);
			CLR_BIT(PORTA,copy_u8PinNum);
			break;
			case PB:
			CLR_BIT(DDRB,copy_u8PinNum);
			CLR_BIT(PORTB,copy_u8PinNum);
			break;
			case PC:
			CLR_BIT(DDRC,copy_u8PinNum);
			CLR_BIT(PORTC,copy_u8PinNum);
			break;
			case PD:
			CLR_BIT(DDRD,copy_u8PinNum);
			CLR_BIT(PORTD,copy_u8PinNum);
			break;
		}
		break;
		case INPULL:
		switch (copy_u8PortId)
		{
			case PA:
			CLR_BIT(DDRA,copy_u8PinNum);
			SET_BIT(PORTA,copy_u8PinNum);
			break;
			case PB:
			CLR_BIT(DDRB,copy_u8PinNum);
			SET_BIT(PORTB,copy_u8PinNum);
			break;
			case PC:
			CLR_BIT(DDRC,copy_u8PinNum);
			SET_BIT(PORTC,copy_u8PinNum);
			break;
			case PD:
			CLR_BIT(DDRD,copy_u8PinNum);
			SET_BIT(PORTD,copy_u8PinNum);
			break;
		}
		break;
	}
}
/***********************************     *** Write On Pin ***     ****************************************/
void DIO_voidWritePin(DIO_Pin_type copy_u8PinId,DIO_Voltage_type copy_u8Volt)
{
	u8 copy_u8PinNum = copy_u8PinId %8 ;   //r=0-7
	DIO_Port_type copy_u8PortId =copy_u8PinId /8 ; //r=0-3
	if (copy_u8Volt==HIGH)
	{
		switch (copy_u8PortId)
		{
			case PA:
			SET_BIT(PORTA,copy_u8PinNum);
			break;
			case PB:
			SET_BIT(PORTB,copy_u8PinNum);
			break;
			case PC:
			SET_BIT(PORTC,copy_u8PinNum);
			break;
			case PD:
			SET_BIT(PORTD,copy_u8PinNum);
			break;
		}
	}
	else
	{
		switch (copy_u8PortId)
		{
			case PA:
			CLR_BIT(PORTA,copy_u8PinNum);
			break;
			case PB:
			CLR_BIT(PORTB,copy_u8PinNum);
			break;
			case PC:
			CLR_BIT(PORTC,copy_u8PinNum);
			break;
			case PD:
			CLR_BIT(PORTD,copy_u8PinNum);
			break;
		}
	}
}
/***********************************     *** Read From Pin ***     ****************************************/
DIO_Voltage_type DIO_ReadPin(DIO_Pin_type copy_u8PinId)
{
	u8 copy_u8PinNum = copy_u8PinId %8 ;   //r=0-7
	DIO_Port_type copy_u8PortId =copy_u8PinId /8 ; //r=0-3
	DIO_Voltage_type copy_u8Volt=LOW;
	switch (copy_u8PortId)
	{
		case PA:
		copy_u8Volt=READ_BIT(PINA,copy_u8PinNum);
		break;
		case PB:
		copy_u8Volt=READ_BIT(PINB,copy_u8PinNum);
		break;
		case PC:
		copy_u8Volt=READ_BIT(PINC,copy_u8PinNum);
		break;
		case PD:
		copy_u8Volt=READ_BIT(PIND,copy_u8PinNum);
		break;
	}
	return copy_u8Volt;
}
/***********************************     *** Toggle On Pin ***     ****************************************/
void DIO_voidTogglePin(DIO_Pin_type copy_u8PinId)
{
	u8 copy_u8PinNum = copy_u8PinId %8 ;   //r=0-7
	DIO_Port_type copy_u8PortId =copy_u8PinId /8 ; //r=0-3
	switch (copy_u8PortId)
	{
		case PA:
		TOG_BIT(PORTA,copy_u8PinNum);
		break;
		case PB:
		TOG_BIT(PORTB,copy_u8PinNum);
		break;
		case PC:
		TOG_BIT(PORTC,copy_u8PinNum);
		break;
		case PD:
		TOG_BIT(PORTD,copy_u8PinNum);
		break;
	}
}
void DIO_voidActivePinInPullUpResistance(DIO_Port_type copy_u8PortId, DIO_Pin_type copy_u8PinId)
{
	volatile u8 *local_pu8Port = NULL;
	switch (copy_u8PortId)
	{
		case PA:
		local_pu8Port = &PORTA;
		break;
		
		case PB:
		local_pu8Port = &PORTB;
		break;
		
		case PC:
		local_pu8Port = &PORTC;
		break;
		
		case PD:
		local_pu8Port = &PORTD;
		break;
		default:
		while (1){}		// For debugging
	}
	
	if (copy_u8PinId >= 0 && copy_u8PinId <= 7)
	{
		SET_BIT(*local_pu8Port, copy_u8PinId);
	}
	else
	{
		while (1){}		// For debugging
	}
}
/***********************************     *** Write On Port ***     ****************************************/
void DIO_voidWritePort(DIO_Port_type copy_u8PortId,u8 copy_u8PortValue)
{
	switch (copy_u8PortId)
	{
		case PA:
		PORTA=copy_u8PortValue;
		break;
		case PB:
		PORTB=copy_u8PortValue;
		break;
		case PC:
		PORTC=copy_u8PortValue;
		break;
		case PD:
		PORTD=copy_u8PortValue;
		break;
	}
}
/***********************************     *** Read From Port ***     ****************************************/
DIO_Voltage_type DIO_ReadPort(DIO_Port_type copy_u8PortId)
{
	u8 copy_pu8PortValue=LOW;
	switch (copy_u8PortId)
	{
		case PA:
		copy_pu8PortValue=PORTA;
		break;
		case PB:
		copy_pu8PortValue=PORTB;
		break;
		case PC:
		copy_pu8PortValue=PORTC;
		break;
		case PD:
		copy_pu8PortValue=PORTD;
		break;
	}
	return copy_pu8PortValue;
}

void DIO_voidTogglePort (DIO_Port_type copy_u8PortId)
{
	volatile u8 *local_pu8Port = NULL;
	
	switch (copy_u8PortId)
	{
		case PA:
		local_pu8Port = &PORTA;
		break;
		
		case PB:
		local_pu8Port = &PORTB;
		break;
		
		case PC:
		local_pu8Port = &PORTC;
		break;
		
		case PD:
		local_pu8Port = &PORTD;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	TOGGLE_REG(*local_pu8Port, 0xff);
}

void DIO_voidActivePortInPullUpResistance(DIO_Port_type copy_u8PortId)
{
	volatile u8 *local_pu8Port = NULL;
	
	switch (copy_u8PortId)
	{
		case PA:
		local_pu8Port = &PORTA;
		break;
		
		case PB:
		local_pu8Port = &PORTB;
		break;
		
		case PC:
		local_pu8Port = &PORTC;
		break;
		
		case PD:
		local_pu8Port = &PORTD;
		break;
		
		default:
		while (1){}		// For debugging
	}
	
	SET_REG(*local_pu8Port, 0xff);
}
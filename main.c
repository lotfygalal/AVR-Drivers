#include "StdTypes.h"
#include "MemMap.h"
#include "Bit_Math.h"
#include "DIO_Interface.h"

#define F_CPU 8000000
#include <util/delay.h>
int main(void)
{
	
DIO_voidSetPortDirection(DIO_PORTA,DIO_PORT_OUTPUT);
	while(1)
	{
		DIO_voidTogglePortValue(DIO_PORTA);
		_delay_ms(1000);
	}
}
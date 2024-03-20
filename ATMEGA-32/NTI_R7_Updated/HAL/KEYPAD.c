#define KEPAD_ARRAY 1
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "Utils.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Cfg.h"

void Keypad_voidInit(void)
{
	for (u8 i=0;i<ROWS;i++)
	{
		DIO_voidWritePin(FIRST_OUTPUT+i,HIGH);
	}
}
u8 Keypad_u8GetKey(void)
{
	u8 i,j,key=NO_KEY;                        //default no enter any key
	for (i=0;i<ROWS;i++)
	{
		DIO_voidWritePin(FIRST_OUTPUT+i,LOW);     //put (zero for first row) to show which pin get (zero in first column)
		for (j=0;j<COLS;j++)
		{
			if (DIO_ReadPin(FIRST_INPUT+j)==LOW)
			{
				key=KeysArray[i][j];
				_delay_ms(10);//debouncing
				while(DIO_ReadPin(FIRST_INPUT+j)==LOW);
			}
		}
		DIO_voidWritePin(FIRST_OUTPUT+i,HIGH);   //must return row high to see next row
	}
	return key;
}

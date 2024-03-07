#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "ADC_Interface.h"
#include "EX_Interrupt_Interface.h"


#define DELAY 3000
/*******************************************************************************************************************/
static volatile u8 flag=0;
static volatile u16 t1,t2;
int main(void)
{
	u16 digit;
	u16 analog;
	u16 temp;
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_256V,ADC_SCALER_128);
	
	while(1)
	{
		digit=ADC_Read(CH_1);
		analog = (u32)digit * 2560 / 1024;
		temp = analog / 10;
		LCD_WriteNumber(temp);
		temp = ((u32)digit * (2.56 * 1000)) / 1024;
		temp = ((u32)digit * ((u32)5 * 1000)) / 1024;
		LCD_WriteNumber(temp/10);
		
		_delay_ms(1000);
		LCD_Clear();
		
	}
}
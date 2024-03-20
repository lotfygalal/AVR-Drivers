
#include "All_Utiles.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"
#include "EXTI_Interface.h"
#include "TIMER0_Interface.h"
#include "PWM_Interface.h"
#include "SPI_Interface.h"
#include "MOTOR_Interface.h"
#include "SERVO_Interface.h"


int main(void)
{
	//u8 k;
	DIO_voidInit();
	//LCD_voidInit();
	//Keypad_voidInit();
	//LCD_voidGoToCell(LINE4,CELL19);
	//LCD_voidWriteString("T");
	
	/*MOTOR*/
	MOTOR_voidInit();
	//MOTOR_voidStartCCW();
	PWM_voidInitChannel_0();
	MOTOR_voidChangePWM(CW,1);
	
	/*SERVO*/
	PWM_voidInitChannel_1A();
	Servo_voidInit();
	Servo_void_ON();
	Servo_void_SetAngle(70);
	

    while (1) 
    {

		
		//k=Keypad_u8GetKey();
		//if (k!=NO_KEY)
		//{
			//LCD_voidGoToCell(LINE1,CELL0);
			//LCD_voidWriteChar(k);
		//}

    }
}


/*
* MOTOR.c
*
* Created: 3/17/2024 5:41:40 PM
*  Author: LOTFY
*/
#include "All_Utiles.h"
#include "DIO_interface.h"
#include "PWM_Interface.h"
#include "MOTOR_Cfg.h"
#include "MOTOR_Interface.h"




/***********************************     *** MOTOR INITIALIZATION ***     ****************************************/
void MOTOR_voidInit(void)
{
	// Go to configure motor pin @ DIO_Cfg & MOTOR_Cfg
}
void MOTOR_voidStartCW(void)
{
	DIO_voidWritePin(MOTOR_PIN_ENA,HIGH);
	DIO_voidWritePin(MOTOR_PIN_DIR,HIGH);
}
void MOTOR_voidStartCCW(void)
{
	DIO_voidWritePin(MOTOR_PIN_ENA,HIGH);
	DIO_voidWritePin(MOTOR_PIN_DIR,LOW);
}

void MOTOR_voidStop	(void)
{
	DIO_voidWritePin(MOTOR_PIN_ENA,LOW);
}

void MOTOR_voidChangePWM(MotorDir_type copy_enumMotorDir,u8 copy_pwmvalue)
{
	switch (copy_enumMotorDir)
	{
		case CW:
		 MOTOR_voidStartCW();
		break;
		
		case CCW:
		 MOTOR_voidStartCCW();
		break;
	}
	
	PWM_voidGenerate_PWM_Channel_0 (copy_pwmvalue);
}
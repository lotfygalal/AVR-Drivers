/*
 * SERVO.c
 *
 * Created: 3/18/2024 1:06:55 PM
 *  Author: LOTFY
 */ 
#include "All_Utiles.h"

#include "SERVO_Interface.h"
#include "DIO_Interface.h"
#include "PWM_Interface.h"

void Servo_voidInit(void)
{
	// Go to configure servo pin_output @ DIO_Cfg 
	//PIND5
}
void Servo_void_ON(void)
{
	PWM_voidInitChannel_1A();
}
void Servo_void_OFF(void)
{
	PWM_voidStopChannel_1A();
}
void Servo_void_SetAngle(u8 copy_u32SetAngle)
{
	static f32 angle=0; 
	angle=(((copy_u32SetAngle+90.0)/180.0)*5)+5;
	PWM_voidGenerate_PWM_Channel_1A(50,angle);
}
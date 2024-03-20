/*
 * PWM_Program.c
 *
 * Created: 3/17/2024 10:50:43 AM
 *  Author: LOTFY
 */ 
#include "All_Utiles.h"

#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "PWM_Cfg.h"


void PWM_voidInitChannel_0			(void)
{
	//select fast PWM mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	//select non-inverting mode
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0 ,COM01);
}

void PWM_voidGenerate_PWM_Channel_0 (u8 copy_u8DutyCycle)
{
	if (copy_u8DutyCycle<=100)
	{
		OCR0 =(((u16)copy_u8DutyCycle*256)/100)-1;		//((50*256)/100)-1 if duty=50% --> ocr0=127
		
		//select PRESCALER =64
		SET_BIT(TCCR0 ,CS00);
		SET_BIT(TCCR0 ,CS01);
		CLR_BIT(TCCR0 ,CS02);
	}
	else
	{
		//error
	}
}
void PWM_voidStopChannel_0			(void)
{
	CLR_BIT(TCCR0 ,CS00);
	CLR_BIT(TCCR0 ,CS01);
	CLR_BIT(TCCR0 ,CS02);
}

void PWM_voidInitChannel_1A			(void)
{
	//select fast PWM mode
	CLR_BIT(TCCR1A ,WGM10);
	SET_BIT(TCCR1A ,WGM11);
	SET_BIT(TCCR1B ,WGM12);
	SET_BIT(TCCR1B ,WGM13);
	
	//select non-inverting mode
	CLR_BIT(TCCR1A ,COM1A0);
	SET_BIT(TCCR1A ,COM1A1);
	
}
void PWM_voidGenerate_PWM_Channel_1A (u32 cop_u32Frequancy_Hz,f32 copy_f32DutyCycle)
{
	if (copy_f32DutyCycle<=100)
	{
		//select frequency
        ICR1 =((1000000/cop_u32Frequancy_Hz)/4)-1;		//tick time=4 micro
		
		//select PWM
		OCR1A =((copy_f32DutyCycle*(ICR1 +1))/100)-1;
		
		//select PRESCALER =64
		SET_BIT(TCCR1B ,CS10);
		SET_BIT(TCCR1B ,CS11);
		CLR_BIT(TCCR1B ,CS12);
	}
	else
	{
		//error
	}
		
}
void PWM_voidStopChannel_1A			(void)
{
	CLR_BIT(TCCR1B ,CS10);
	CLR_BIT(TCCR1B ,CS11);
	CLR_BIT(TCCR1B ,CS12);
}

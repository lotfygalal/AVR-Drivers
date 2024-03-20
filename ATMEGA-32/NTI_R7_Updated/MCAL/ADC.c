#include "All_Utiles.h"
#include "ADC_Interface.h"

static u8 ADC_BusyFlag; //To ensure that ADC is not busy for starting process.
/***********************************     *** ADC_Initilization ***     ****************************************/
void ADC_voidInit(ADC_VoltRef_type copy_enumMaxVoltage,ADC_Prescaler_type copy_enumPrescaler)
{
	/* vref*/
	switch(copy_enumMaxVoltage)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256V:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	/* Pre-scaler */
	ADCSRA&=0XF8;					//11111000
	copy_enumPrescaler&=0X07;      //00000111
	ADCSRA=ADCSRA|copy_enumPrescaler;
	
	/* enable ADC*/
	SET_BIT(ADCSRA,ADEN);
	
}
/***********************************     *** ADC Read By Blocking Way ***     ****************************************/
u16 ADC_voidReadDigitalVal(ADC_Channel_type copy_enumChannel)
{
	/* set channel mux*/
	ADMUX&=0XE0;      //11100000
	ADMUX|=copy_enumChannel;
	
	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
	
	/* wait ADC finish**/
	while(READ_BIT(ADCSRA,ADSC));
	
	return ADC;
}
/***********************************     *** ADC Read By polling Way ***     ****************************************/
/*start conversion*/
void ADC_voidStartConversion(ADC_Channel_type copy_enumChannel)
{
	if (ADC_BusyFlag==0)
	{
		/* set channel mux*/
		ADMUX&=0XE0;      //11100000
		ADMUX|=copy_enumChannel;
		
		/*start conversion*/
		SET_BIT(ADCSRA,ADSC);
		ADC_BusyFlag=1;
	}
}

/* Periodic Check (Polling) */

u8 ADC_u8GetReadPeriodic(u16 *copy_enumPeriodicData)
{
	if (!READ_BIT(ADCSRA,ADSC))
	{
		ADC_BusyFlag=1;
		*copy_enumPeriodicData=ADC;
		return 1;
	}
	return 0;
}

/*get ADC read*/

u16 ADC_u16GetRead(void)
{

	while(READ_BIT(ADCSRA,ADSC));
	return ADC;
}
/***********************************     *** ADC Read No Blocking ***     ****************************************/
u16 ADC_u16GetReadNoBlocking(void)
{
	return ADC;
}
/***********************************     *** ADC Volt Read ***     ****************************************/
u16 ADC_u16VoltRead(ADC_Channel_type copy_enumChannel)
{
	u16 volt;
	u16 adc;
	adc=ADC_voidReadDigitalVal(copy_enumChannel);
	volt=(adc*(u32)5000)/1023;      //1023 instead 1024 for max number 5000 instead 4999
	//5000 for vref=5*1000
	//cast for bigger number in calculation
	return volt;                    /* return mele-volt(mv)*/
}
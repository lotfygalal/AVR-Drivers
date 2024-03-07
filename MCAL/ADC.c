#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC_Interface.h"

static u8 ADC_BusyFlag; //To ensure that ADC is not busy for starting process.
/***********************************     *** ADC_Initilization ***     ****************************************/
void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler)
{
	/* vref*/
	switch(vref)
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
	ADCSRA&=0XF8;      //11111000
	scaler&=0X07;      //00000111
	ADCSRA=ADCSRA|scaler;
	
	/* enable ADC*/
	SET_BIT(ADCSRA,ADEN);
	
}
/***********************************     *** ADC Read By Blocking Way ***     ****************************************/
u16 ADC_Read(ADC_Channel_type CH)
{
	/* set channel mux*/
	ADMUX&=0XE0;      //11100000
	ADMUX|=CH;
	
	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
	
	/* wait ADC finish**/
	while(READ_BIT(ADCSRA,ADSC));
	
	/*get read*/
	//u16 adc=ADCL;
	//adc=adc|(ADCL<<8);
	
	/*if adle==1*/
	//u16 adc=ADCL>>6;
	//adc=adc|ADCH<<2;
	
	return ADC;
}
/***********************************     *** ADC Read By polling Way ***     ****************************************/
/*start conversion*/
void ADC_StartConversion(ADC_Channel_type CH)
{
	if (ADC_BusyFlag==0)
	{
		/* set channel mux*/
		ADMUX&=0XE0;      //11100000
		ADMUX|=CH;
		
		/*start conversion*/
		SET_BIT(ADCSRA,ADSC);
		ADC_BusyFlag=1;
	}
}
/* Periodic Check (Polling) */
u8 ADC_GetReadPeriodic(u16 *pdata)
{
	if (!READ_BIT(ADCSRA,ADSC))
	{
		ADC_BusyFlag=1;
		*pdata=ADC;
		return 1;
	}
	return 0;
}
/*get ADC read*/
u16 ADC_GetRead(void)
{
	/*get read*/
	//u16 adc=ADCL;
	//adc=adc|(ADCL<<8);
	
	/*if adle==1*/
	//u16 adc=ADCL>>6;
	//adc=adc|ADCH<<2;
	while(READ_BIT(ADCSRA,ADSC));
	return ADC;
}
/***********************************     *** ADC Read No Blocking ***     ****************************************/
u16 ADC_GetReadNoBlocking(void)
{
	return ADC;
}
/***********************************     *** ADC Volt Read ***     ****************************************/
u16 ADC_VoltRead(ADC_Channel_type CH)
{
	u16 volt;
	u16 adc;
	adc=ADC_Read(CH);
	volt=(adc*(u32)5000)/1023;      //1023 instead 1024 for max number 5000 instead 4999
	//5000 for vref=5*1000
	//cast for bigger number in calculation
	return volt;                    /* return melevolt(mv)*/
}
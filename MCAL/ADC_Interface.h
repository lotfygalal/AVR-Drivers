﻿#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/***********************************     *** ADC MUX SELECTION ***     ****************************************/
typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256V
}ADC_VoltRef_type;
/***********************************     *** ADC PRESCALER SELCTION ***     ****************************************/
typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,    //BEST for Atmeg32
	ADC_SCALER_128,
}ADC_Prescaler_type;

typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_type;


void ADC_Init(ADC_VoltRef_type vref,ADC_Prescaler_type scaler);
u16 ADC_Read(ADC_Channel_type CH);
void ADC_StartConversion(ADC_Channel_type CH);
u8 ADC_GetReadPeriodic(u16 *pdata);
u16 ADC_GetRead(void);
u16 ADC_GetReadNoBlocking(void);
u16 ADC_VoltRead(ADC_Channel_type CH); 




#endif /* ADC_INTERFACE_H_ */
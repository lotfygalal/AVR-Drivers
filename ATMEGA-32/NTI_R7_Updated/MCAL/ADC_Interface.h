#ifndef ADC_INTERFACE_H_
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


void ADC_voidInit(ADC_VoltRef_type copy_enumMaxVoltage,ADC_Prescaler_type copy_enumPrescaler);
u16 ADC_voidReadDigitalVal(ADC_Channel_type copy_enumChannel);
void ADC_voidStartConversion(ADC_Channel_type copy_enumChannel);
u8 ADC_u8GetReadPeriodic(u16 *copy_enumPeriodicData);
u16 ADC_u16GetRead(void);
u16 ADC_u16GetReadNoBlocking(void);
u16 ADC_u16VoltRead(ADC_Channel_type copy_enumChannel);








#endif /* ADC_INTERFACE_H_ */
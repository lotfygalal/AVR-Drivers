/*
 * EXT_Interface.h
 *
 * Created: 3/3/2024 12:59:44 PM
 *  Author: LOTFY
 */ 


#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_
typedef enum{
	EXTI_LOW_LEVEL=0,
	EXTI_ANY_LOGIC_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE
}EXTI_SenseControl_t;
typedef enum
{
	EXTI_INT0=0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_Source_t;

void EXTI_voidEnable (EXTI_Source_t copy_enumInterruptSource,EXTI_SenseControl_t copy_enumSenseControl);
void EXTI_voidDisable(EXTI_Source_t copy_enumInterruptSource);
void EXI_VoidSetCallBack(EXTI_Source_t copy_enumInterruptSource,void(*LocalPtr)(void));
//void EXI_VoidSetCallBackINT1(void(*LocalPtr)(void));



#endif /* EXT_INTERFACE_H_ */
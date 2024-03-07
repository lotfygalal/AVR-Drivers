#ifndef EX_INTERRUPT_INTERFACE_H_
#define EX_INTERRUPT_INTERFACE_H_
/***********************************     *** Global INTURRUBT ENABLE/DISABLE ***     ****************************************/
#define   GlobalINT_ENABLE     sei
#define   GlobalINT_DISABLE    cli
/***********************************     *** ENUM FOR TriggerEdge RAISING/FALLING***     ************************************/
typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}TriggerEdge_type;
/***********************************     *** ENUM FOR 3 INT_PINS ON AVR***     **********************************************/
typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;
/****************************************************************************************************************************/
void EXI_Init(void);
void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_Disable(ExInterruptSource_type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void));

#endif /* EX_INTERRUPT_INTERFACE_H_ */
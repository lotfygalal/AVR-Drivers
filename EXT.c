/*
* EXT.c
*
* Created: 3/3/2024 12:58:04 PM
*  Author: LOTFY
*/

#include "EXT_Interface.h"
#include "EXT_Private.h"

/****************************     *** Pointer to functions to be assigned to ISR ***     ******************************/
static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;




void EXTI_voidEnable(EXTI_Source_t copy_enumInterruptSource, EXTI_SenseControl_t copy_enumSenseControl)
{
	switch (copy_enumInterruptSource)
	{
		case EXTI_INT0:
		switch (copy_enumSenseControl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC00);
			SET_BIT(MCUCR_REG, ISC01);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG, ISC00);
			SET_BIT(MCUCR_REG, ISC01);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG, ISC00);
			CLR_BIT(MCUCR_REG, ISC01);
			break;
			
			case EXTI_ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR_REG, ISC00);
			CLR_BIT(MCUCR_REG, ISC01);
			break;
		}
		SET_BIT(GICR_REG, INT0);
		break;
		
		case EXTI_INT1:
		switch (copy_enumSenseControl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC10);
			SET_BIT(MCUCR_REG, ISC11);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG, ISC10);
			SET_BIT(MCUCR_REG, ISC11);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG, ISC10);
			CLR_BIT(MCUCR_REG, ISC11);
			break;
			
			case EXTI_ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR_REG, ISC10);
			CLR_BIT(MCUCR_REG, ISC11);
			break;
		}
		SET_BIT(GICR_REG, INT1);
		break;
		
		case EXTI_INT2:
		switch (copy_enumSenseControl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC2);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG, ISC2);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG, ISC10);
			CLR_BIT(MCUCR_REG, ISC11);
			break;
			
			case EXTI_ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR_REG, ISC10);
			CLR_BIT(MCUCR_REG, ISC11);
			break;
		}
		SET_BIT(GICR_REG, INT2);
		break;
	}
}
void EXTI_voidDisable(EXTI_Source_t copy_enumInterruptSource)
{
	switch(copy_enumInterruptSource){
		case EXTI_INT0:
		CLR_BIT(GICR_REG,INT0);
		break;
		case EXTI_INT1:
		CLR_BIT(GICR_REG,INT1);
		break;
		case EXTI_INT2:
		CLR_BIT(GICR_REG,INT2);
		break;
	}
}
void EXI_VoidSetCallBack(EXTI_Source_t copy_enumInterruptSource,void(*LocalPtr)(void))
{
	switch(copy_enumInterruptSource){
		case EXTI_INT0:
		INT0_Fptr=LocalPtr;
		break;
		case EXTI_INT1:
		INT1_Fptr=LocalPtr;
		break;
		case EXTI_INT2:
		INT2_Fptr=LocalPtr;
		break;
		
	}
}

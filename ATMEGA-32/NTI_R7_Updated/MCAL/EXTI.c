

/********************************************************************************************************/
/*                  External Interrupt Driver															*/
/*					AVR - ATMEGA32																		*/
/*					How to use this driver:																*/
/*						- Configure the EXTI pin as input or input pull up resistor	using DIO Driver	*/
/*						- Include EXTI_interface.h														*/
/*						- Configure the EXTI Source and Sense Control using EXTI_voidEnable API			*/
/*						- Set your callback function for a certain EXTI									*/
/*						- Enable the global interrupt using GI Driver									*/
/*						- Use APIs according to its description											*/
/********************************************************************************************************/

#include "All_Utiles.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"

/************************************************************************************************************************************/
/*			API Name: EXTI_voidEnable																								*/
/*			Parameters:																												*/
/*				- copy_enumInterruptSource	: determine the source of the interrupt INT0, INT1 or INT2 @ref INT_SRC_define			*/
/*				- copy_enumSenseControl		: determine the sense control of the interrupt falling, rising, any change or low level */
/*											  @ref INT_SENSE_CONTROL_define															*/
/*			Return: Void																											*/
/*			Description: This API is used to enable and configure the EXTI interrupt.												*/
/************************************************************************************************************************************/
void EXTI_voidEnable(EXTI_Source_t copy_enumInterruptSource, EXTI_SenseControl_t copy_enumSenseControl)
{
	switch (copy_enumInterruptSource)
	{
		case EXTI_INT0:					 
		switch (copy_enumSenseControl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR , ISC00);
			SET_BIT(MCUCR , ISC01);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR , ISC00);
			SET_BIT(MCUCR , ISC01);
			break;
			
			case EXTI_LOW_EDGE:
			CLR_BIT(MCUCR , ISC00);
			CLR_BIT(MCUCR , ISC01);
			break;
			
			case EXTI_ANY_CHANGE:
			SET_BIT(MCUCR , ISC00);
			CLR_BIT(MCUCR , ISC01);
			break;
			
			default:
			while(1) {} // for debug
		}		 
		SET_BIT(GICR , INT0);			 
		break;							 
										 
		case EXTI_INT1:					 
		switch (copy_enumSenseControl)	 
		{								 
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR , ISC10);
			SET_BIT(MCUCR , ISC11);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR , ISC10);
			SET_BIT(MCUCR , ISC11);
			break;
			
			case EXTI_LOW_EDGE:
			CLR_BIT(MCUCR , ISC10);
			CLR_BIT(MCUCR , ISC11);
			break;
			
			case EXTI_ANY_CHANGE:
			SET_BIT(MCUCR , ISC10);
			CLR_BIT(MCUCR , ISC11);
			break;
			
			default:
			while(1) {} // for debug	 
		}
		SET_BIT(GICR , INT1);			 
		break;							 
										 
		case EXTI_INT2:					 
		switch (copy_enumSenseControl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR , ISC2);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR , ISC2);
			break;
			
			case EXTI_LOW_EDGE:
			case EXTI_ANY_CHANGE:
			default:
			while(1) {} // for debug
		}								 
		SET_BIT(GICR , INT2);			 
		break;
		
		default:
		while(1) {} // for debug
	}
}

/************************************************************************************************************************************/
/*			API Name: EXTI_voidDisable																								*/
/*			Parameters:																												*/
/*				- copy_enumInterruptSource	: determine the source of the interrupt INT0, INT1 or INT2 @ref INT_SRC_define			*/
/*			Return: Void																											*/
/*			Description: This API is used to disable the EXTI interrupt.															*/
/************************************************************************************************************************************/
void EXTI_voidDisable(EXTI_Source_t copy_enumInterruptSource)
{
	switch (copy_enumInterruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR , INT0);
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR , INT1);
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR , INT2);
		break;
		
		default:
		while(1) {} // for debug
	}
}

/************************************************************************************************************************************/
/*			API Name: EXTI_voidSetCallBack																							*/
/*			Parameters:																												*/
/*				- copy_enumInterruptSource	: determine the source of the interrupt INT0, INT1 or INT2 @ref INT_SRC_define			*/
/*				- copy_pFunVoid				: a pointer to a function to set your callback function									*/
/*			Return: Void																											*/
/*			Description: This API is used to set your callback function to be called by ISR.										*/
/************************************************************************************************************************************/
void EXTI_voidSetCallBack(EXTI_Source_t copy_enumInterruptSource, void (*copy_pFunVoid)(void))
{
	if (copy_pFunVoid == NULL)
	{
		while(1) {} // for debug
	}
	
	switch (copy_enumInterruptSource)
	{
		case EXTI_INT0:
		PRV_pFunCallBackINTx[0] = copy_pFunVoid; 
		break;
		
		case EXTI_INT1:
		PRV_pFunCallBackINTx[1] = copy_pFunVoid;
		break;
		
		case EXTI_INT2:
		PRV_pFunCallBackINTx[2] = copy_pFunVoid;
		break;
		
		default:
		while(1) {} // for debug
	}
}
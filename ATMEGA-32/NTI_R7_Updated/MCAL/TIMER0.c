

#include "All_Utiles.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Cfg.h"
#include "TIMER0_Private.h"

static u16 PRV_CTC_Counter ;

void TMR0_voidInit	(void)
{
										//normal mode
	#if TMR0_MODE == TMR0_NORMAL_MODE

	
	/* WaveForm Generation */
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	
	/* PreLoad: TCNT0 */
	TCNT0 = TMR0_PRELOAD_VALUE;
	
	/* Enable Overflow Interrupt */
	SET_BIT(TIMSK, TOIE0);
	
										//CTC mode
	#elif TMR0_MODE == TMR0_CTC_MODE

	
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	
	SET_BIT(TIMSK,OCIE0);
	
	OCR0=TMR0_OUT_COMPARE_VALUE;
	#endif
}

void TMR0_voidStart	(void)
{
	/* PreScaler */
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
}

void TMR0_voidStop	(void)
{
	/* PreScaler */
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
}

void TMR0_voidSetCallBack(void (*copy_pFunAction)(void),u8 copy_u8InterruptSource)
{
	if (copy_pFunAction !=NULL)
	{
		switch(copy_u8InterruptSource)
		{
			case TMR0_NORMAL_OVER_FLOW:
			PRV_pfunCallBackOVF=copy_pFunAction;
			break;
			case TMR0_CTC_COMPARE_MATCH:
			PRV_pfunCallBackOC=copy_pFunAction;
			break;
			
		}
	}
}

void TMR0_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms)
{
	//under condition tick time = 4 micro sec
	OCR0=249; //default
	PRV_CTC_Counter =copy_u16Delay_ms;
	
}


void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 local_u16OVFCounter = 0;
	local_u16OVFCounter++;
	
	if(TMR0_OVER_FLOW_COUNTER == local_u16OVFCounter)
	{
		local_u16OVFCounter = 0;
		
		/* Call Action */
		if (NULL != PRV_pfunCallBackOVF)
		{
			PRV_pfunCallBackOVF();
		}
		else
		{
			// for debug
		}
		
		/* PreLoad: TCNT0 */
		TCNT0 = TMR0_PRELOAD_VALUE;
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u16 local_u16CTCCounter = 0;
	local_u16CTCCounter++;
	if (PRV_CTC_Counter==local_u16CTCCounter)
	{
		//CLEAR COUNTER
		local_u16CTCCounter=0;
		//CALL ACTION
		if (NULL!=PRV_pfunCallBackOC)
		{
			PRV_pfunCallBackOC();
		}
		else
		{
			//error
		}
		
	}
}

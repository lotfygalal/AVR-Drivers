
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#include "StdTypes.h"

static void (*PRV_pFunCallBackINTx[3])(void);

/************************************/
/*			ISR					*/
/************************************/
void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

void __vector_1(void)
{
	if(PRV_pFunCallBackINTx[0] != NULL)
	{
		PRV_pFunCallBackINTx[0]();
	}
}

void __vector_2(void)
{
	if(PRV_pFunCallBackINTx[1] != NULL)
	{
		PRV_pFunCallBackINTx[1]();
	}
}

void __vector_3(void)
{
	if(PRV_pFunCallBackINTx[2] != NULL)
	{
		PRV_pFunCallBackINTx[2]();
	}
}


#endif /* EXTI_PRIVATE_H_ */
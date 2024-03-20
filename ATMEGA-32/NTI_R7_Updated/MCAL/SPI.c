
#include "All_Utiles.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Cfg.h"


void SPI_voidInitMaster(SPI_InterruptEnable_t copy_enumInterruptEnable)
{
	/* Interrupt */
	switch (copy_enumInterruptEnable)
	{
		case INTERRUPT_DISABLE:
		CLR_BIT(SPI_REGS->SPCR_reg, SPIE);
		break;
		
		case INTERRUPT_ENABLE:
		SET_BIT(SPI_REGS->SPCR_reg, SPIE);
		break;
		
		default:
		while(1) {}  // for debug
	}
	
	
	/* Data Order */
	SET_BIT(SPI_REGS->SPCR_reg, DORD);
	
	/* SPI MODE: MASTER or SLAVE */
	SET_BIT(SPI_REGS->SPCR_reg, MSTR);
	
	/* DATA MODE */
	SET_BIT(SPI_REGS->SPCR_reg, CPOL);
	SET_BIT(SPI_REGS->SPCR_reg, CPHA);
	
	/* SPEED */
	SET_BIT(SPI_REGS->SPCR_reg, SPR1);
	CLR_BIT(SPI_REGS->SPCR_reg, SPR0);
	
	CLR_BIT(SPI_REGS->SPSR_reg, SPI2X);
	
	/* SPI ENABLE */
	SET_BIT(SPI_REGS->SPCR_reg, SPE);
}

void SPI_voidInitSlave(SPI_InterruptEnable_t copy_enumInterruptEnable)
{
	/* Interrupt */
	switch (copy_enumInterruptEnable)
	{
		case INTERRUPT_DISABLE:
		CLR_BIT(SPI_REGS->SPCR_reg, SPIE);
		break;
		
		case INTERRUPT_ENABLE:
		SET_BIT(SPI_REGS->SPCR_reg, SPIE);
		break;
		
		default:
		while(1) {}  // for debug
	}
	
	/* Data Order */
	SET_BIT(SPI_REGS->SPCR_reg, DORD);
	
	/* SPI MODE: MASTER or SLAVE */
	CLR_BIT(SPI_REGS->SPCR_reg, MSTR);
	
	/* DATA MODE */
	SET_BIT(SPI_REGS->SPCR_reg, CPOL);
	SET_BIT(SPI_REGS->SPCR_reg, CPHA);
	
	/* SPI ENABLE */
	SET_BIT(SPI_REGS->SPCR_reg, SPE);
}

void SPI_voidRead(u8 *copy_pu8ReadValue, SPI_Transfer_Mode_t copy_enumTransferMode)
{
	if (copy_enumTransferMode == POLLING)
	{
		while (!READ_BIT(SPI_REGS->SPSR_reg, SPIF))
		{
		}
	}
	
	if (copy_pu8ReadValue != NULL)
	{
		*copy_pu8ReadValue = SPI_REGS->SPDR_reg;
	} 
	else
	{
	}
}

void SPI_voidWrite(u8 copy_u8WriteValue, SPI_Transfer_Mode_t copy_enumTransferMode)
{
	if (copy_enumTransferMode == POLLING)
	{
		while (!READ_BIT(SPI_REGS->SPSR_reg, SPIF))
		{
		}
	}
	
	SPI_REGS->SPDR_reg = copy_u8WriteValue;
}

void SPI_voidReadWrite(u8 copy_u8TxData, u8 *copy_pu8RxData, SPI_Transfer_Mode_t copy_enumTransferMode)
{
	if (copy_pu8RxData != NULL)
	{
		SPI_REGS->SPDR_reg = copy_u8TxData;
		
		if (copy_enumTransferMode == POLLING)
		{
			while (!READ_BIT(SPI_REGS->SPSR_reg, SPIF))
			{
			}
		}
		
		*copy_pu8RxData = SPI_REGS->SPDR_reg;
	} 
	else
	{
	}
}

void SPI_voidSetCallBack(void (*copy_pFunVoid)(void))
{
	if (copy_pFunVoid == NULL)
	{
		while(1) {} // for debug
	}
	else
	{
		PRV_pFunCallBackINTx = copy_pFunVoid;
	}
}

/************************************/
/*			PRIVATE					*/
/************************************/
void __vector_12(void) __attribute__((signal));

void __vector_12(void)
{
	if(PRV_pFunCallBackINTx != NULL)
	{
		PRV_pFunCallBackINTx();
	}
}



#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "Utils.h"
#include "StdTypes.h"

typedef struct  
{
	u8 SPCR_reg;
	u8 SPSR_reg;
	u8 SPDR_reg;
	
} SPI_reg;

#define SPI_REGS		((volatile SPI_reg*)0x2D)

#define SPIE			7
#define SPE				6
#define DORD			5
#define MSTR			4
#define CPOL			3
#define CPHA			2
#define SPR1			1
#define SPR0			0

#define SPIF			7
#define WCOL			6
#define SPI2X			0


static void (*PRV_pFunCallBackINTx)(void);


#endif /* SPI_PRIVATE_H_ */
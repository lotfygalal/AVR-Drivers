


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



typedef enum
{
	POLLING,
	INTERRUPT

} SPI_Transfer_Mode_t;

typedef enum
{
	INTERRUPT_DISABLE,
	INTERRUPT_ENABLE

} SPI_InterruptEnable_t;

void SPI_voidInitMaster(SPI_InterruptEnable_t copy_enumInterruptEnable);
void SPI_voidInitSlave(SPI_InterruptEnable_t copy_enumInterruptEnable);
void SPI_voidRead(u8 *copy_pu8ReadValue, SPI_Transfer_Mode_t copy_enumTransferMode);
void SPI_voidWrite(u8 copy_u8WriteValue, SPI_Transfer_Mode_t copy_enumTransferMode);
void SPI_voidReadWrite(u8 copy_u8TxData, u8 *copy_pu8RxData, SPI_Transfer_Mode_t copy_enumTransferMode);
void SPI_voidSetCallBack(void (*copy_pFunVoid)(void));



#endif /* SPI_INTERFACE_H_ */
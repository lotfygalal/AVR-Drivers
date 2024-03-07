#ifndef DIO_H_
#define DIO_H_


#include "Std_Types.h"
#include "Dio_Cfg.h"

/* Development Errors */
/* Invalid Channel  */
#define DIO_E_PARAM_INVALID_CHANNEL_ID      (0x0A)U
/* Invalid Port     */
#define DIO_E_PARAM_INVALID_PORT_ID         (0x14)U
/* Invalid Channel Group  */
#define DIO_E_PARAM_INVALID_GROUP           (0x1F)U
/* API service called with a NULL pointer */
#define DIO_E_PARAM_POINTER                 (0x20)U

typedef uint8_t Dio_ChannelType;
typedef uint8_t Dio_PortType;
typedef uint8_t Dio_LevelType;
typedef uint8_t Dio_PortLevelType;
typedef uint8_t Dio_PinDirection;
typedef uint8_t Dio_PortDirection;

/* Definition  channel ID */
#define CHANNEL0		( (Dio_ChannelType) 0U)
#define CHANNEL1		( (Dio_ChannelType) 1U)
#define CHANNEL2		( (Dio_ChannelType) 2U)
#define CHANNEL3		( (Dio_ChannelType) 3U)
#define CHANNEL4		( (Dio_ChannelType) 4U)
#define CHANNEL5		( (Dio_ChannelType) 5U)
#define CHANNEL6		( (Dio_ChannelType) 6U)
#define CHANNEL7		( (Dio_ChannelType) 7U)
#define CHANNEL8		( (Dio_ChannelType) 8U)
#define CHANNEL9		( (Dio_ChannelType) 9U)
#define CHANNEL10		( (Dio_ChannelType) 10U)
#define CHANNEL11		( (Dio_ChannelType) 11U)
#define CHANNEL12		( (Dio_ChannelType) 12U)
#define CHANNEL13		( (Dio_ChannelType) 13U)
#define CHANNEL14		( (Dio_ChannelType) 14U)
#define CHANNEL15		( (Dio_ChannelType) 15U)
#define CHANNEL16		( (Dio_ChannelType) 16U)
#define CHANNEL17		( (Dio_ChannelType) 17U)
#define CHANNEL18		( (Dio_ChannelType) 18U)
#define CHANNEL19		( (Dio_ChannelType) 19U)
#define CHANNEL20		( (Dio_ChannelType) 20U)
#define CHANNEL21		( (Dio_ChannelType) 21U)
#define CHANNEL22		( (Dio_ChannelType) 22U)
#define CHANNEL23		( (Dio_ChannelType) 23U)
#define CHANNEL24		( (Dio_ChannelType) 24U)
#define CHANNEL25		( (Dio_ChannelType) 25U)
#define CHANNEL26		( (Dio_ChannelType) 26U)
#define CHANNEL27		( (Dio_ChannelType) 27U)
#define CHANNEL28		( (Dio_ChannelType) 28U)
#define CHANNEL29		( (Dio_ChannelType) 29U)
#define CHANNEL30		( (Dio_ChannelType) 30U)
#define CHANNEL31		( (Dio_ChannelType) 31U)
#define CHANNEL32		( (Dio_ChannelType) 32U)

/* definition Port ID */
#define PORT_ID0	(Dio_PortType)(0U)
#define PORT_ID1	(Dio_PortType)(1U)
#define PORT_ID2	(Dio_PortType)(2U)
#define PORT_ID3	(Dio_PortType)(3U)

typedef struct{
    uint32_t		mask;
    uint8_t			offset;
    Dio_PortType	port;
}Dio_ChannelGroupType;


								/*                            Functions Prototype                                          */

FUNC(Dio_LevelType, DIO_MEM_CLASS) Dio_ReadChannel (VAR(Dio_ChannelType, DIO_MEM_CLASS) ChannelId);
FUNC(void, DIO_MEM_CLASS) Dio_WriteChannel(VAR(Dio_ChannelType, DIO_MEM_CLASS) ChannelId , VAR(Dio_LevelType, DIO_MEM_CLASS) Level);
FUNC(Dio_PortLevelType, DIO_MEM_CLASS) Dio_ReadPort ( VAR(Dio_PortType, DIO_MEM_CLASS) PortId);
FUNC(void, DIO_MEM_CLASS) Dio_WritePort( VAR(Dio_PortType, DIO_MEM_CLASS) PortId , VAR(Dio_PortLevelType, DIO_MEM_CLASS) Level);
FUNC(Dio_PortLevelType, DIO_MEM_CLASS) Dio_ReadChannelGroup( P2CONST( Dio_ChannelGroupType, DIO_MEM_CLASS , DIO_PTR_CLASS) ChannelGroupIdPtr);
FUNC(void, DIO_MEM_CLASS) Dio_WriteChannelGroup( P2CONST(Dio_ChannelGroupType, DIO_MEM_CLASS , DIO_PTR_CLASS )ChannelGroupId , VAR(Dio_PortLevelType, DIO_MEM_CLASS) Level);
FUNC(Dio_LevelType, DIO_MEM_CLASS) Dio_FlipChannel( VAR( Dio_ChannelType, DIO_MEM_CLASS) ChannelId );
FUNC(void, DIO_MEM_CLASS) Dio_MaskedWritePort( VAR(Dio_PortType, DIO_MEM_CLASS) PortId, VAR(Dio_PortLevelType, DIO_MEM_CLASS) Level, VAR(Dio_PortLevelType, DIO_MEM_CLASS) Mask);

#endif /* DIO_H_ */

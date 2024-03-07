											/****************** lotfy galal   ********************/
#include "Common_Macros.h"
#include "Dio.h"
#include "Dio_MemMap.h"
#include "Det.h"
#include "SchM_Dio.h"
#include "Dio_Regs.h"
#include "Dio_Cfg.h"
#include "Dio_Private.h"

extern const Dio_Channel_Configs_t DioChannels[DIO_CONFIGURED_CHANNELS];
extern const Dio_Port_Configs_t DioPorts[DIO_CONFIGURED_PORTS];

							/*                       Dio_ReadChannel                         */

FUNC(Dio_LevelType, DIO_MEM_CLASS) Dio_ReadChannel (VAR(Dio_ChannelType, DIO_MEM_CLASS) ChannelId)
{
    Dio_LevelType Local_DioChannelValue = STD_LOW;
    if (ChannelId < DIO_CONFIGURED_CHANNELS)
    {
        switch(DioChannels[ChannelId].PortNum)
        {
        case DIOA:
            Local_DioChannelValue = GET_BIT(PINA, DioChannels[ChannelId].ChannelNum);
            break;
        case DIOB:
            Local_DioChannelValue = GET_BIT(PINB, DioChannels[ChannelId].ChannelNum);
            break;
        case DIOC:
            Local_DioChannelValue = GET_BIT(PINC, DioChannels[ChannelId].ChannelNum);
            break;
        case DIOD:
            Local_DioChannelValue = GET_BIT(PIND, DioChannels[ChannelId].ChannelNum);
            break;
        default:

            break;
        }
    }
    else
    {
#if DIO_DEV_ERROR_DETECT == STD_ON
        Local_DioChannelValue = STD_LOW;
#endif
    }
    return Local_DioChannelValue;
}

							/*                       Dio_WriteChannel                         */
FUNC(void, DIO_MEM_CLASS) Dio_WriteChannel(VAR(Dio_ChannelType, DIO_MEM_CLASS) ChannelId , VAR(Dio_LevelType, DIO_MEM_CLASS) Level)
{
    volatile uint8_t * PortPtr = NULL;
    if (ChannelId < DIO_CONFIGURED_CHANNELS)
    {
        if ( DioChannels[ChannelId].ChannelDirection == STD_OUT )
        {
            switch(DioChannels[ChannelId].PortNum)
            {
            case DIOA:
                PortPtr = &PORTA;
                break;
            case DIOB:
                PortPtr = &PORTB;
                break;
            case DIOC:
                PortPtr = &PORTC;
                break;
            case DIOD:
                PortPtr = &PORTD;
                break;
            default:
                break;
            }
            if(STD_HIGH == Level )
            {
                SET_BIT(*PortPtr,DioChannels[ChannelId].ChannelNum);
            }
            else if (STD_LOW == Level)
            {
                CLEAR_BIT(*PortPtr , DioChannels[ChannelId].ChannelNum);
            }
            else
            {
                /* No Action Required */
            }
        }
        else
        {
            /* No Action Required */
        }
    }
    else
    {
#if DIO_DEV_ERROR_DETECT == STD_ON
        /* Report an Error */
#endif
    }
}
							/*                       Dio_ReadPort                         */
FUNC(Dio_PortLevelType, DIO_MEM_CLASS) Dio_ReadPort ( VAR(Dio_PortType, DIO_MEM_CLASS) PortId)
{
    Dio_PortLevelType Local_DioReturnValue = STD_LOW;

    if( PortId < DIO_CONFIGURED_PORTS )
    {
        switch(DioPorts[PortId].PortNum)
        {
        case DIOA:
            Local_DioReturnValue = PINA;
            break;
        case DIOB:
            Local_DioReturnValue = PINB;
            break;
        case DIOC:
            Local_DioReturnValue = PINC;
            break;
        case DIOD:
            Local_DioReturnValue = PIND;
            break;
        default:
            /* No Action Required */
            break;
        }
    }
    else
    {
#if (DIO_DEV_ERROR_DETECT == STD_ON)

        /* Report Error */

#endif
    }
    return Local_DioReturnValue;
}

							/*                       Dio_WritePort                         */
FUNC(void, DIO_MEM_CLASS) Dio_WritePort( VAR(Dio_PortType, DIO_MEM_CLASS) PortId , VAR(Dio_PortLevelType, DIO_MEM_CLASS) Level)
{
    if( PortId < DIO_CONFIGURED_PORTS )
    {
        if ( DioPorts[PortId].PortDirection == STD_OUT )
        {
            switch(DioPorts[PortId].PortNum)
            {
            case DIOA:
                PORTA = Level;
                break;
            case DIOB:
                PORTB = Level;
                break;
            case DIOC:
                PORTC = Level;
                break;
            case DIOD:
                PORTD = Level;
                break;
            default:
                /* No Action Required */
                break;
            }
        }
        else
        {
            /* No Action Required */
        }
    }
    else
    {
#if DIO_DEV_ERROR_DETECT == STD_ON
        /* Report an Error */
#endif
    }
}

							/*                       Dio_FlipChannel                         */
#if (DIO_FLIP_CHANNEL_API == STD_ON)
FUNC(Dio_LevelType, DIO_MEM_CLASS) Dio_FlipChannel( VAR( Dio_ChannelType, DIO_MEM_CLASS) ChannelId )
{
    Dio_LevelType Local_DioReturnResult = STD_LOW;
    volatile uint8_t * PortPtr = NULL;

    if ( ChannelId < DIO_CONFIGURED_CHANNELS )
    {
        switch(DioChannels[ChannelId].PortNum)
        {
        case DIOA:
            PortPtr = &PORTA;
            break;
        case DIOB:
            PortPtr = &PORTB;
            break;
        case DIOC:
            PortPtr = &PORTC;
            break;
        case DIOD:
            PortPtr = &PORTD;
            break;
        default:
            /* No Action Required */
            break;
        }

        if ( IS_BIT_SET(*PortPtr, DioChannels[ChannelId].ChannelNum))
        {
            CLEAR_BIT(*PortPtr, DioChannels[ChannelId].ChannelNum);
            Local_DioReturnResult = STD_LOW;
        }
        else
        {
            SET_BIT(*PortPtr, DioChannels[ChannelId].ChannelNum);
            SET_BIT(*PortPtr, DioChannels[ChannelId].ChannelNum);
            Local_DioReturnResult = STD_HIGH;
        }
    }
    else
    {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
        /* Report Errors */
        Local_DioReturnResult = STD_LOW;
#endif
    }
    return Local_DioReturnResult;
}
#endif
							/*                       Dio_ReadChannelGroup                         */

FUNC(void, DIO_MEM_CLASS) Dio_MaskedWritePort( VAR(Dio_PortType, DIO_MEM_CLASS) PortId, VAR(Dio_PortLevelType, DIO_MEM_CLASS) Level, VAR(Dio_PortLevelType, DIO_MEM_CLASS) Mask);

FUNC(Dio_PortLevelType, DIO_MEM_CLASS) Dio_ReadChannelGroup( P2CONST( Dio_ChannelGroupType, DIO_MEM_CLASS , DIO_PTR_CLASS) ChannelGroupIdPtr)
{
	Dio_PortLevelType Local_Dio_ChannelGroupValue = STD_LOW;
	volatile uint8_t * DioPortPtr = NULL; 
	if(ChannelGroupIdPtr != NULL)
	{
		switch(ChannelGroupIdPtr->port)
		{
			case DIOA:
			DioPortPtr = &PINA;
			break;
			case DIOB:
			DioPortPtr = &PINB;
			break;
			case DIOC:
			DioPortPtr = &PINC;
			break;
			case DIOD:
			DioPortPtr = &PIND;
			break;
			default:
			/* Report Error to DET */
			break;
		}
		Local_Dio_ChannelGroupValue = (*DioPortPtr&(ChannelGroupIdPtr->mask) >> ChannelGroupIdPtr->offset);
		
	}
	else
	{
		#if DIO_DEV_ERROR_DETECT == STD_ON
		/* Report Error to DET */

#endif
	}
	return Local_Dio_ChannelGroupValue;
}
							/*                       Dio_WriteChannelGroup                         */
FUNC(void, DIO_MEM_CLASS) Dio_WriteChannelGroup( P2CONST(Dio_ChannelGroupType, DIO_MEM_CLASS , DIO_PTR_CLASS )ChannelGroupIdPtr , VAR(Dio_PortLevelType, DIO_MEM_CLASS) Level)
{
	if (NULL == ChannelGroupIdPtr)
	{
		switch(ChannelGroupIdPtr->port)
		{
			case DIOA:
				PORTA &=~(ChannelGroupIdPtr->mask);
				PORTA |= ( ( Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);
				break;
			case DIOB:
				PORTB &=~(ChannelGroupIdPtr->mask);
				PORTB |= ( ( Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);
				break;
			case DIOC:
				PORTC &=~(ChannelGroupIdPtr->mask);
				PORTC |= ( ( Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);
				break;
			case DIOD:
				PORTD &=~(ChannelGroupIdPtr->mask);
				PORTD |= ( ( Level << ChannelGroupIdPtr->offset) & ChannelGroupIdPtr->mask);
				break;
			default:
			/* Report Error */
			break;
		}
	}
	else
	{
		#if DIO_DEV_ERROR_DETECT == STD_ON
		/* Report Error to Det */
#endif
	}
}



/*
 * GI.c
 *
 * Created: 3/3/2024 2:02:25 PM
 *  Author: LOTFY
 */ 
#include "StdTypes.h"
#include "Utils.h"
#include "GI_Private.h"
#include "GI_Interface.h"


void GI_VoidEnable(void)
{
	SET_BIT(SREG_REG,I);
}
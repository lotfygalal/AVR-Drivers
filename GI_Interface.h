/*
 * GI_Interface.h
 *
 * Created: 3/3/2024 2:03:15 PM
 *  Author: LOTFY
 */ 
#include "StdTypes.h"
#include "Utils.h"

#ifndef GI_INTERFACE_H_
#define GI_INTERFACE_H_

#define SREG_REG (*(volatile u8*)0x5F)
#define I 7


void GI_VoidEnable(void);
void GI_VoidDisable(void);



#endif /* GI_INTERFACE_H_ */
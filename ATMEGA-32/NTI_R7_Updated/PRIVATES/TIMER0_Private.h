

#ifndef TMR0_PRIVATE_H_
#define TMR0_PRIVATE_H_

#include "StdTypes.h"

#define TMR0_NORMAL_MODE	1
#define TMR0_CTC_MODE		2

static void (*PRV_pfunCallBackOVF)(void) = NULL;
static void (*PRV_pfunCallBackOC)(void) = NULL;


#endif /* TMR0_PRIVATE_H_ */
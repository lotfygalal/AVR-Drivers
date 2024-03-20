/*
 * MOTOR_Interface.h
 *
 * Created: 3/17/2024 5:42:19 PM
 *  Author: LOTFY
 */ 

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "MOTOR_CFG.h"

typedef enum{
	CW=1,
	CCW=2
	}MotorDir_type;

void MOTOR_voidInit(void);
void MOTOR_voidStartCW(void);
void MOTOR_voidStartCCW(void);
void MOTOR_voidStop	(void);
void MOTOR_voidChangePWM(MotorDir_type copy_enumMotorDir,u8 copy_pwmvalue);




#endif /* MOTOR_INTERFACE_H_ */
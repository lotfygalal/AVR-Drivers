/*
 * PWM_Interface.h
 *
 * Created: 3/17/2024 10:51:19 AM
 *  Author: LOTFY
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_


void PWM_voidInitChannel_0			 (void);
void PWM_voidGenerate_PWM_Channel_0  (u8 copy_u8DutyCycle);
void PWM_voidStopChannel_0			 (void);

void PWM_voidInitChannel_1A			 (void);										//MODE 14
void PWM_voidGenerate_PWM_Channel_1A (u32 cop_u32Frequancy_Hz,f32 copy_f32DutyCycle);
void PWM_voidStopChannel_1A			 (void);




#endif /* PWM_INTERFACE_H_ */
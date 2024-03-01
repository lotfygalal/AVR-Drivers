/*
 * Bit_Math.h
 *
 * Created: 2/29/2024 2:21:40 PM
 *  Author: LOTFY
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define  READ_BIT(reg,bit)    ((reg>>bit)&1)
#define  SET_BIT(reg,bit)     (reg|=(1<<bit))
#define  CLR_BIT(reg,bit)     (reg&=~(1<<bit))
#define  TOG_BIT(reg,bit)     (reg^=(1<<bit))

#endif /* BIT_MATH_H_ */
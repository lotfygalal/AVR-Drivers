/*
 * _7_SEGMANT_Interface.h
 *
 * Created: 3/1/2024 10:04:14 PM
 *  Author: LOTFY
 */ 

#include "StdTypes.h"
#include "Bit_Math.h"
#include "DIO_interface.h"

#ifndef 7_SEGMANT_INTERFACE_H_
#define 7_SEGMANT_INTERFACE_H_

#define COM1_PORT    DIO_PORTA
#define COM1_PIN     DIO_PIN3

#define COM2_PORT    DIO_PORTA
#define COM2_PIN     DIO_PIN2


#define COM3_PORT    DIO_PORTB
#define COM3_PIN     DIO_PIN5


#define COM4_PORT    DIO_PORTB
#define COM4_PIN     DIO_PIN6


void Segmant_init();
void Segmant_print_num(u8 copy_u8num);



#endif /* 7_SEGMANT_INTERFACE_H_ */
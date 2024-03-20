﻿

#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef          char c8;
typedef unsigned char u8;
typedef   signed char s8;

typedef unsigned short u16;
typedef   signed short s16;

typedef unsigned long u32;
typedef   signed long s32;

typedef unsigned long long u64;
typedef signed long long s64;

typedef float f32;
typedef double f64;

#define  MAX_U8   ((u8)255)
#define  MIN_U8   ((u8)0)
#define  MAX_S8   ((s8)127)
#define  MIN_S8   ((s8)-128)
#define  ZERO_S8  ((s8)0)

#define   NULLPTR  ((void*)0)
#define   NULL     (char)0

typedef enum{
	FALSE,
	TRUE
}Bool_t;

typedef enum{
	OK=0,
	NOK,
	OUT_OF_RANGE,
	NULL_PTR_ERROR   //error due to wild/dangled pointer
}Error_t;


#endif /* STDTYPES_H_ */
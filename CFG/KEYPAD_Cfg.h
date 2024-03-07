﻿
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
/***********************************     *** select your keypad size ***     ****************************************/
#define  ROWS   4
#define  COLS   4
/***********************************     *** select your keypad PINS ***     ****************************************/
#define FIRST_OUTPUT PINB4
#define FIRST_INPUT  PIND2
#define NO_KEY '?'

/***********************************     *** Array of keypad ***     ****************************************/
#if KEPAD_ARRAY==1
const u8 KeysArray[ROWS][COLS]= { /*  COLUMNS  */
					   /*ROWS*/ {'7','8','9','/'},
					   /*ROWS*/ {'4','5','6','*'},
					   /*ROWS*/ {'1','2','3','-'},
					   /*ROWS*/ {'c','0','=','+'},
											    };
#endif


#endif /* KEYPAD_CFG_H_ */
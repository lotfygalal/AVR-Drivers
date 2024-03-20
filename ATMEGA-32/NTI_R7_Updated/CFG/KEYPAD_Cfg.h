
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_
/***********************************     *** select your keypad size ***     ****************************************/
#define  ROWS   4
#define  COLS   4
/***********************************     *** select your keypad PINS ***     ****************************************/
#define FIRST_INPUT  PINC0		//pins down
#define FIRST_OUTPUT PINC4		//pins up
#define NO_KEY '?'

/***********************************     *** Array of keypad ***     ****************************************/
//Guard for non-repeatable array
#if KEPAD_ARRAY==1

const u8 KeysArray[ROWS][COLS]= { /*  COLUMNS  */
					   /*ROWS*/ {'7','8','9','/'},
					   /*ROWS*/ {'4','5','6','*'},
					   /*ROWS*/ {'1','2','3','-'},
					   /*ROWS*/ {'c','0','=','+'},
											    };
#endif


#endif /* KEYPAD_CFG_H_ */
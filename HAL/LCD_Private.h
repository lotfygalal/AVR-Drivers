

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/***********************************     *** lines of LCD ***     ****************************************/
#define Line1_Start  0x80        // from data sheet
#define Line2_Start (0x80+0x40)

/***********************************     *** _8_BIT or _4_BIT ***     ****************************************/
#define _8_BIT 1
#define _4_BIT 0
/***********************************     *** patterns ***     ****************************************/
u8 pattern0[8]={0x04,0x0A,0x04,0x1B,0x04,0x0A,0x0A,0x00};  //human
u8 pattern1[8]={0x02,0x15,0x0A,0x04,0x0A,0x15,0x14,0x14};  //human raise right hand
u8 pattern2[8]={0x08,0x15,0x0A,0x04,0x0A,0x15,0x05,0x05};  //human raise left hand
u8 pattern11[8]={0x00,0x02,0x05,0x02,0x04,0x0C,0x18,0x00}; //human dead
u8 pattern12[8]={0x00,0x00,0x00,0x00,0x03,0x1F,0x00,0x00}; //human dead2
u8 pattern3[8]={0x00,0x00,0x0A,0x15,0x11,0x0A,0x04,0x00};  //HART
u8 pattern10[8]={0x04,0x0C,0x1C,0x0C,0x04,0x04,0x04,0x04};  //knife
/*laugh face*/
u8 pattern4[8]={0B00001,0B00011,0B00111,0B01110,0B11110,0B11111,0B11111,0B11111};
u8 pattern5[8]={0B11111,0B11111,0B11111,0B01110,0B01110,0B11111,0B11111,0B11111};
u8 pattern6[8]={0B10000,0B11000,0B11100,0B01110,0B01111,0B11111,0B11111,0B11111};
u8 pattern7[8]={0B11011,0B11000,0B11100,0B11110,0B01111,0B00111,0B00011,0B00001};
u8 pattern8[8]={0B11111,0B00000,0B00000,0B00000,0B00000,0B11111,0B11111,0B11111};
u8 pattern9[8]={0B11011,0B00011,0B00111,0B01111,0B11110,0B11100,0B11000,0B10000};
/**/


#endif /* LCD_PRIVATE_H_ */
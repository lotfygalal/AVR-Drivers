

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/***********************************     *** _8_BIT or _4_BIT ***     ****************************************/
#define LCD_MODE _4_BIT      //choose for LCD mode _4_BIT || _8_BIT //define @ lcd_privat.h

/***********************************     *** definition lcd pins for 2mode***     ****************************************/

#define RS PINA1           //Register Selection
#define EN PINA2		   //Trigger Enable
//RW CONNECTION WITH Ground (DEFAULT 0)

/***********************************     *** _4_BIT mode***     ****************************************/
#define D4 PINA3
#define D5 PINA4
#define D6 PINA5
#define D7 PINA6

/***********************************     *** _8_BIT mode ***     ****************************************/
#define LCD_PORT PA         //LCD Select Port

#endif /* LCD_CFG_H_ */
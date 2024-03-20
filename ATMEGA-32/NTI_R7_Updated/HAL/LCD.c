#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Cfg.h"
#include "LCD_Private.h"

#if LCD_MODE == _8_BIT  //To selection go to CFG File.

/***********************************     *** LCD write Saved Instruction ***     ****************************************/
static void LCD_voidWriteIns(u8 copy_u8Instruction)
{
	DIO_voidWritePin(RS,LOW);
	DIO_voidWritePort(PA,copy_u8Instruction);
	DIO_voidWritePin(EN,HIGH);
	_delay_ms(1);
	DIO_voidWritePin(EN,LOW);
}
/***********************************     *** LCD write Any Data ***     ****************************************/
static void LCD_voidWriteData(u8 copy_u8Data)
{
	DIO_voidWritePin(RS,HIGH);
	DIO_voidWritePort(PA,copy_u8Data);
	DIO_voidWritePin(EN,HIGH);
	_delay_ms(1);
	DIO_voidWritePin(EN,LOW);
}
/***********************************     *** LCD INITIALIZATION ***     ****************************************/
void LCD_voidInit()
{
	_delay_ms(50);
	LCD_voidWriteIns(0x38); //0x38 --> Function Set
	_delay_ms (1);
	LCD_voidWriteIns(0x0c); //0x0c --> Display On  //0x0e --> Cursor On //0x0f --> Cursor Blink
	_delay_ms (1);
	LCD_voidWriteIns(0x01); //0x01 --> Display Clear
	_delay_ms (2);
	LCD_voidWriteIns(0x06); //0x06 --> Next cell without shifting //0x04 --> NO shifting //0x07 -->shift left //0x05 -->shift right
}
#else  //_4_BIT

/***********************************     *** LCD write Saved Instruction ***     ****************************************/
static void LCD_voidWriteIns(u8 copy_u8Instruction)
{
	DIO_voidWritePin(RS,LOW);
	DIO_voidWritePin(D7,READ_BIT(copy_u8Instruction,7));
	DIO_voidWritePin(D6,READ_BIT(copy_u8Instruction,6));
	DIO_voidWritePin(D5,READ_BIT(copy_u8Instruction,5));
	DIO_voidWritePin(D4,READ_BIT(copy_u8Instruction,4));
	
	DIO_voidWritePin(EN,HIGH);
	_delay_ms(1);
	DIO_voidWritePin(EN,LOW);
	
	DIO_voidWritePin(D7,READ_BIT(copy_u8Instruction,3));
	DIO_voidWritePin(D6,READ_BIT(copy_u8Instruction,2));
	DIO_voidWritePin(D5,READ_BIT(copy_u8Instruction,1));
	DIO_voidWritePin(D4,READ_BIT(copy_u8Instruction,0));
	
	DIO_voidWritePin(EN,HIGH);
	_delay_ms(1);
	DIO_voidWritePin(EN,LOW);
}
/***********************************     *** LCD write Any Data ***     ****************************************/
static void LCD_voidWriteData(u8 copy_u8Data)
{
	DIO_voidWritePin(RS,HIGH);
	DIO_voidWritePin(D7,READ_BIT(copy_u8Data,7));
	DIO_voidWritePin(D6,READ_BIT(copy_u8Data,6));
	DIO_voidWritePin(D5,READ_BIT(copy_u8Data,5));
	DIO_voidWritePin(D4,READ_BIT(copy_u8Data,4));
	
	DIO_voidWritePin(EN,HIGH);
	_delay_ms(1);
	DIO_voidWritePin(EN,LOW);
	
	DIO_voidWritePin(D7,READ_BIT(copy_u8Data,3));
	DIO_voidWritePin(D6,READ_BIT(copy_u8Data,2));
	DIO_voidWritePin(D5,READ_BIT(copy_u8Data,1));
	DIO_voidWritePin(D4,READ_BIT(copy_u8Data,0));
	
	DIO_voidWritePin(EN,HIGH);
	_delay_ms(1);
	DIO_voidWritePin(EN,LOW);
}
/***********************************     *** LCD INITIALIZATION ***     ****************************************/
void LCD_voidInit()
{
	_delay_ms(50);
	LCD_voidWriteIns(0x02); //0x02 --> Function Set
	LCD_voidWriteIns(0x28); //0x28 --> Function Set
	_delay_ms (1);
	LCD_voidWriteIns(0x0c); //0x0c --> Display On  //0x0e --> Cursor On //0x0f --> Cursor Blink
	_delay_ms (1);
	LCD_voidWriteIns(0x01); //0x01 --> Display Clear
	_delay_ms (2);
	LCD_voidWriteIns(0x06); //0x06 --> Next cell without shifting //0x04 --> NO shifting //0x07 -->shift left //0x05 -->shift right
}
#endif

/***********************************     *** start write from any cell ***     ****************************************/
void LCD_voidGoToCell(LCD_Line_type copy_u8Line,LCD_CELL_type copy_u8Cell)
{
	switch (copy_u8Line)
	{
		case LINE1:
		LCD_voidWriteIns((Line1_Start|0x80)+copy_u8Cell);
		break;
		case LINE2:
		LCD_voidWriteIns((Line2_Start|0x80)+copy_u8Cell);
		break;
		case LINE3:
		LCD_voidWriteIns((Line3_Start|0x80)+copy_u8Cell);
		break;
		case LINE4:
		LCD_voidWriteIns((Line4_Start|0x80)+copy_u8Cell);
		break;
	}
}
/***********************************     *** LCD Write character ***     ****************************************/
void LCD_voidWriteChar(u8 copy_u8character)
{
	LCD_voidWriteData(copy_u8character);
}
/***********************************     *** LCD Write Pattern  ***     ****************************************/
void LCD_voidCreatCustomChar(u8 copy_u8Address,u8 *copy_u8Pattern)
{
	LCD_voidWriteIns(0x40+copy_u8Address*8);  //for 8byte CG-RAM
	for(u8 i=0;i<8;i++)
	{
		LCD_voidWriteData(copy_u8Pattern[i]);
	}
	LCD_voidWriteIns(0x80);           //for reset to DD-RAM
}
/***********************************     *** LCD Write string  ***     ****************************************/
void LCD_voidWriteString(c8 *copy_u8String)
{
	u8 i;
	for (i=0;copy_u8String[i];i++)
	{
		LCD_voidWriteChar(copy_u8String[i]);
	}
}
/***********************************     *** LCD Write number  ***     ****************************************/
void LCD_voidWriteNumber(s32 copy_u8Number)
{
	c8 str[20];
	u8 i=0;
	s8 j;
	if (copy_u8Number==0)
	{
		LCD_voidWriteChar('0');
		return;
	}
	if (copy_u8Number<0)
	{
		LCD_voidWriteChar('-');
		copy_u8Number=copy_u8Number*(-1);
	}
	
	while(copy_u8Number)
	{
		str[i]=copy_u8Number%10 +'0';
		i++;
		copy_u8Number=copy_u8Number/10;
	}
	for (j=i-1;j>=0;j--)
	{
		LCD_voidWriteChar(str[j]);
	}
}
/***********************************     *** LCD Write Binary ***     ****************************************/
void LCD_voidWriteBinary(u8 copy_u8Number)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_voidWriteChar(READ_BIT(copy_u8Number,i)+'0');
	}
}
/***********************************     *** LCD Write HEX ***     ****************************************/
void LCD_voidWriteHex(u8 copy_u8Number)
{
	u8 HN=copy_u8Number>>4;
	u8 LN=copy_u8Number&0x0f;
	u8 hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	LCD_voidWriteChar(hex[HN]);
	LCD_voidWriteChar(hex[LN]);
}
/***********************************     *** LCD Write number on 4 digits ***     ****************************************/
void LCD_voidWrite_4Digits(u16 copy_u8Number)
{
	//LCD_voidWriteChar( ((copy_u8Number%100000)/10000)+'0');    //if 5 digits
	LCD_voidWriteChar( ((copy_u8Number%10000)/1000)+'0');
	LCD_voidWriteChar( ((copy_u8Number%1000)/100)+'0');
	LCD_voidWriteChar( ((copy_u8Number%100)/10)+'0');
	LCD_voidWriteChar( ((copy_u8Number%10)/1)+'0');
}
/***********************************     *** LCD Write String on specisfic cell ***     ****************************************/
void LCD_voidGoToWriteString(u8 copy_u8Line ,u8 copy_u8Cell,c8 *copy_u8String)
{
	LCD_voidGoToCell(copy_u8Line,copy_u8Cell);
	LCD_voidWriteString(copy_u8String);
}
/***********************************     *** LCD clear ALL screen ***     ****************************************/
void LCD_voidClear(void)
{
	LCD_voidWriteIns(0x01);
	_delay_ms(1);
}
/***********************************     *** LCD Clear specisfic cells***     ****************************************/
void LCD_voidClearNoCell(u8 copy_u8Line ,u8 copy_u8Cell,u8 copy_u8No_Cells)
{
	u8 i;
	LCD_voidGoToCell(copy_u8Line,copy_u8Cell);
	for (i=0;i<copy_u8No_Cells;i++)
	{
		LCD_voidWriteChar(' ');  //space
	}
}
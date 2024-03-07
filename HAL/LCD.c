#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Cfg.h"
#include "LCD_Private.h"

#if LCD_MODE == _8_BIT  //To selection go to CFG File.

/***********************************     *** LCD write Saved Instruction ***     ****************************************/
static void LCD_WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(PA,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
}
/***********************************     *** LCD write Any Data ***     ****************************************/
static void LCD_WriteData(u8 Data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(PA,Data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
}
/***********************************     *** LCD INITIALIZATION ***     ****************************************/
void LCD_Init()
{
	_delay_ms(50);
	LCD_WriteIns(0x38); //0x38 --> Function Set
	_delay_ms (1);
	LCD_WriteIns(0x0c); //0x0c --> Display On  //0x0e --> Cursor On //0x0f --> Cursor Blink
	_delay_ms (1);
	LCD_WriteIns(0x01); //0x01 --> Display Clear
	_delay_ms (2);
	LCD_WriteIns(0x06); //0x06 --> Next cell without shifting //0x04 --> NO shifting //0x07 -->shift left //0x05 -->shift right
}
#else  //_4_BIT

/***********************************     *** LCD write Saved Instruction ***     ****************************************/
static void LCD_WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
}
/***********************************     *** LCD write Any Data ***     ****************************************/
static void LCD_WriteData(u8 Data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(Data,7));
	DIO_WritePin(D6,READ_BIT(Data,6));
	DIO_WritePin(D5,READ_BIT(Data,5));
	DIO_WritePin(D4,READ_BIT(Data,4));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	
	DIO_WritePin(D7,READ_BIT(Data,3));
	DIO_WritePin(D6,READ_BIT(Data,2));
	DIO_WritePin(D5,READ_BIT(Data,1));
	DIO_WritePin(D4,READ_BIT(Data,0));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
}
/***********************************     *** LCD INITIALIZATION ***     ****************************************/
void LCD_Init()
{
	_delay_ms(50);
	LCD_WriteIns(0x02); //0x02 --> Function Set
	LCD_WriteIns(0x28); //0x28 --> Function Set
	_delay_ms (1);
	LCD_WriteIns(0x0c); //0x0c --> Display On  //0x0e --> Cursor On //0x0f --> Cursor Blink
	_delay_ms (1);
	LCD_WriteIns(0x01); //0x01 --> Display Clear
	_delay_ms (2);
	LCD_WriteIns(0x06); //0x06 --> Next cell without shifting //0x04 --> NO shifting //0x07 -->shift left //0x05 -->shift right
}
#endif

/***********************************     *** start write from any cell ***     ****************************************/
void LCD_GoToCell(LCD_Line_type line,LCD_CELL_type cell)
{
	switch (line)
	{
		case LINE1:
		LCD_WriteIns(Line1_Start|0x80+cell);
		break;
		case LINE2:
		LCD_WriteIns(Line2_Start|0x80+cell);
		break;
	}
}
/***********************************     *** LCD Write character ***     ****************************************/
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
/***********************************     *** LCD Write Pattern  ***     ****************************************/
void LCD_CreatCustomChar(u8 address,u8*pattern)
{
	LCD_WriteIns(0x40+address*8);  //for 8byte CG-RAM
	for(u8 i=0;i<8;i++)
	{
		LCD_WriteData(pattern[i]);
	}
	LCD_WriteIns(0x80);           //for reset to DD-RAM
}
/***********************************     *** LCD Write string  ***     ****************************************/
void LCD_WriteString(c8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}
/***********************************     *** LCD Write number  ***     ****************************************/
void LCD_WriteNumber(s32 num)
{
	c8 str[20];
	u8 i=0;
	s8 j;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		LCD_WriteChar('-');
		num=num*(-1);
	}
	
	while(num)
	{
		str[i]=num%10 +'0';
		i++;
		num=num/10;
	}
	for (j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
}
/***********************************     *** LCD Write Binary ***     ****************************************/
void LCD_WriteBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteChar(READ_BIT(num,i)+'0');
	}
}
/***********************************     *** LCD Write HEX ***     ****************************************/
void LCD_WriteHex(u8 num)
{
	u8 HN=num>>4;
	u8 LN=num&0x0f;
	u8 hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	LCD_WriteChar(hex[HN]);
	LCD_WriteChar(hex[LN]);
}
/***********************************     *** LCD Write number on 4 digits ***     ****************************************/
void LCD_Write_4Digits(u16 num)
{
	//LCD_WriteChar( ((num%100000)/10000)+'0');    //if 5 digits
	LCD_WriteChar( ((num%10000)/1000)+'0');
	LCD_WriteChar( ((num%1000)/100)+'0');
	LCD_WriteChar( ((num%100)/10)+'0');
	LCD_WriteChar( ((num%10)/1)+'0');
}
/***********************************     *** LCD Write String on specisfic cell ***     ****************************************/
void LCD_GoToWriteString(u8 line ,u8 cell,c8*str)
{
	LCD_GoToCell(line,cell);
	LCD_WriteString(str);
}
/***********************************     *** LCD clear ALL screen ***     ****************************************/
void LCD_Clear(void)
{
	LCD_WriteIns(0x01);
	_delay_ms(1);
}
/***********************************     *** LCD Clear specisfic cell***     ****************************************/
void LCD_ClearNoCell(u8 line ,u8 cell,u8 No_Cells)
{
	u8 i;
	LCD_GoToCell(line,cell);
	for (i=0;i<No_Cells;i++)
	{
		LCD_WriteChar(' ');  //space
	}
}
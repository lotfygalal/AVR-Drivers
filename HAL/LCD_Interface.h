

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

typedef enum{
	LINE1,
	LINE2
}LCD_Line_type;
typedef enum{
	CELL0,
	CELL1,
	CELL2,
	CELL3,
	CELL4,
	CELL5,
	CELL6,
	CELL7,
	CELL8,
	CELL9,
	CELL10,
	CELL11,
	CELL12,
	CELL13,
	CELL14,
	CELL15,
	TOTAL_CELL
}LCD_CELL_type;

void LCD_Init(void);
void LCD_GoToCell(LCD_Line_type line,LCD_CELL_type cell);
void LCD_GoToWriteString(u8 line ,u8 cell,c8*str);
void LCD_Clear(void);
void LCD_ClearNoCell(u8 line ,u8 cell,u8 No_Cell);
void LCD_WriteChar(u8 ch);
void LCD_CreatCustomChar(u8 address,u8*pattern);
void LCD_WriteString(c8*str);
void LCD_WriteNumber(s32 num);
void LCD_Write_4Digits(u16 num);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);








#endif /* LCD_INTERFACE_H_ */
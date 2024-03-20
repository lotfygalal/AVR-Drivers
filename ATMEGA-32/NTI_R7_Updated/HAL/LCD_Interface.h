

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

typedef enum{
	LINE1,
	LINE2,
	LINE3,
	LINE4
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
	CELL16,
	CELL17,
	CELL18,
	CELL19,
	TOTAL_CELL
}LCD_CELL_type;

void LCD_voidInit();
void LCD_voidClear(void);
void LCD_voidGoToCell(LCD_Line_type copy_u8Line,LCD_CELL_type copy_u8Cell);
void LCD_voidWriteChar(u8 copy_u8character);
void LCD_voidWriteString(c8 *copy_u8String);
void LCD_voidClearNoCell(u8 copy_u8Line ,u8 copy_u8Cell,u8 copy_u8No_Cells);
void LCD_voidCreatCustomChar(u8 copy_u8Address,u8 *copy_u8Pattern);
void LCD_voidGoToWriteString(u8 copy_u8Line ,u8 copy_u8Cell,c8 *copy_u8String);
void LCD_voidWriteNumber(s32 copy_u8Number);
void LCD_voidWrite_4Digits(u16 copy_u8Number);
void LCD_voidWriteBinary(u8 copy_u8Number);
void LCD_voidWriteHex(u8 copy_u8Number);


#endif /* LCD_INTERFACE_H_ */
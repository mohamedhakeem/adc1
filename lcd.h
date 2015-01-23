/*
 * LCD.h
 *
 * Created: 4/2/2014 7:46:00 PM
 *  Author: Mohamed Tarek
 */ 

#ifndef LCD_H_
#define LCD_H_

#include "dio.h"


#define LCD_BIT_MODE 8
#define TWO_LINE_LCD_FOUR_BIT_MODE 0X28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38



#define LCD_CTRL_PORT 'D'
#define RS  4
#define RW  5
#define E   6



#define LCD_DATA_PORT 'C'

#if (LCD_BIT_MODE == 8)
#define D0 0
#define D1 1
#define D2 2
#define D3 3
#endif

#define D4 4
#define D5 5
#define D6 6
#define D7 7




#define CLEAR_COMMAND 0x01
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80 







void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_intgerToString(int data);

#endif /* LCD_H_ */
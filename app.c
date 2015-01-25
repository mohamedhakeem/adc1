/*
 * Exercise7.c
 *
 * Created: 4/3/2014 6:00:08 PM
 *  Author: Mohamed Tarek
 */ 

#include "lcd.h"
#include "lm35.h"
 

int main(void)
{
	
	LCD_init(); /* initialize LCD */
	LM35_init();
	
	LCD_displayStringRowColumn(0,0,"TEMPRUTURE");
	LCD_displayStringRowColumn(1,8,"C");
	
	uint8 temp ;
	//LCD_intgerToString(10);
	
    while(1)
    {
		temp=LM35_read();
		
		
	if (temp<100)
	{
		LCD_displayStringRowColumn(1,7," ");
		if (temp<10)
		{
			LCD_displayStringRowColumn(1,6," ");
		}
	}
	
	LCD_goToRowColumn(1,5);
	LCD_intgerToString(temp);	 
		
    }
	
}
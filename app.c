/*
 * Exercise7.c
 *
 * Created: 4/3/2014 6:00:08 PM
 *  Author: Mohamed Tarek
 */ 

#include "lcd.h"
#include "adc.h"
 

int main(void)
{
	
	LCD_init(); /* initialize LCD */
	ADC_init();
	
	LCD_displayStringRowColumn(0,0,"TEMPRUTURE");
	LCD_displayStringRowColumn(1,8,"C");
	
	uint32 temp , recevedVolt ;
	
	//LCD_intgerToString(10);
	
    while(1)
    {
		recevedVolt=ADC_read(ADC_PIN_NO);
		temp=(100*5*recevedVolt)/1023 ;
		
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
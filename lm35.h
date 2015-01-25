/*
 * LCD.h
 *
 * Created: 4/2/2014 7:46:00 PM
 *  Author: Mohamed Tarek
 */ 

#ifndef LCD_H_
#define LCD_H_

#include "adc.h"

#define LM35_CH_NO 5

void LM35_init();

uint8 LM35_read();


#endif

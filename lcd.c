/*
 * LCD.c
 *
 * Created: 4/2/2014 7:42:46 PM
 *  Author: Mohamed Tarek
 */

#include "LCD.h"



/*___________________________GLOBAL VARIBLES_______________________________________*/
/* intialize some structure for the LCD pins */ 


#if (LCD_BIT_MODE==8)
static DIO_Config   g_LCD_D0_Config ={LCD_DATA_PORT,D0,OUTPUT,LOGIC_LOW};
static DIO_Config   g_LCD_D1_Config ={LCD_DATA_PORT,D1,OUTPUT,LOGIC_LOW};
static DIO_Config   g_LCD_D2_Config ={LCD_DATA_PORT,D2,OUTPUT,LOGIC_LOW};
static DIO_Config   g_LCD_D3_Config ={LCD_DATA_PORT,D3,OUTPUT,LOGIC_LOW};
#endif

static DIO_Config   g_LCD_D4_Config ={LCD_DATA_PORT,D4,OUTPUT,LOGIC_LOW};
static DIO_Config   g_LCD_D5_Config ={LCD_DATA_PORT,D5,OUTPUT,LOGIC_LOW};
static DIO_Config   g_LCD_D6_Config ={LCD_DATA_PORT,D6,OUTPUT,LOGIC_LOW};
static DIO_Config   g_LCD_D7_Config ={LCD_DATA_PORT,D7,OUTPUT,LOGIC_LOW};



static DIO_Config   g_LCD_RS_Config ={LCD_CTRL_PORT,RS,OUTPUT,LOGIC_LOW};
static DIO_Config   g_LCD_RW_Config ={LCD_CTRL_PORT,RW,OUTPUT,LOGIC_LOW};
static DIO_Config   g_LCD_E_Config ={LCD_CTRL_PORT,E,OUTPUT,LOGIC_LOW};

/* LCD Data Configurations Structure */
/*********************************************************************************************/
/* Description: Called by the LED_Init function (only) used to fill the led configurations structure */
static void LCD_configurations(void)
{

#if (LCD_BIT_MODE==8)

DIO_setDirection(& g_LCD_D0_Config);		/* set the direction of the pin D0 in LCD */
DIO_writePin(& g_LCD_D0_Config);			/* set the Default s_value (initial value)*/
DIO_setDirection(& g_LCD_D1_Config);		/* set the direction of the pin D1 in LCD*/
DIO_writePin(& g_LCD_D1_Config);			/* set the Default value (initial value)*/
DIO_setDirection(& g_LCD_D2_Config);		/* set the direction of the pin D2 in LCD*/
DIO_writePin(& g_LCD_D2_Config);			/* set the Default value (initial value)*/
DIO_setDirection(& g_LCD_D3_Config);		/* set the direction of the pin D3 in LCD*/
DIO_writePin(& g_LCD_D3_Config);			/* set the Default value (initial value)*/
#endif
	


DIO_setDirection(& g_LCD_D4_Config);		/* set the direction of the pin D4 in LCD */
DIO_writePin(& g_LCD_D4_Config);			/* set the Default value (initial value) */
DIO_setDirection(& g_LCD_D5_Config);		/* set the direction of the pin D5 in LCD */
DIO_writePin(& g_LCD_D5_Config);			/*	set the Default value (initial value) */
DIO_setDirection(& g_LCD_D6_Config);		/* set the direction of the pin D6 in LCD */
DIO_writePin(& g_LCD_D6_Config);			/* set the Default value (initial value) */
DIO_setDirection(& g_LCD_D7_Config);		/* set the direction of the pin D7 in LCD */
DIO_writePin(& g_LCD_D7_Config);			/* set the Default value (initial value) */

DIO_setDirection(& g_LCD_RS_Config);		/* set the direction of the pin RS in LCD */
DIO_writePin(& g_LCD_RS_Config);			/* set the Default value (initial value) */
DIO_setDirection(& g_LCD_RW_Config);		/* set the direction of the pin RW in LCD */
DIO_writePin(& g_LCD_RW_Config);			/* set the Default value (initial value) */
DIO_setDirection(& g_LCD_E_Config);			/* set the direction of the pin E in LCD */
DIO_writePin(& g_LCD_E_Config);				/* set the Default value (initial value) */
} 

	
	


/*********************************************************************************************/



void LCD_init(void)
{
	LCD_configurations();			 /* fill the g_LCD_Config structure with the lCd configurations*/
	
	
	 
	 
	#if (LCD_BIT_MODE  == 8)
	
	 
	 
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);	/* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	
	

	#elif (LCD_BIT_MODE  == 4)

	LCD_sendCommand(0x02);
	LCD_sendCommand(TWO_LINE_LCD_FOUR_BIT_MODE);	/* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
	

	#endif
	
	LCD_sendCommand(CURSOR_OFF);					 /* cursor off */
	LCD_sendCommand(CLEAR_COMMAND);					 /* clear LCD at the beginning */
}



void LCD_sendCommand(uint8 command)
{
	g_LCD_RS_Config.s_value = LOGIC_LOW;
	DIO_writePin(& g_LCD_RS_Config);				/* Instruction Mode RS=0 */
	g_LCD_RW_Config.s_value = LOGIC_LOW;
	DIO_writePin(& g_LCD_RW_Config);				/* write data to LCD so RW=0 */
	_delay_ms(1);									/* delay for processing Tas = 50ns */
	g_LCD_E_Config.s_value = LOGIC_HIGH;
	DIO_writePin(& g_LCD_E_Config);					/* Enable LCD E=1 */
	_delay_ms(1);									/* delay for processing Tpw - Tdws = 190ns */
	
	#if (LCD_BIT_MODE  == 8)
	
	g_LCD_D0_Config.s_value = (command>>0) & 0x01;
	g_LCD_D1_Config.s_value = (command>>1) & 0x01;
	g_LCD_D2_Config.s_value = (command>>2) & 0x01;
	g_LCD_D3_Config.s_value = (command>>3) & 0x01;
	g_LCD_D4_Config.s_value = (command>>4) & 0x01;
	g_LCD_D5_Config.s_value = (command>>5) & 0x01;
	g_LCD_D6_Config.s_value = (command>>6) & 0x01;
	g_LCD_D7_Config.s_value = (command>>7) & 0x01;
	DIO_writePin(& g_LCD_D0_Config);
	DIO_writePin(& g_LCD_D1_Config);
	DIO_writePin(& g_LCD_D2_Config);
	DIO_writePin(& g_LCD_D3_Config);
	DIO_writePin(& g_LCD_D4_Config);
	DIO_writePin(& g_LCD_D5_Config);
	DIO_writePin(& g_LCD_D6_Config);
	DIO_writePin(& g_LCD_D7_Config);				 /* out the required command to the data bus D0 --> D7 */
	
	
	
	#elif (LCD_BIT_MODE  == 4)
		g_LCD_D4_Config.s_value = (command>>4) & 0x01;
		g_LCD_D5_Config.s_value = (command>>5) & 0x01;
		g_LCD_D6_Config.s_value = (command>>6) & 0x01;
		g_LCD_D7_Config.s_value = (command>>7) & 0x01;
		
		DIO_writePin(& g_LCD_D4_Config);
		DIO_writePin(& g_LCD_D5_Config);
		DIO_writePin(& g_LCD_D6_Config);
		DIO_writePin(& g_LCD_D7_Config);
	_delay_ms(1);									 /* delay for processing Tdsw = 100ns */
	g_LCD_E_Config.s_value = LOGIC_LOW;
	DIO_writePin(& g_LCD_E_Config);					 /* disable LCD E=0 */
	_delay_ms(1);									 /* delay for processing Tas = 50ns */
	g_LCD_E_Config.s_value = LOGIC_HIGH;
	DIO_writePin(& g_LCD_E_Config);					 /* Enable LCD E=1 */
	_delay_ms(1);									 /* delay for processing Tpw - Tdws = 190ns */
	g_LCD_D4_Config.s_value = (command>>0) & 0x01;
	g_LCD_D5_Config.s_value = (command>>1) & 0x01;
	g_LCD_D6_Config.s_value = (command>>2) & 0x01;
	g_LCD_D7_Config.s_value = (command>>3) & 0x01;
	
	DIO_writePin(& g_LCD_D4_Config);
	DIO_writePin(& g_LCD_D5_Config);
	DIO_writePin(& g_LCD_D6_Config);
	DIO_writePin(& g_LCD_D7_Config);
	#endif
	
	_delay_us(500);									 /* delay for processing Tdsw = 100ns */
	g_LCD_E_Config.s_value = LOGIC_LOW;
	DIO_writePin(& g_LCD_E_Config);					 /* disable LCD E=0 */
	_delay_ms(1);									 /* delay for processing Th = 13ns */
}

void LCD_displayCharacter(uint8 data)
{
	g_LCD_RS_Config.s_value = LOGIC_HIGH;
	DIO_writePin(& g_LCD_RS_Config);				/* Instruction Mode RS=0 */
	g_LCD_RW_Config.s_value = LOGIC_LOW;
	DIO_writePin(& g_LCD_RW_Config);				/* write data to LCD so RW=0 */
	_delay_ms(1);									/* delay for processing Tas = 50ns */
	g_LCD_E_Config.s_value = LOGIC_HIGH;
	DIO_writePin(& g_LCD_E_Config);					/* Enable LCD E=1 */
	_delay_ms(1);									/* delay for processing Tpw - Tdws = 190ns */
	
	#if (LCD_BIT_MODE  == 8)
	g_LCD_D0_Config.s_value = (data>>0) & 0x01;
	g_LCD_D1_Config.s_value = (data>>1) & 0x01;
	g_LCD_D2_Config.s_value = (data>>2) & 0x01;
	g_LCD_D3_Config.s_value = (data>>3) & 0x01;
	g_LCD_D4_Config.s_value = (data>>4) & 0x01;
	g_LCD_D5_Config.s_value = (data>>5) & 0x01;
	g_LCD_D6_Config.s_value = (data>>6) & 0x01;
	g_LCD_D7_Config.s_value = (data>>7) & 0x01;
	DIO_writePin(& g_LCD_D0_Config);
	DIO_writePin(& g_LCD_D1_Config);
	DIO_writePin(& g_LCD_D2_Config);
	DIO_writePin(& g_LCD_D3_Config);
	DIO_writePin(& g_LCD_D4_Config);
	DIO_writePin(& g_LCD_D5_Config);
	DIO_writePin(& g_LCD_D6_Config);
	DIO_writePin(& g_LCD_D7_Config);				 /* out the required command to the data bus D0 --> D7 */
	
	#elif (LCD_BIT_MODE  == 4)
	g_LCD_D4_Config.s_value = (data>>4) & 0x01;
	g_LCD_D5_Config.s_value = (data>>5) & 0x01;
	g_LCD_D6_Config.s_value = (data>>6) & 0x01;
	g_LCD_D7_Config.s_value = (data>>7) & 0x01;
	
	DIO_writePin(& g_LCD_D4_Config);
	DIO_writePin(& g_LCD_D5_Config);
	DIO_writePin(& g_LCD_D6_Config);
	DIO_writePin(& g_LCD_D7_Config);
	_delay_ms(1);									/* delay for processing Tdsw = 100ns */
	g_LCD_E_Config.s_value = LOGIC_LOW;
	DIO_writePin(& g_LCD_E_Config);					/* disable LCD E=0 */
	_delay_ms(1);									/* delay for processing Tas = 50ns */
	g_LCD_E_Config.s_value = LOGIC_HIGH;
	DIO_writePin(& g_LCD_E_Config);					/* Enable LCD E=1 */
	_delay_ms(1);									/* delay for processing Tpw - Tdws = 190ns */
	g_LCD_D4_Config.s_value = (data>>0) & 0x01;
	g_LCD_D5_Config.s_value = (data>>1) & 0x01;
	g_LCD_D6_Config.s_value = (data>>2) & 0x01;
	g_LCD_D7_Config.s_value = (data>>3) & 0x01;
	
	DIO_writePin(& g_LCD_D4_Config);
	DIO_writePin(& g_LCD_D5_Config);
	DIO_writePin(& g_LCD_D6_Config);
	DIO_writePin(& g_LCD_D7_Config);
	#endif
	
	_delay_us(500);									/* delay for processing Tdsw = 100ns */
	g_LCD_E_Config.s_value = LOGIC_LOW;
	DIO_writePin(& g_LCD_E_Config);					/* disable LCD E=0 */
	_delay_ms(1);									/* delay for processing Th = 13ns */
}

void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	/***************** Another Method ***********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}		
	*********************************************************/
}

void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address;
	
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}					
	/* to write to a specific address in the LCD 
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(Address | SET_CURSOR_LOCATION); 
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col);				/* go to to the required LCD position */
	
	LCD_displayString(Str);					/* display the string */
}

void LCD_intgerToString(int data)
{
   char buff[16];							/* String to hold the ascii result */
   itoa(data,buff,10);						/* 10 for decimal */
   LCD_displayString(buff);
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND);			/*clear display */ 
}	 




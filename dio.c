/* ---------------------------------------------------------------------------------------------------
[FILE NAME]		: dio.c
[AUTHOR(S)]		: Abdelrahman ElMaghraby
[DATE CREATED]	: 11/1/2015
[DESCRIPTION]	: Button module header file for this program
[VERSION]		: 1.0
--------------------------------------------------------------------------------------------------- */


#include "dio.h"

/******************************************************************************************************************/
void DIO_setDirection(const DIO_Config *a_configMsg)
{
	uint8 * ddr_Ptr;
	/* point to the required DDR Register */
	switch(a_configMsg->s_port)
	{
		case 'A': ddr_Ptr = &DDRA;
				  break;
		case 'B': ddr_Ptr = &DDRB;
				  break;
		case 'C': ddr_Ptr = &DDRC;
				  break;
		case 'D': ddr_Ptr = &DDRD;
				  break;
		default :
			break ;		  		  		  
	}
	if(a_configMsg->s_direction == OUTPUT)
	{
		MACRO_setBit(*ddr_Ptr,a_configMsg->s_pinNum); 	/* set the corresponding bit in the DDR register to configure it as output pin */
	}
	else if(a_configMsg->s_direction == INPUT)	
	{
		MACRO_clearBit(*ddr_Ptr,a_configMsg->s_pinNum);		 /* clear the corresponding bit in the DDR register to configure it as input pin */
	}
	else
	{
	}				
}
/*******************************************************************************************************************/
void DIO_writePin(const DIO_Config * a_state)
{
	uint8 * port_Ptr;
	/* point to the required PORT Register */
	switch(a_state->s_port)
	{
		case 'A': port_Ptr = &PORTA;
				  break;
		case 'B': port_Ptr = &PORTB;
				  break;
		case 'C': port_Ptr = &PORTC;
				  break;
		case 'D': port_Ptr = &PORTD;
				  break;
		default :
			break ;		  		  		  
	}
	if(a_state->s_value == LOGIC_HIGH)
	{
		MACRO_setBit(*port_Ptr,a_state->s_pinNum); 		/*set the corresponding pin in the PORT register */
	}				
    else if(a_state->s_value == LOGIC_LOW)
	{
        MACRO_clearBit(*port_Ptr,a_state->s_pinNum); 	/*clear the corresponding pin in the PORT register */
	}
	else
	{
	}		
}
/*******************************************************************************************************************/
uint8 DIO_readPin(const DIO_Config * a_state)
{
	uint8 * pin_Ptr;
	uint8  output;
	/* point to the required pin Register */
	switch(a_state->s_port)
	{
		case 'A': pin_Ptr = &PINA;
				  break;
		case 'B': pin_Ptr = &PINB;
				  break;
		case 'C': pin_Ptr = &PINC;
				  break;
		case 'D': pin_Ptr = &PIND;
				  break;
		default :
			break ;	  		  		  
	}
	if(MACRO_bitIsSet(*pin_Ptr,a_state->s_pinNum)) 		/*check if the corresponding bit is set in the PORT register */
	{ 
		output =  LOGIC_HIGH;
	}
	else if(MACRO_bitIsClear(*pin_Ptr,a_state->s_pinNum)) /*check if the corresponding bit is clear in the PORT register */
	{
		output = LOGIC_LOW;
	}
	else
	{
	}
	return output;	
}
/********************************************************************************************************************/
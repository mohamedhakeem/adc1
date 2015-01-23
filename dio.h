/* ---------------------------------------------------------------------------------------------------
[FILE NAME]		: dio.h
[AUTHOR(S)]		: Abdelrahman ElMaghraby
[DATE CREATED]	: 11/1/2015
[DESCRIPTION]	: data input output module 
[VERSION]		: 1.0
--------------------------------------------------------------------------------------------------- */

#ifndef DIO_H_
#define DIO_H_

#include "std_type.h"
#include "common_macro.h"
#include "micro_config.h"

#define INPUT 0
#define OUTPUT 1

#define LOGIC_HIGH 1
#define LOGIC_LOW 0

/***********************************************STRUCTURE**************************************************
 * [STRUCTURE NAME]	: DIO_CONFIG
 * [DESCRIPTION]	: Structure to describe each individual PIN contains:
 *						  1. the PORT Which the pin belongs to. 'A 'B' 'C' or 'D'
 *						  2. the number of the pin in the PORT.
 *						  3. the direction of pin --> INPUT or OUTPUT
 *						  4. the value of the pin 
***********************************************************************************************************/
typedef struct {
	uint8 s_port; 		/* 1. the PORT Which the pin belongs to. 'A 'B' 'C' or 'D' */ 
	uint8 s_pinNum; 	/* 2. the number of the pin in the PORT. */
	uint8 s_direction;	/* 3. the direction of pin --> INPUT or OUTPUT */ 
	uint8 s_value; 		/* 4. the value of the pin  */
}DIO_Config;
/********************************************END OF STRUCTURE***********************************************/


/* ------------------------------------------FUNCTION---------------------------------------------------------
[Function Name] : DIO_setDirection
[Description] 	: configure the PIN to input or output pin.
[Args]			: a_configMsg
[in] type _ name: pointer to structure ->  a_configMsg:
[Description] 	: has the data about the wanted pin
[Returns] 		: void 
----------------------------------------------------------------------------------------------------------- */
void DIO_setDirection(const DIO_Config *a_configMsg );



/* ------------------------------------------FUNCTION------------------------------------------------------------
[Function Name] : DIO_writePin
[Description] 	: write 1 or 0 on the pin.
[Args]			: a_state
[in] type _ name: pointer to structure ->  a_state
[Description] 	: has the data about the wanted pin 
[Returns] 		: void 
--------------------------------------------------------------------------------------------------------------- */
void DIO_writePin(const DIO_Config * a_state);



/* -------------------------------------------FUNCTION-----------------------------------------------------------
[Function Name] : DIO_readPin
[Description] 	:read the pin.
[Args]			:  a_state
[in] type _ name: pointer to structure ->   a_state:
[Description] 	: has the data about the wanted pin 
[Returns] 		: value of wanted pin 
---------------------------------------------------------------------------------------------------------------- */
uint8 DIO_readPin(const DIO_Config * a_state);




#endif /* DIO_H_ */
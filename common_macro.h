/* ---------------------------------------------------------------------------------------------------
[FILE NAME]		: common_macro.h
[AUTHOR(S)]		: Abdelrahman ElMaghraby
[DATE CREATED]	: 11/1/2015
[DESCRIPTION]	: Common macros module header file for this program
[VERSION]		: 1.0
--------------------------------------------------------------------------------------------------- */

#ifndef COMMON_MACRO_H_
#define COMMON_MACRO_H_

#define MACRO_setBit(reg,bitNum) ( reg = reg | (1<<bitNum) ) 		/* Set a certain bit in any register */

#define MACRO_clearBit(reg,bitNum) ( reg = reg & (~(1<<bitNum)) ) 	/*clear a certain bit in any register */

#define MACRO_bitIsSet(reg,bitNum) ( reg & (1<<bitNum) ) 			/*check if any bit is set in any register and return true if yes */

#define MACRO_bitIsClear(reg,bitNum) ( !(reg & (1<<bitNum)) ) 		/*check if any bit is clear in any register and return true if yes */


#define TOGGLE_bitNum(reg,bitNum) (reg^=(1<<bitNum))				/* Toggle a certain bit in any register */


#define ROR(reg,bitNum) ( reg= (reg>>bitNum) | (reg<<(8-bitNum)) )	/* Rotate right the register value with specific bitNumber of rotates */


#define ROL(reg,bitNum) ( reg= (reg<<bitNum) | (reg>>(8-bitNum)) )	/* Rotate left the register value with specific bitNumber of rotates */


#endif /* COMMON_MACRO_H_ */

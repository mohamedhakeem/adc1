/*
 * adc.c
 *
 * Created: 16/01/2015 02:29:47 م
 *  Author: Maghraby
 */ 


#include "adc.h"


void ADC_init(void)
{
	MACRO_clearBit(ADMUX,REFS0);		/*Bit 7:6 – REFS1:0: Reference Selection Bits >>AREF */
	MACRO_clearBit(ADMUX,REFS1);		/*Bit 7:6 – REFS1:0: Reference Selection Bits >>AREF */
	MACRO_clearBit(ADMUX,ADLAR);		/*Bit 5 – ADLAR: ADC Left Adjust Result */
	MACRO_setBit(ADCSRA,ADEN);			/* Bit 7 – ADEN: ADC Enable */
	MACRO_setBit(ADCSRA,ADPS0);			/* Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits >>8 */
	MACRO_setBit(ADCSRA,ADPS1);			/* Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits >>8 */
	MACRO_clearBit(ADCSRA,ADPS2);		/* Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits >>8 */
	
}

uint16 ADC_read(uint8 a_pinNo)
{
	ADMUX&=0xF8;							/* clear the no of pins to set new one */
	ADMUX|=(a_pinNo & 0x07);
	MACRO_setBit(ADCSRA,ADSC);				/* Bit 6 – ADSC: ADC Start Conversion */
	
	while(MACRO_bitIsClear(ADCSRA,ADIF));   /* Bit 4 – ADIF: ADC Interrupt Flag */
	{
		
	}
	MACRO_setBit(ADCSRA,ADIF);				/* Bit 4 – ADIF: ADC Interrupt Flag >> 1 (rest) */
	return ADC ;
	
}
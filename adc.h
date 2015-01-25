/*
 * adc.h
 *
 * Created: 16/01/2015 02:31:26 م
 *  Author: Maghraby
 */ 


#ifndef ADC_H_
#define ADC_H_

#define ADC_PIN_NO 5

#include "std_type.h"
#include "common_macro.h"
#include "micro_config.h"

void ADC_init(void);

uint16 ADC_read(uint8 a_pinNo);
 




#endif /* ADC_H_ */
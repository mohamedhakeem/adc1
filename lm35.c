	
	#include "lm35.h"
	void LM35_init()
	{
		ADC_init();
	}
	
	uint8 LM35_read()
	{
		uint32  recevedVolt ;
		uint8 temp ;
		recevedVolt=ADC_read(LM35_CH_NO);
		temp=(100*5*recevedVolt)/1023 ;
		return temp ;
	}
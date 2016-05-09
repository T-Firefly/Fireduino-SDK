 /**
 * @file wirish_analog.c
 * @brief Definitions wirish_analog class for Fireduino
 * @author jiang<jdz@t-chip.com.cn> 
 * @version V1.0
 * @date 2016.02
 * 
 * @par Copyright:
 * Copyright (c) 2016 T-CHIP INTELLIGENCE TECHNOLOGY CO.,LTD. \n\n
 *
 * For more information, please visit website <http://www.t-firefly.com/>, \n\n
 * or email to <service@t-firefly.com>.
 */ 
#include "wirish_analog.h"


/* Unlike Wiring and Arduino, this assumes that the pin's mode is set
 * to INPUT_ANALOG. That's faster, but it does require some extra work
 * on the user's part. Not too much, we think ;). */
void analogReference(eAnalogReference type)
{
	ardAdcReferenceSet(type);
}

uint16_t analogRead(uint8_t pin){
	if (!gAdcInitFlag)
		ardAdcInit();
	return ard_adc_read(pin);
    //return 0;
}

void analogWrite(uint8_t pin,uint32_t duty_cycle)
{
	pwmWrite(pin,duty_cycle);
}

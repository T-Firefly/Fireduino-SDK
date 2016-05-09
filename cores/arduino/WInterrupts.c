 /**
 * @file WInterrupts.c
 * @brief Definitions WInterrupts class for Fireduino
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
#include "WInterrupts.h"
#include "ard_gpio.h"


void attachInterrupt(unsigned long pin, void (*callback)(void), unsigned long mode)
{
	ard_gpio_int_enable(pin,callback,mode);
}

void detachInterrupt(unsigned long pin)
{
	ard_gpio_int_disable(pin);
}






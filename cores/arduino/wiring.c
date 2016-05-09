 /**
 * @file wiring.c
 * @brief Definitions wiring class for Fireduino
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
#include <ard_sys.h>
#include <stdint.h>

#include "wiring.h"



uint32_t millis( void )
{
	double t = ((double)SysTickPeriodGet()-(double)SysTickValueGet())/(double)SysTickPeriodGet();
	t *= 10;

	return get_SystickCount() * 10 + (uint32_t)t;
}

uint32_t micros( void )
{
	double t = ((double)SysTickPeriodGet()-(double)SysTickValueGet())/(double)SysTickPeriodGet();
	t *= 10;
	t *= 1000;

	return (get_SystickCount() * 1000 * 10 + (uint32_t)t);
}

void yield(void){ } //do nothing!

void delay( uint32_t ms )
{
	Delay_Ms(ms);
}

void delayMicroseconds(uint32_t us)
{
	DelayUs(us);
}

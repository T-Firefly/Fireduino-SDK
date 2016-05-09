 /**
 * @file wirish_shift.c
 * @brief Definitions wirish_shift class for Fireduino
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
#include "wirish_shift.h"
#include "wirish_digital.h"
#include "wirish_constants.h"

unsigned char shiftIn(unsigned char ulDataPin, unsigned char ulClockPin, unsigned char ulBitOrder)
{
	unsigned char value = 0 ;
	unsigned char i ;

	for ( i=0 ; i < 8 ; ++i )
    {
		digitalWrite( ulClockPin, HIGH ) ;

		if (ulBitOrder == LSBFIRST)
        {
			value |= digitalRead( ulDataPin ) << i ;
        }
		else
        {
			value |= digitalRead( ulDataPin ) << (7 - i) ;
        }

		digitalWrite( ulClockPin, LOW ) ;
	}

	return value ;
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t value)
{
	unsigned char i ;

	for ( i=0 ; i < 8 ; i++ )
    {
		if ( bitOrder == LSBFIRST )
        {
			digitalWrite( dataPin, !!(value & (1 << i)) ) ;
        }
		else
        {
			digitalWrite( dataPin, !!(value & (1 << (7 - i))) ) ;
        }

		digitalWrite( clockPin, HIGH ) ;
		digitalWrite( clockPin, LOW ) ;
	}
}

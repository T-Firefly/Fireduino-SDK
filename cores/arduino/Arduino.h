 /**
 * @file Arduino.h
 * @brief Definitions Arduino class for Fireduino
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
#ifndef _WIRISH_WPROGRAM_H_
#define _WIRISH_WPROGRAM_H_

#include "wirish.h"

void setup();
void loop();
extern void tone(unsigned int pin,unsigned int freq,unsigned int duration = 0);
extern void noTone(unsigned int pin);
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus
void yield(void);
#ifdef __cplusplus
}
#endif // __cplusplus



#define digitalPinToPort(P)        ( _get_port(P))
#define digitalPinToBitMask(P)     ( _get_mask(P) )
#define portOutputRegister(port)   ( _get_dr(port) )
#define portInputRegister(port)   ( _get_ind(port) )
#define portDirectRegister(port)   ( _get_ddr(port) )

//#include "variant.h"
#define NUM_DIGITAL_PINS 30

#endif

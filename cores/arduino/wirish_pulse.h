 /**
 * @file wirish_pulse.h
 * @brief Definitions wirish_pulse class for Fireduino
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
#ifndef ARDUINO_WIRISH_PULSE_H_
#define ARDUINO_WIRISH_PULSE_H_

#include "wirish_digital.h"

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t pulseIn( uint32_t pin, uint32_t state, uint32_t timeout );

#ifdef __cplusplus
}
#endif



#endif /* ARDUINO_WIRISH_PULSE_H_ */

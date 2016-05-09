 /**
 * @file WInterrupts.h
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
#ifndef ARDUINO_CORES_WINTERRUPTS_H_
#define ARDUINO_CORES_WINTERRUPTS_H_

#include "ard_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif


void attachInterrupt(unsigned long pin, void (*callback)(void), unsigned long mode);
void detachInterrupt(unsigned long pin);

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_CORES_WINTERRUPTS_H_ */

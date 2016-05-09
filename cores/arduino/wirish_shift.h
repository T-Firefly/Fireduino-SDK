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
#include "io.h"

#ifndef ARDUINO_CORES_WIRISH_SHIFT_H_
#define ARDUINO_CORES_WIRISH_SHIFT_H_

#ifdef __cplusplus
extern "C" {
#endif

unsigned char shiftIn(unsigned char ulDataPin, unsigned char ulClockPin, unsigned char ulBitOrder);
//void shiftOut(unsigned long ulDataPin, unsigned long ulClockPin, unsigned long ulBitOrder, unsigned long ulVal);

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_CORES_WIRISH_SHIFT_H_ */

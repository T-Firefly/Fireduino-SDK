 /**
 * @file wirish_digital.h
 * @brief Definitions wirish_digital class for Fireduino
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
#ifndef ARDUINO_CORES_WIRISH_DIGITAL_H_
#define ARDUINO_CORES_WIRISH_DIGITAL_H_

#include "ard_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

void togglePin(unsigned char pin);
unsigned char isButtonPressed(unsigned char pin, unsigned long pressedLevel);
unsigned char waitForButtonPress(unsigned long timeout);

#ifdef __cplusplus
}
#endif



#endif /* ARDUINO_CORES_WIRISH_DIGITAL_H_ */

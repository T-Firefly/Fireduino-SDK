 /**
 * @file wirish_analog.h
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
#ifndef ARDUINO_CORES_ARDUINO_WIRISH_ANALOG_H_
#define ARDUINO_CORES_ARDUINO_WIRISH_ANALOG_H_

#include "io.h"
#include "ard_adc.h"
#include "ard_pwm.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void analogReference(eAnalogReference type);

#ifdef __cplusplus
}
#endif




#endif /* ARDUINO_CORES_ARDUINO_WIRISH_ANALOG_H_ */

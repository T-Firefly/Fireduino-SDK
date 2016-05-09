 /**
 * @file ard_gpio.h
 * @brief Definitions gpio driver header for Fireduino
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
#ifndef ARDUINO_LIB_ARD_GPIO_H_
#define ARDUINO_LIB_ARD_GPIO_H_

#include "io.h"

#ifdef __cplusplus
extern "C" {
#endif



#define	BUTTON_DEBOUNCE_DELAY	1

#define	BOARD_BUTTON_PIN		2

#define	PIN_MAX	30

enum int_tri_mode
{
	T_LOW = 0,
	T_HIGH,
	T_RISE,
	T_FALL,
};


extern void ard_pin_mode(unsigned char pin, WiringPinMode mode);
extern uint32_t ard_gpio_read(unsigned char pin);
extern void ard_gpio_write(unsigned char pin, unsigned char val);
extern void ard_gpio_int_enable(uint32_t pin,void (*callback)(void),enum int_tri_mode mode);
extern void ard_gpio_int_disable(uint32_t pin);
extern void interrupts(void);
extern void noInterrupts(void);
unsigned int _get_port(unsigned int  pin);
unsigned int  _get_mask(unsigned int  pin);
unsigned int*  _get_dr(unsigned int  port);
unsigned int*  _get_ind(unsigned int  port);
unsigned int*  _get_ddr(unsigned int  port);

#ifdef __cplusplus
}
#endif





#endif /* ARDUINO_LIB_ARD_GPIO_H_ */

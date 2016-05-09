 /**
 * @file ard_servo.h
 * @brief Definitions servo driver for Fireduino
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
#ifndef _ARDUINO_SERVO_H_
#define _ARDUINO_SERVO_H_


#ifdef __cplusplus
extern "C" {
#endif

typedef void (*pFun_isr)(void);

extern unsigned int ard_servo_clock_us(void);
extern void ard_servo_timer_set(unsigned char dev,unsigned int ticktime);
extern void ard_servo_timer_disable(unsigned char dev);
extern void ard_servo_timer_isr(unsigned char dev,pFun_isr isr);

#ifdef __cplusplus
}
#endif


#endif



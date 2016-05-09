 /**
 * @file ard_pwm.h
 * @brief Definitions pwm driver header for Fireduino
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
#ifndef ARDUINO_LIB_ARD_PWM_H_
#define ARDUINO_LIB_ARD_PWM_H_


#ifdef __cplusplus
extern "C" {
#endif

extern unsigned long gPwmMastFlag;
extern unsigned char gPwmTimer;


//void pwmWrite(unsigned char pin, unsigned int duty_cycle16);

//void analogWrite(unsigned char pin, int duty_cycle8);
void pwmWrite(unsigned char pin, unsigned int duty_cycle);
extern void pwminit(void);
extern void pwmdisinit(void);

#ifdef __cplusplus
}
#endif




#endif /* ARDUINO_LIB_ARD_PWM_H_ */

 /**
 * @file ard_timer.h
 * @brief Definitions timer driver header for Fireduino
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
#ifndef ARDUINO_LIB_ARD_TIME_H_
#define ARDUINO_LIB_ARD_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif


typedef     void (*pFunc)(void);

typedef enum _TIMER_CHANNEL
{
    ARD_TIMER0 = 0,
    ARD_TIMER1,
    ARD_TIMER_MAX
}eTIMER_CHANNEL;


extern void ard_timer_init(unsigned char timer_ch,pFunc callback);
extern void ard_timer_start(unsigned long timerChannel);
extern void ard_timer_stop(unsigned long timerChannel);
extern void ard_timer_set_count(unsigned long timerChannel,unsigned long long usTick);

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_LIB_ARD_TIME_H_ */

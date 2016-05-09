 /**
 * @file wirish_tone.h
 * @brief Definitions wirish_tone class for Fireduino
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
#ifndef WIRISH_TONE_H_
#define WIRISH_TONE_H_
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//

//unsigned int pin
//#ifdef __cplusplus
//}
//#endif

extern void tone(unsigned int pin,unsigned int freq,unsigned int duration);
extern void noTone(unsigned int pin);



#endif /* WIRISH_TONE_H_ */

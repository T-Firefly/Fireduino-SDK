 /**
 * @file ard_debug.h
 * @brief Definitions debug api for Fireduino
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
#ifndef ARDUINO_LIB_ARD_DEBUG_H_
#define ARDUINO_LIB_ARD_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif

void dbg_print(const char *s);
void dbg_println(const char *x);
void dbg_print_hex(int x);
void dbg_print_num(int x);

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_LIB_ARD_DEBUG_H_ */

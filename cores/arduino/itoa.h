 /**
 * @file itoa.h
 * @brief Definitions itoa class for Fireduino
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
#ifndef _ITOA_
#define _ITOA_

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#if 0

extern void itoa( int n, char s[] ) ;

#else

extern char* itoa( int value, char *string, int radix ) ;
extern char* ltoa( long value, char *string, int radix ) ;
extern char* utoa( unsigned long value, char *string, int radix ) ;
extern char* ultoa( unsigned long value, char *string, int radix ) ;
#endif /* 0 */

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // _ITOA_

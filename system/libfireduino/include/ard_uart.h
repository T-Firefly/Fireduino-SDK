 /**
 * @file ard_uart.h
 * @brief Definitions uart driver header class for Fireduino
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
#ifndef _ARDUINO_UART_H_
#define _ARDUINO_UART_H_


#ifdef __cplusplus
extern "C" {
#endif

extern void ard_uart_init(unsigned char dev,unsigned int baudRate ,unsigned char databit,unsigned char stopbit,unsigned char parity);
extern void ard_uart_disable(unsigned char dev);
extern unsigned int ard_uart_putc(unsigned char dev,unsigned char byte);
extern unsigned char ard_uart_getc(unsigned char dev);
extern unsigned char ard_uart_peek(unsigned char dev);
extern unsigned int ard_uart_data_available(unsigned char dev);
extern void ard_uart_flush(unsigned char dev);

#ifdef __cplusplus
}
#endif


#endif



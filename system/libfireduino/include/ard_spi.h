 /**
 * @file ard_spi.h
 * @brief Definitions spi driver header for Fireduino
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
#ifndef _ARDUINO_SPI_H_
#define _ARDUINO_SPI_H_


#ifdef __cplusplus
extern "C" {
#endif

extern void ard_spi_pin(void);
extern void ard_spi_io_init(void);
extern void ard_spi_io_deinit(void);
extern void ard_spi_init(void);
extern void ard_spi_deinit(void);
extern void ard_spi_setBitOrder(unsigned char order);
extern void ard_spi_setDataMode(unsigned char mode);
extern void ard_spi_setClockDivider(unsigned short div);
extern unsigned char ard_spi_transfer(unsigned char data);
extern unsigned short ard_spi_transfer16(unsigned short data);
extern void ard_spi_cs(unsigned char flag);
extern void ard_spi_reset(unsigned char flag);
extern unsigned char ard_spi_version(void);
extern void ard_spi_test(void);
#ifdef __cplusplus
}
#endif


#endif



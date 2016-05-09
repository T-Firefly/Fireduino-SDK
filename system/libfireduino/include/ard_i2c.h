 /**
 * @file ard_i2c.h
 * @brief Definitions i2c driver header for Fireduino
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
#ifndef _ARDUINO_I2C_H_
#define _ARDUINO_I2C_H_


#ifdef __cplusplus
extern "C" {
#endif

extern void ard_i2c_init(unsigned char dev);
extern void ard_i2c_deinit(unsigned char dev);
extern void ard_i2c_start(unsigned char dev,unsigned char txAddress);
extern void ard_i2c_write(unsigned char dev,unsigned char txAddress,unsigned char *data,unsigned short len);
extern unsigned char  ard_i2c_read(unsigned char dev,unsigned char txAddress,unsigned char *data,unsigned short len);

#ifdef __cplusplus
}
#endif


#endif



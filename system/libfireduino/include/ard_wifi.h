 /**
 * @file ard_wifi.h
 * @brief Definitions wifi driver headers for Fireduino
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
#ifndef _ARDUINO_WIFI_H_
#define _ARDUINO_WIFI_H_


#ifdef __cplusplus
extern "C" {
#endif
#include "IPAddress.h"

extern void ard_wifi_init(void);
extern int ard_wifi_connect(char* ssid ,char *pass);
extern IPAddress ard_wifi_get_ip_addr(void);
#ifdef __cplusplus
}
#endif


#endif



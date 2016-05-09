 /**
 * @file autoLoad.h
 * @brief Definitions autoLoad Demo for Fireduino
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
#ifdef __cplusplus
extern "C" {
#endif

#define	ADDR_ENTER_MASKROM	0x0000008c
#define	ADDR_GENERAL_RESET	0x00000000

#define	FLAG_ENTER_LOADER	0x02
#define	FLAG_GENERAL_RESET	0x01



extern int autoLoadInit(void);
extern int autoLoadStart();
extern void systemAutoLoad(void);


#ifdef __cplusplus
}
#endif





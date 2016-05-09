 /**
 * @file ard_adc.h
 * @brief Definitions adc driver header for Fireduino
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
#ifndef ARDUINO_LIB_ARD_ADC_H_
#define ARDUINO_LIB_ARD_ADC_H_

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned char gAdcInitFlag;

typedef enum _eAnalogReference
{
	INTERNAL2V56,
}eAnalogReference;


extern void ardAdcInit(void);
extern unsigned long ard_adc_read(unsigned char ch);
extern void ardAdcReferenceSet(eAnalogReference type);

#ifdef __cplusplus
}
#endif


#endif /* ARDUINO_LIB_ARD_ADC_H_ */

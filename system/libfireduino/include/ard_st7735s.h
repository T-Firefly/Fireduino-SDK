 /**
 * @file ard_st7735s.h
 * @brief Definitions st7735s driver header for Fireduino
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
#ifndef _ARDUINO_ST7735S_H_
#define _ARDUINO_ST7735S_H_


#ifdef __cplusplus
extern "C" {
#endif

extern void ard_lcd_init(void);
extern void ard_lcd_backlight(unsigned char bl);
extern void ard_writecommand(unsigned int cmd);
extern void ard_writedata(unsigned int dat);
extern void ard_VopSendData(unsigned int d);

extern void ard_ST7735S_ScreenUpdate(void* PanelBuf);
extern void ard_ST7735S_Image(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned short *pSrc);
extern void ard_ST7735S_Clear(unsigned short color);
extern void ard_ST7735S_SetWindow(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1);
extern void ard_ST7735S_Standby(void);
extern void ard_ST7735S_WakeUp(void);
extern void ard_ST7735S_Init(void);
extern void ard_ST7735S_WriteRAM_Prepare(void);
extern void ard_ST7735S_Rotation(unsigned int r);
extern void ard_ST7735S_ClrSrc(void);
extern void ard_ST7735S_ClrRect(unsigned short x0,unsigned short y0,unsigned short x1,unsigned short y1);

#ifdef __cplusplus
}
#endif


#endif

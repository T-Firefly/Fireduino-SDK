 /**
 * @file ard_sd.h
 * @brief Definitions sd interface driver header for Fireduino
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
#ifndef _ARDUINO_SD_H_
#define _ARDUINO_SD_H_


#ifdef __cplusplus
extern "C" {
#endif

extern int ard_sd_init(void);
extern void ard_sd_deinit(void);
extern unsigned char ard_sd_cd(void);
extern void * ard_sd_open(char* path,unsigned char mode ,unsigned char *is_dir);
extern unsigned int ard_sd_write(void * file,void *buf,unsigned int len);
extern unsigned int ard_sd_read(void * file,void *buf,unsigned int len);
extern unsigned int ard_sd_position(void * file);
extern unsigned int ard_sd_seek(void * file ,unsigned int seek);
extern unsigned int ard_sd_size(void * file);
extern void ard_sd_flush(void * file);
extern unsigned int ard_sd_close(void * file);
extern unsigned char ard_sd_exists(char *file_path);
extern unsigned char ard_sd_mkdir(char *file_path);
extern unsigned char ard_sd_remove(char *file_path);
extern unsigned char ard_sd_rmdir(char *file_path);
extern unsigned char ard_sd_scandir(const char *filepath,
		unsigned char (*callback)(const char *filename, int isFile),
		int onlyScanFiles);

#ifdef __cplusplus
}
#endif


#endif

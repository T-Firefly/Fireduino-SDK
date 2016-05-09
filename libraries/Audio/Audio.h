 /**
 * @file audio.h
 * @brief Definitions audio class for Fireduino
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
#ifndef _AUDIO_H
#define _AUDIO_H

#include "Arduino.h"

// playing status
typedef enum
{
	AudioFailed = 0,
	AudioPlay ,
	AudioPause ,
	AudioStop ,
}AudioStatus;


typedef enum
{
	AUDIO_SD,         // SD
	AUDIO_NET    		// NET

}Storage;

class AudioClass {
public:
	AudioClass() { };
public:
	void 	begin(Storage st);
	void    playFile(const char *path);
	void    playFile(const wchar_t* path);
	void    playNetFile(const char* path);
	void    setVolume(unsigned char volume);
	unsigned char getVolume(void);
	void    pause(void);
	void    resume(void);
	void    stop(void);
	AudioStatus    getStatus(void);
	void	end(void);
	operator bool();

public:
	bool init_flag = false;
	Storage _st;
};

extern AudioClass Audio;

#endif

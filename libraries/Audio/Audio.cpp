 /**
 * @file audio.c
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
#include <ard_audio.h>
#include <string.h>
#include <wchar.h>
#include "Audio.h"



void AudioClass::begin(Storage st){
	_st = st;
	if(ard_audio_init(st) == 0)
	{
		init_flag = true;
	}
	else
	{
		init_flag = false;
	}
}



extern "C" unsigned int  Ascii2Unicode(unsigned char * pbAscii, unsigned short * pwUnicode, unsigned int len);
void AudioClass::playFile(const char *path){
	int i;
	unsigned short path_t[256];
	if(_st == AUDIO_SD)
	{
		Ascii2Unicode((unsigned char *)path,(unsigned short *)path_t,strlen(path)*2);
		path_t[strlen(path)] = 0x0000;
		i = ard_audio_playfile((wchar_t*)path_t);
		while(i);
	}
}

void AudioClass::playFile(const wchar_t* path){
	if(_st == AUDIO_SD)
	{
		ard_audio_playfile(path);
	}
}

void AudioClass::playNetFile(const char* path)
{
	if(_st == AUDIO_NET)
	{
		ard_audio_playnetfile(path);
	}
}

void AudioClass::setVolume(unsigned char volume){
	ard_audio_setVolume(volume);
}

unsigned char AudioClass::getVolume(){
	return ard_audio_getVolume();
}

void AudioClass::pause(){
	ard_audio_pause();
}

void AudioClass::resume(){
	ard_audio_resume();
}

void AudioClass::stop(){
	ard_audio_stop();
}

AudioStatus AudioClass::getStatus(){
      return (AudioStatus)ard_audio_getStatus();;
}

void AudioClass::end(){
	ard_audio_stop();
	ard_audio_end();
	init_flag = false;
}

AudioClass::operator bool() {
  return init_flag;
}

AudioClass Audio;


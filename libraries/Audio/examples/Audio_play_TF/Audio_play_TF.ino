 /**
 * @file Audio_play_TF.ino
 * @brief Definitions Audio_play_TF Demo for Fireduino
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
#include <Arduino.h>
#include "TF.h"
#include "Audio.h"

void setup() {
	Serial.begin(115200);
	Serial.print("\r\narduino setup ...\r\n");

	if(!SD.begin())
	{
		Serial.println("sd init err\r\n");
		while(1);
	}

	Audio.begin(AUDIO_SD);
	if(Audio)
	{
		Audio.playFile("\\4.MP3");
	}

}

void loop() {
	Serial.println("loop");
	delay(2000);
	if(Audio.getStatus() == AudioStop)
	{
		Audio.playFile("\\3.MP3");
	}
}


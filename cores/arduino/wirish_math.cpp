 /**
 * @file wirish_math.cpp
 * @brief Definitions wirish_math class for Fireduino
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
#include "stdlib.h"
#include "wirish_math.h"

void randomSeed(unsigned int seed) {
    if (seed != 0) {
        srand(seed);
    }
}

long random(long howbig) {
    if (howbig == 0) {
        return 0;
    }

    return rand() % howbig;
}

long random(long howsmall, long howbig) {
    if (howsmall >= howbig) {
        return howsmall;
    }

    long diff = howbig - howsmall;
    return random(diff) + howsmall;
}

unsigned short makeWord( unsigned short w )
{
  return w ;
}

unsigned short makeWord(unsigned char h,unsigned char l )
{
  return (h << 8) | l ;
}

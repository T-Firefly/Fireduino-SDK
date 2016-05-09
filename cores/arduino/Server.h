 /**
 * @file Server.h
 * @brief Definitions Server class for Fireduino
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
#ifndef server_h
#define server_h

#include "Print.h"

class Server : public Print {
public:
  virtual void begin() =0;
  virtual ~Server() {}
};

#endif

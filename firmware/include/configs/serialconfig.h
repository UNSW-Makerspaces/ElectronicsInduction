#ifndef _SERIALCONFIG_H_
#define _SERIALCONFIG_H_

#include "gamepad_config.h"

class SerialConfig : public GPConfig {
public:
    virtual void setup();
    virtual void loop();
private:
};

#endif

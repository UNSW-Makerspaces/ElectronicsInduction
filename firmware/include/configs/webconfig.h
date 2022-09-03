#ifndef _WEBCONFIG_H_
#define _WEBCONFIG_H_

#include "gamepad_config.h"

class WebConfig : public GPConfig {
public:
    virtual void setup();
    virtual void loop();
private:
};

#endif

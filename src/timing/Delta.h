#ifndef LED_CONTROLLER_DELTA_H
#define LED_CONTROLLER_DELTA_H

#include "platform/Platform.h"

class Delta {
public:
    explicit Delta(Platform *platform) : _platform(platform) {
        _lastUpdate = _platform->Millis();
    };

    unsigned int update();

private:
    Platform *_platform;
    unsigned int _lastUpdate;
};

#endif //LED_CONTROLLER_DELTA_H

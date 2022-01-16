#ifndef CUBE_ARDUINO_SDK_DELTA_H
#define CUBE_ARDUINO_SDK_DELTA_H

#include "platform/Platform.h"

class Delta {
public:
    explicit Delta(Platform *platform) : _platform(platform) {
        _lastUpdate = _platform->millis();
    };

    unsigned int update();

private:
    Platform *_platform;
    unsigned int _lastUpdate;
};

#endif //CUBE_ARDUINO_SDK_DELTA_H

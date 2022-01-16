#ifndef CUBE_ARDUINO_SDK_UTILS_H
#define CUBE_ARDUINO_SDK_UTILS_H

namespace cube {
    static long map(long x, long in_min, long in_max, long out_min, long out_max) {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
}

#endif //CUBE_ARDUINO_SDK_UTILS_H

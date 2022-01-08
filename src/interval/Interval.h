#ifndef CUBE_ARDUINO_SDK_INTERVAL_H
#define CUBE_ARDUINO_SDK_INTERVAL_H

#include "Updatable.h"

class Interval : public Updatable {
public:
    /**
     * Update the duration of the _interval.
     * @param duration
     */
    virtual void setDuration(unsigned int duration) = 0;

    virtual void reset() = 0;

    virtual unsigned int getDuration() = 0;
};

#endif //CUBE_ARDUINO_SDK_INTERVAL_H

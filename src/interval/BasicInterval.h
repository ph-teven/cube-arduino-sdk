#ifndef CUBE_ARDUINO_SDK_BASICINTERVAL_H
#define CUBE_ARDUINO_SDK_BASICINTERVAL_H

#include <functional>
#include "Interval.h"

class BasicInterval : public Interval {
public:
    explicit BasicInterval(
            unsigned int duration,
            std::function<void()> onFinished
    ) : _duration(duration),
        _onFinished(std::move(onFinished)) {};

    /**
     * Update the internal _interval.
     */
    void update(unsigned long delta) override;

    /**
     * Update the duration of the _interval.
     * @param duration
     */
    void setDuration(unsigned long duration) override;

    void reset() override;

    unsigned long getDuration() override;

private:
    unsigned int _duration;
    std::function<void()> _onFinished;
    unsigned int _expiredTime = 0;
};

#endif //CUBE_ARDUINO_SDK_BASICINTERVAL_H

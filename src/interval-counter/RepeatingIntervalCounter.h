#ifndef CUBE_ARDUINO_SDK_REPEATINGINTERVALCOUNTER_H
#define CUBE_ARDUINO_SDK_REPEATINGINTERVALCOUNTER_H

#include <functional>
#include "counter/RepeatingCounter.h"
#include "interval/BasicInterval.h"
#include "IntervalCounter.h"

class RepeatingIntervalCounter : public IntervalCounter {
public:

    /**
     * @param start Inclusive
     * @param end Exclusive
     */
    explicit RepeatingIntervalCounter(
            unsigned int duration,
            int start,
            int end,
            unsigned int step,
            const std::function<void(int)> &onChange,
            const std::function<void()> &onRepeat
    ) : IntervalCounter(
            new RepeatingCounter(
                    start,
                    end,
                    step,
                    onChange,
                    onRepeat
            ),
            new BasicInterval(
                    duration,
                    [this] {
                        _counter->increment();
                    }
            )
    ) {}
};

#endif //CUBE_ARDUINO_SDK_REPEATINGINTERVALCOUNTER_H
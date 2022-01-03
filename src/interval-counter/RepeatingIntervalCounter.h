#ifndef CUBE_ARDUINO_SDK_REPEATINGINTERVALCOUNTER_H
#define CUBE_ARDUINO_SDK_REPEATINGINTERVALCOUNTER_H

#include <functional>
#include "counter/RepeatingCounter.h"
#include "interval/Interval.h"
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
            const std::function<void(int)> &onChange = [](int) {},
            const std::function<void()> &onRepeat = [] {},
            int step = 1
    ) : IntervalCounter(
            new RepeatingCounter(
                    start,
                    end,
                    onChange,
                    onRepeat,
                    step
            ),
            new Interval(
                    duration,
                    [this] {
                        counter->increment();
                    }
            )
    ) {}
};


#endif //CUBE_ARDUINO_SDK_REPEATINGINTERVALCOUNTER_H

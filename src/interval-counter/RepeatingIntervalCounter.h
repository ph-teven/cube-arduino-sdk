#ifndef CUBE_ARDUINO_SDK_REPEATINGINTERVALCOUNTER_H
#define CUBE_ARDUINO_SDK_REPEATINGINTERVALCOUNTER_H

#include <functional>
#include <utility>
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
            long start,
            long end,
            unsigned long step = 1,
            std::function<void(long)> onChange = [](long) {},
            std::function<void()> onRepeat = [] {}
    ) : IntervalCounter(
            new RepeatingCounter(
                    start,
                    end,
                    step,
                    std::move(onChange),
                    std::move(onRepeat)
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
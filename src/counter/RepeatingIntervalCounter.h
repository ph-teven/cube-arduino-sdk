#ifndef LED_CONTROLLER_REPEATINGINTERVALCOUNTER_H
#define LED_CONTROLLER_REPEATINGINTERVALCOUNTER_H

#include <functional>
#include "timing/Interval.h"
#include "RepeatingCounter.h"

class RepeatingIntervalCounter {
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
    ) :
            counter(
                    new RepeatingCounter(
                            start,
                            end,
                            onChange,
                            onRepeat,
                            step
                    )
            ),
            interval(
                    new Interval(
                            duration,
                            [this] {
                                counter->increment();
                            }
                    )
            ) {}

    void update(unsigned int delta);

    RepeatingCounter *counter;
    Interval *interval;
};


#endif //LED_CONTROLLER_REPEATINGINTERVALCOUNTER_H

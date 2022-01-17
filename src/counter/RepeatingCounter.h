#ifndef CUBE_ARDUINO_SDK_REPEATINGCOUNTER_H
#define CUBE_ARDUINO_SDK_REPEATINGCOUNTER_H

#include <functional>
#include <utility>
#include "Counter.h"

class RepeatingCounter : public Counter {
public:

    /**
     * @param start Inclusive
     * @param end Exclusive
     */
    explicit RepeatingCounter(
            long start,
            long end,
            unsigned long step = 1,
            std::function<void(long)> onChange = [](long) {},
            std::function<void()> onRepeat = [] {}
    ) :
            _onRepeat(std::move(onRepeat)),
            _onChange(std::move(onChange)),
            _current(start),
            _step(step),
            _start(start),
            _end(end - 1) {}

    void increment() override;

    long getValue() override;

    void setValue(long value) override;

    unsigned long getStep() override;

    long getEnd() override;

    void setStep(unsigned long step) override;

private:
    std::function<void()> _onRepeat;
    std::function<void(long)> _onChange;
    long _current = 0;
    unsigned long _step = 1;
    long _start;
    long _end;
};


#endif //CUBE_ARDUINO_SDK_REPEATINGCOUNTER_H

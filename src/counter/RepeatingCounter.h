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
            int start,
            int end,
            std::function<void(int)> onChange = [](int) {},
            std::function<void()> onRepeat = [] {},
            int step = 1
    ) :
            _onRepeat(std::move(onRepeat)),
            _onChange(std::move(onChange)),
            _current(start),
            _step(step),
            _start(start),
            _end(end - 1) {}

    void increment() override;

    int getValue() override;

    void setValue(int value) override;

    int getStep() override;

    int getEnd() override;

    void setStep(int step) override;

private:
    std::function<void()> _onRepeat;
    std::function<void(int)> _onChange;
    int _current = 0;
    int _step = 1;
    int _start;
    int _end;
};


#endif //CUBE_ARDUINO_SDK_REPEATINGCOUNTER_H

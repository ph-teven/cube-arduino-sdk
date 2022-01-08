#ifndef CUBE_ARDUINO_SDK_UPDOWNREPEATINGCOUNTER_H
#define CUBE_ARDUINO_SDK_UPDOWNREPEATINGCOUNTER_H

#include <functional>
#include "Counter.h"

// goes like this 0 1 2 3 2 1 0

class UpDownRepeatingCounter : public Counter {

public:
    /**
     * @param start Inclusive
     * @param end Exclusive
     */
    explicit UpDownRepeatingCounter(
            int start,
            int end,
            unsigned int step = 1,
            std::function<void(int)> onChange = [](int) {},
            std::function<void()> onRepeat = [] {}
    ) :
            _onRepeat(std::move(onRepeat)),
            _onChange(std::move(onChange)),
            _current(start),
            _start(start),
            _end(end),
            _step(step) {}

    void increment() override;

    int getValue() override;

    void setValue(int value) override;

    int getEnd() override;

    int getStep() override;

    void setStep(int step) override;

private:
    std::function<void()> _onRepeat;
    std::function<void(int)> _onChange;
    int _countingUp = true;
    int _current = 0;
    int _start;
    int _end;
    unsigned int _step;
};


#endif //CUBE_ARDUINO_SDK_UPDOWNREPEATINGCOUNTER_H

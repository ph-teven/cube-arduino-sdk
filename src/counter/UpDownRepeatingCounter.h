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
            long start,
            long end,
            unsigned long step = 1,
            std::function<void(long)> onChange = [](long) {},
            std::function<void()> onRepeat = [] {}
    ) :
            _onRepeat(std::move(onRepeat)),
            _onChange(std::move(onChange)),
            _current(start),
            _start(start),
            _end(end),
            _step(step) {}

    void increment() override;

    long getValue() override;

    void setValue(long value) override;

    long getEnd() override;

    unsigned long getStep() override;

    void setStep(unsigned long step) override;

private:
    std::function<void()> _onRepeat;
    std::function<void(long)> _onChange;
    bool _countingUp = true;
    long _current = 0;
    long _start;
    long _end;
    unsigned long _step;
};


#endif //CUBE_ARDUINO_SDK_UPDOWNREPEATINGCOUNTER_H

#ifndef LED_CONTROLLER_UPDOWNCOUNTER_H
#define LED_CONTROLLER_UPDOWNCOUNTER_H

#include <functional>

class UpDownCounter {

public:
    /**
     * @param start Inclusive
     * @param end Exclusive
     */
    explicit UpDownCounter(
            int start,
            int end,
            std::function<void(int)> onChange = [](int) {},
            std::function<void()> onRepeat = [] {}
    ) :
            _onRepeat(std::move(onRepeat)),
            _onChange(std::move(onChange)),
            _current(start),
            _start(start),
            _end(end) {}

    void increment();

    int getValue();

    void setValue(int value);

    int getEnd();

private:
    std::function<void()> _onRepeat;
    std::function<void(int)> _onChange;
    int _countingUp = true;
    int _current = 0;
    int _start;
    int _end;
};


#endif //LED_CONTROLLER_UPDOWNCOUNTER_H

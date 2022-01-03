#ifndef LED_CONTROLLER_REPEATINGCOUNTER_H
#define LED_CONTROLLER_REPEATINGCOUNTER_H

#include <functional>
#include <utility>

class RepeatingCounter {
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

    void increment();

    int getValue();

    void setValue(int value);

    int getStep();

    int getEnd();

    void setStep(int step);

private:
    std::function<void()> _onRepeat;
    std::function<void(int)> _onChange;
    int _current = 0;
    int _step = 1;
    int _start;
    int _end;
};


#endif //LED_CONTROLLER_REPEATINGCOUNTER_H

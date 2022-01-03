#ifndef LED_CONTROLLER_INTERVAL_H
#define LED_CONTROLLER_INTERVAL_H

#include <functional>

class Interval {
public:
    explicit Interval(
            unsigned int duration,
            std::function<void()> onFinished
    ) : _duration(duration),
        _onFinished(std::move(onFinished)) {};

    /**
     * Update the internal interval.
     */
    void update(unsigned int delta);

    /**
     * Update the duration of the interval.
     * @param duration
     */
    void setDuration(unsigned int duration);

    void reset();

    unsigned int getDuration();


private:
    unsigned int _duration;
    std::function<void()> _onFinished;
    unsigned int _expiredTime = 0;

};


#endif //LED_CONTROLLER_INTERVAL_H

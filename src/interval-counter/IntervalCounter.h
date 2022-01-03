#ifndef CUBE_ARDUINO_SDK_INTERVAL_COUNTER_H
#define CUBE_ARDUINO_SDK_INTERVAL_COUNTER_H

#include "counter/Counter.h"
#include "interval/Interval.h"

class IntervalCounter {
public:
    explicit IntervalCounter(Counter *counter, Interval *interval) : counter(counter), interval(interval) {}

    Counter *counter;
    Interval *interval;
};


#endif //CUBE_ARDUINO_SDK_INTERVAL_COUNTER_H

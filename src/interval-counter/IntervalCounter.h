#ifndef CUBE_ARDUINO_SDK_INTERVAL_COUNTER_H
#define CUBE_ARDUINO_SDK_INTERVAL_COUNTER_H

#include "counter/Counter.h"
#include "interval/BasicInterval.h"

class IntervalCounter : public Interval, public Counter {
public:
    explicit IntervalCounter(Counter *counter, BasicInterval *interval) : _counter(counter), _interval(interval) {}

    void update(unsigned int delta) override {
        this->_interval->update(delta);
    }

    void setDuration(unsigned int duration) override {
        this->_interval->setDuration(duration);
    }

    void reset() override {
        this->_interval->reset();
    }

    unsigned int getDuration() override {
        return this->_interval->getDuration();
    }

    void increment() override {
        this->_counter->increment();
    }

    int getValue() override {
        return this->_counter->getValue();
    }

    void setValue(int value) override {
        this->_counter->setValue(value);
    }

    int getStep() override {
        return this->_counter->getStep();
    }

    int getEnd() override {
        return this->_counter->getEnd();
    }

    void setStep(int step) override {
        this->_counter->setStep(step);
    }

protected:
    Counter *_counter;
    BasicInterval *_interval;
};


#endif //CUBE_ARDUINO_SDK_INTERVAL_COUNTER_H

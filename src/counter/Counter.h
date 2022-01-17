#ifndef CUBE_ARDUINO_SDK_COUNTER_H
#define CUBE_ARDUINO_SDK_COUNTER_H

class Counter {

public:
    virtual void increment() = 0;

    virtual long getValue() = 0;

    virtual void setValue(long value) = 0;

    virtual unsigned long getStep() = 0;

    virtual long getEnd() = 0;

    virtual void setStep(unsigned long step) = 0;
};


#endif //CUBE_ARDUINO_SDK_COUNTER_H

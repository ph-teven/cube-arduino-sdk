#ifndef CUBE_ARDUINO_SDK_COUNTER_H
#define CUBE_ARDUINO_SDK_COUNTER_H

class Counter {

public:
    virtual void increment() = 0;

    virtual int getValue() = 0;

    virtual void setValue(int value) = 0;

    virtual int getStep() = 0;

    virtual int getEnd() = 0;

    virtual void setStep(int step) = 0;
};


#endif //CUBE_ARDUINO_SDK_COUNTER_H

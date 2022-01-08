#ifndef CUBE_ARDUINO_SDK_TESTPLATFORM_H
#define CUBE_ARDUINO_SDK_TESTPLATFORM_H

#include "Platform.h"

class TestPlatform : public Platform {
public:
    explicit TestPlatform();

    unsigned int Millis() override;

    void PinMode(int pin, int mode) override;

    int DigitalRead(int pin) override;

    void DigitalWrite(int pin, int value) override;

    int AnalogRead(int pin) override;

    void AnalogWrite(int pin, int value) override;

    void setTime(int time);

private:
    int _pinModes[10]{
            INPUT, INPUT, INPUT, INPUT, INPUT,
            INPUT, INPUT, INPUT, INPUT, INPUT,
    };
    int _digitalValues[10]{
            LOW, LOW, LOW, LOW, LOW,
            LOW, LOW, LOW, LOW, LOW,
    };
    int _analogValues[10]{
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
    };
    int _time = 0;
};


#endif //CUBE_ARDUINO_SDK_TESTPLATFORM_H

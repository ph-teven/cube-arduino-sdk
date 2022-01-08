#ifndef CUBE_ARDUINO_SDK_TESTPLATFORM_H
#define CUBE_ARDUINO_SDK_TESTPLATFORM_H

#include "platform/Platform.h"

class TestPlatform : public Platform {
public:
    explicit TestPlatform();

    unsigned long Millis() override;

    void PinMode(unsigned char pin, unsigned char mode) override;

    int DigitalRead(unsigned char pin) override;

    void DigitalWrite(unsigned char pin, unsigned char value) override;

    int AnalogRead(unsigned char pin) override;

    void AnalogWrite(unsigned char pin, int value) override;

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

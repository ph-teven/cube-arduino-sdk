#ifndef CUBE_ARDUINO_SDK_TESTPLATFORM_H
#define CUBE_ARDUINO_SDK_TESTPLATFORM_H

#include "Platform.h"

class TestPlatform : public Platform {
public:
    explicit TestPlatform();

    unsigned long millis() override;

    void pinMode(unsigned char pin, unsigned char mode) override;

    int digitalRead(unsigned char pin) override;

    void digitalWrite(unsigned char pin, unsigned char value) override;

    int analogRead(unsigned char pin) override;

    void analogWrite(unsigned char pin, int value) override;

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

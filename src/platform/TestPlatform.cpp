#include "TestPlatform.h"

TestPlatform::TestPlatform() = default;

int TestPlatform::DigitalRead(unsigned char pin) {
    bool isPullup = _pinModes[pin] == INPUT_PULLUP;

    if (isPullup && _digitalValues[pin] == HIGH) {
        return LOW;
    }

    if (isPullup && _digitalValues[pin] == LOW) {
        return HIGH;
    }

    return _digitalValues[pin];
}

void TestPlatform::DigitalWrite(unsigned char pin, unsigned char value) {
    _digitalValues[pin] = value;
}

void TestPlatform::PinMode(unsigned char pin, unsigned char mode) {
    _pinModes[pin] = mode;
}

unsigned long TestPlatform::Millis() {
    return _time;
}

void TestPlatform::setTime(int time) {
    _time = time;
}

int TestPlatform::AnalogRead(unsigned char pin) {
    return _analogValues[pin];
}

void TestPlatform::AnalogWrite(unsigned char pin, int value) {
    _analogValues[pin] = value;
}

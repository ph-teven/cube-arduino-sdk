#include "TestPlatform.h"

TestPlatform::TestPlatform() = default;

int TestPlatform::DigitalRead(int pin) {
    bool isPullup = _pinModes[pin] == INPUT_PULLUP;

    if (isPullup && _digitalValues[pin] == HIGH) {
        return LOW;
    }

    if (isPullup && _digitalValues[pin] == LOW) {
        return HIGH;
    }

    return _digitalValues[pin];
}

void TestPlatform::DigitalWrite(int pin, int value) {
    _digitalValues[pin] = value;
}

void TestPlatform::PinMode(int pin, int mode) {
    _pinModes[pin] = mode;
}

unsigned int TestPlatform::Millis() {
    return _time;
}

void TestPlatform::setTime(int time) {
    _time = time;
}

int TestPlatform::AnalogRead(int pin) {
    return _analogValues[pin];
}

void TestPlatform::AnalogWrite(int pin, int value) {
    _analogValues[pin] = value;
}

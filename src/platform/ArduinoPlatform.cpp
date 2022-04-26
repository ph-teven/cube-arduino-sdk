#include "ArduinoPlatform.h"
#include "Externals.h"

ArduinoPlatform::ArduinoPlatform() = default;

int ArduinoPlatform::DigitalRead(unsigned char pin) {
    return digitalRead(pin);
}

void ArduinoPlatform::DigitalWrite(unsigned char pin, unsigned char value) {
    digitalWrite(pin, value);
}

void ArduinoPlatform::PinMode(unsigned char pin, unsigned char mode) {
    pinMode(pin, mode);
}

unsigned long ArduinoPlatform::Millis() {
    return millis();
}

int ArduinoPlatform::AnalogRead(unsigned char pin) {
    return analogRead(pin);
}

void ArduinoPlatform::AnalogWrite(unsigned char pin, int value) {
    analogWrite(pin, value);
}

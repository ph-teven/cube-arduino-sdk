#include "ArduinoPlatform.h"
#include "Externals.h"

ArduinoPlatform::ArduinoPlatform() = default;

int ArduinoPlatform::digitalRead(unsigned char pin) {
    return digitalRead(pin);
}

void ArduinoPlatform::digitalWrite(unsigned char pin, unsigned char value) {
    digitalWrite(pin, value);
}

void ArduinoPlatform::pinMode(unsigned char pin, unsigned char mode) {
    pinMode(pin, mode);
}

unsigned long ArduinoPlatform::millis() {
    return millis();
}

int ArduinoPlatform::analogRead(unsigned char pin) {
    return analogRead(pin);
}

void ArduinoPlatform::analogWrite(unsigned char pin, int value) {
    analogWrite(pin, value);
}


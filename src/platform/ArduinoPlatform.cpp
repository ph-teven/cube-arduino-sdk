#include "ArduinoPlatform.h"

ArduinoPlatform::ArduinoPlatform() = default;

int ArduinoPlatform::DigitalRead(int pin) {
    return digitalRead(pin);
}

void ArduinoPlatform::DigitalWrite(int pin, int value) {
    digitalWrite(pin, value);
}

void ArduinoPlatform::PinMode(int pin, int mode) {
    pinMode(pin, mode);
}

unsigned int ArduinoPlatform::Millis() {
    return millis();
}

int ArduinoPlatform::AnalogRead(int pin) {
    return analogRead(pin);
}

void ArduinoPlatform::AnalogWrite(int pin, int value) {
    analogWrite(pin, value);
}

void ArduinoPlatform::PrintLn(const char *value) {
    Serial.println(value);
}

void ArduinoPlatform::PrintLn(int value) {
    Serial.println(value);
}


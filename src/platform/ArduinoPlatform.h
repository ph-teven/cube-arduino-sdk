#ifndef CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H
#define CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H

#include "Platform.h"

extern int digitalRead(int pin);

extern void digitalWrite(int pin, int value);

extern void pinMode(int pin, int mode);

extern int millis();

extern int analogRead(int pin);

extern void analogWrite(int pin, int value);


class ArduinoPlatform : public Platform {
public:
    explicit ArduinoPlatform();

    unsigned int Millis() override;

    void PinMode(int pin, int mode) override;

    int DigitalRead(int pin) override;

    void DigitalWrite(int pin, int value) override;

    int AnalogRead(int pin) override;

    void AnalogWrite(int pin, int value) override;
};


#endif //CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H

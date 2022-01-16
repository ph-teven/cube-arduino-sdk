#ifndef CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H
#define CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H

#include "Platform.h"

class ArduinoPlatform : public Platform {
public:
    explicit ArduinoPlatform();

    unsigned long millis() override;

    void pinMode(unsigned char pin, unsigned char mode) override;

    int digitalRead(unsigned char pin) override;

    void digitalWrite(unsigned char pin, unsigned char value) override;

    int analogRead(unsigned char pin) override;

    void analogWrite(unsigned char pin, int value) override;
};


#endif //CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H

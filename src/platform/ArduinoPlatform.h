#ifndef CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H
#define CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H

#include "Platform.h"

class ArduinoPlatform : public Platform {
public:
    explicit ArduinoPlatform();

    unsigned long Millis() override;

    void PinMode(unsigned char pin, unsigned char mode) override;

    int DigitalRead(unsigned char pin) override;

    void DigitalWrite(unsigned char pin, unsigned char value) override;

    int AnalogRead(unsigned char pin) override;

    void AnalogWrite(unsigned char pin, int value) override;
};


#endif //CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H

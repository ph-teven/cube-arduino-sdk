#ifndef CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H
#define CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H

#include "Platform.h"
#include "Arduino.h"

// https://community.platformio.org/t/nrf52832-include-set-breaks-compilation-on-platformio-but-compiles-fine-on-arduinoide/12237/2
#undef min
#undef max

class ArduinoPlatform : public Platform {
public:
    explicit ArduinoPlatform();

    unsigned int Millis() override;

    void PinMode(int pin, int mode) override;

    int DigitalRead(int pin) override;

    void DigitalWrite(int pin, int value) override;

    int AnalogRead(int pin) override;

    void AnalogWrite(int pin, int value) override;

    void PrintLn(const char *value) override;

    void PrintLn(int value) override;
};


#endif //CUBE_ARDUINO_SDK_ARDUINOPLATFORM_H

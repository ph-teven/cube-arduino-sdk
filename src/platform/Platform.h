#ifndef CUBE_ARDUINO_SDK_PLATFORM_H
#define CUBE_ARDUINO_SDK_PLATFORM_H

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

class Platform {

public:
    virtual unsigned long Millis() = 0;

    virtual void PinMode(unsigned char pin, unsigned char mode) = 0;

    virtual int DigitalRead(unsigned char pin) = 0;

    virtual void DigitalWrite(unsigned char pin, unsigned char value) = 0;

    virtual int AnalogRead(unsigned char pin) = 0;

    virtual void AnalogWrite(unsigned char pin, int value) = 0;
};

#endif //CUBE_ARDUINO_SDK_PLATFORM_H

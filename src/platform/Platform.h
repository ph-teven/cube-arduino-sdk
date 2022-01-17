#ifndef CUBE_ARDUINO_SDK_PLATFORM_H
#define CUBE_ARDUINO_SDK_PLATFORM_H

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

class Platform {

public:
    virtual unsigned long millis() = 0;

    virtual void pinMode(unsigned char pin, unsigned char mode) = 0;

    virtual int digitalRead(unsigned char pin) = 0;

    virtual void digitalWrite(unsigned char pin, unsigned char value) = 0;

    virtual int analogRead(unsigned char pin) = 0;

    virtual void analogWrite(unsigned char pin, int value) = 0;
};

#endif //CUBE_ARDUINO_SDK_PLATFORM_H

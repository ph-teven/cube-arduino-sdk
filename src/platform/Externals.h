#ifndef CUBE_ARDUINO_SDK_EXTERNALS_H
#define CUBE_ARDUINO_SDK_EXTERNALS_H

extern "C" int digitalRead(unsigned char pin);

extern "C" void digitalWrite(unsigned char pin, unsigned char value);

extern "C" void pinMode(unsigned char pin, unsigned char mode);

extern "C" unsigned long millis(void);

extern "C" int analogRead(unsigned char pin);

extern "C" void analogWrite(unsigned char pin, int value);

#endif //CUBE_ARDUINO_SDK_EXTERNALS_H

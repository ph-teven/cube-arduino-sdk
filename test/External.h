#ifndef CUBE_ARDUINO_SDK_EXTERNAL_H
#define CUBE_ARDUINO_SDK_EXTERNAL_H

extern int digitalRead(int pin) {
    return 0;
}

extern void digitalWrite(int pin, int value) {
}

extern void pinMode(unsigned char pin, int mode) {
}

extern unsigned long millis() {
    return 0;
}

extern int analogRead(int pin) {
    return 0;
}

extern void analogWrite(int pin, int value) {
}

#endif //CUBE_ARDUINO_SDK_EXTERNAL_H

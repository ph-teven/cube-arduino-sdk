#ifndef CUBE_ARDUINO_SDK_UPDATABLE_H
#define CUBE_ARDUINO_SDK_UPDATABLE_H

class Updatable {
public:
    virtual void update(unsigned long delta) = 0;
};

#endif //CUBE_ARDUINO_SDK_UPDATABLE_H

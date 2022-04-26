#ifndef CUBE_ARDUINO_SDK_BUTTON_H
#define CUBE_ARDUINO_SDK_BUTTON_H

#include <functional>
#include <utility>
#include "platform/Platform.h"
#include "Component.h"

class Button : public Component {

public:
    explicit Button(
            Platform *platform,
            int pin,
            std::function<void()> onPressed = [] {}
    )
            : _platform(platform),
              _pin(pin),
              _onPressed(std::move(onPressed)) {
        _platform->PinMode(_pin, INPUT_PULLUP);
    }

    void update(unsigned long delta) override {
        bool pressed = _platform->DigitalRead(_pin) == LOW;

        if (!_pressed && pressed) {
            _onPressed();
        }

        _pressed = pressed;
    }

private:
    Platform *_platform;
    int _pin;
    std::function<void()> _onPressed;
    bool _pressed = false;
};

#endif //CUBE_ARDUINO_SDK_BUTTON_H

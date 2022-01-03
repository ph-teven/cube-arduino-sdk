#ifndef LED_CONTROLLER_BUTTON_H
#define LED_CONTROLLER_BUTTON_H

#include <functional>
#include <utility>
#include "platform/Platform.h"

class Button {

public:
    explicit Button(Platform *platform, int pin, std::function<void()> onPressed)
            : _platform(platform),
              _pin(pin),
              _onPressed(std::move(onPressed)) {
        _platform->PinMode(_pin, INPUT_PULLUP);
    }

    void update();

private:
    Platform *_platform;
    int _pin;
    std::function<void()> _onPressed;
    bool _pressed = false;
};

#endif //LED_CONTROLLER_BUTTON_H

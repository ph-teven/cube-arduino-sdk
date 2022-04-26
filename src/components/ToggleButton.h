#ifndef CUBE_ARDUINO_SDK_TOGGLEBUTTON_H
#define CUBE_ARDUINO_SDK_TOGGLEBUTTON_H

#include <functional>
#include <utility>
#include "platform/Platform.h"
#include "Component.h"

class ToggleButton : public Component {

public:
    explicit ToggleButton(
            Platform *platform,
            int pin,
            std::function<void(bool)> onToggle = [](bool toggled) {}
    ) : _platform(platform),
        _pin(pin),
        _onToggle(std::move(onToggle)) {
        _platform->PinMode(_pin, INPUT_PULLUP);
    }

    void update(unsigned long delta) override {
        bool pressed = _platform->DigitalRead(_pin) == LOW;

        if (!_lastPressed && pressed) { // value changed
            _toggled = !_toggled;
            _onToggle(_toggled);
        }

        _lastPressed = pressed;
    }

private:
    Platform *_platform;
    int _pin;
    std::function<void(bool)> _onToggle;
    bool _lastPressed = false;
    bool _toggled = false;
};

#endif //CUBE_ARDUINO_SDK_TOGGLEBUTTON_H

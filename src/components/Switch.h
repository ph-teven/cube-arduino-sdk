#ifndef CUBE_ARDUINO_SDK_SWITCH_H
#define CUBE_ARDUINO_SDK_SWITCH_H

#include <functional>
#include <utility>
#include "Component.h"
#include "platform/Platform.h"

class Switch : public Component {

public:
    explicit Switch(Platform *platform, int pin, std::function<void(bool)> onToggle = [](bool) {})
            : _platform(platform),
              _pin(pin),
              _onToggle(std::move(onToggle)) {
        platform->PinMode(_pin, INPUT_PULLUP);
    }

    void update(unsigned long delta) override  {
        bool on = _platform->DigitalRead(_pin) == HIGH;

        if (on != _on) {
            _onToggle(on);
        }

        _on = on;
    }

    bool isOn() const {
        return _on;
    }

private:
    Platform *_platform;
    int _pin;
    std::function<void(bool)> _onToggle;
    bool _on = false;
};


#endif //CUBE_ARDUINO_SDK_SWITCH_H

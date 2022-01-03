#ifndef LED_CONTROLLER_SWITCH_H
#define LED_CONTROLLER_SWITCH_H

#include <functional>
#include <utility>
#include "platform/Platform.h"

class Switch {

public:
    explicit Switch(Platform *platform, int pin, std::function<void(bool)> onToggle = [](bool) {})
            : _platform(platform),
              _pin(pin),
              _onToggle(std::move(onToggle)) {
        platform->PinMode(_pin, INPUT_PULLUP);
    }

    void update();

    bool isOn();

private:
    Platform *_platform;
    int _pin;
    std::function<void(bool)> _onToggle;
    bool _on = false;
};


#endif //LED_CONTROLLER_SWITCH_H

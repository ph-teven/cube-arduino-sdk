#ifndef CUBE_ARDUINO_SDK_SWITCH_H
#define CUBE_ARDUINO_SDK_SWITCH_H

#include <functional>
#include <utility>
#include "Component.h"
#include "platform/Platform.h"

class Switch : public Component {

public:
    explicit Switch(Platform *platform, int pin, std::function<void(bool)> onToggle)
            : _platform(platform),
              _pin(pin),
              _onToggle(std::move(onToggle)) {
        platform->PinMode(_pin, INPUT_PULLUP);
    }

    void update(unsigned int delta) override;

    bool isOn() const;

private:
    Platform *_platform;
    int _pin;
    std::function<void(bool)> _onToggle;
    bool _on = false;
};


#endif //CUBE_ARDUINO_SDK_SWITCH_H

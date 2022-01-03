#ifndef CUBE_ARDUINO_SDK_POTI_H
#define CUBE_ARDUINO_SDK_POTI_H

#include <functional>
#include <utility>
#include "platform/Platform.h"
#include "ValueRange.h"
#include "Component.h"

const auto analogRange = Range{0, 1023};

class Poti : public Component {
public:
    explicit Poti(Platform *platform, int pin, Range range = analogRange, std::function<void(int)> onChanged = [](int) {}) :
            _platform(platform),
            _onChanged(std::move(onChanged)),
            _pin(pin),
            _range(range) {

        _value = _platform->AnalogRead(_pin);
        _mappedValue = Platform::Map(_value, analogRange.min, analogRange.max, _range.min, _range.max);
    }

    int getValue();

    void update() override;

private:
    Platform *_platform;
    std::function<void(int)> _onChanged;
    int _pin;
    Range _range;
    int _value = 0;
    int _mappedValue = 0;
};

#endif //CUBE_ARDUINO_SDK_POTI_H
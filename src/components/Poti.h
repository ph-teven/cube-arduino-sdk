#ifndef CUBE_ARDUINO_SDK_POTI_H
#define CUBE_ARDUINO_SDK_POTI_H

#include <functional>
#include <utility>
#include "platform/Platform.h"
#include "ValueRange.h"
#include "Component.h"
#include "utils.h"

const auto range10Bit = Range{0, 1023};

class Poti : public Component {
public:
    explicit Poti(Platform *platform, int pin, Range range, std::function<void(int)> onChanged = [](int) {}) :
            _platform(platform),
            _onChanged(std::move(onChanged)),
            _pin(pin),
            _range(range) {

        _value = _platform->analogRead(_pin);
        _mappedValue = (int) cube::map(_value, range10Bit.min, range10Bit.max, _range.min, _range.max);
    }

    int getValue() const {
        return _mappedValue;
    }

    void update(unsigned long delta) override {
        // Take 0.6 of the new value and add it to 0.4 of the old value.
        auto newValue = (4 * _value + 6 * _platform->analogRead(_pin)) / 10;
        auto newMappedValue = (int) cube::map(newValue, range10Bit.min, range10Bit.max, _range.min, _range.max);

        if (newMappedValue != _mappedValue) {
            _value = newValue;
            _mappedValue = newMappedValue;

            _onChanged(_mappedValue);
        }
    }


private:
    Platform *_platform;
    std::function<void(int)> _onChanged;
    int _pin;
    Range _range;
    int _value = 0;
    int _mappedValue = 0;
};

#endif //CUBE_ARDUINO_SDK_POTI_H

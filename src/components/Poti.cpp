#include "Poti.h"

int Poti::getValue() {
    return _mappedValue;
}

void Poti::update() {
    // Take 0.6 of the new value and add it to 0.4 of the old value.
    int newValue = (4 * _value + 6 * _platform->AnalogRead(_pin)) / 10;
    int newMappedValue = Platform::Map(newValue, analogRange.min, analogRange.max, _range.min, _range.max);

    if (newMappedValue != _mappedValue) {
        _value = newValue;
        _mappedValue = newMappedValue;

        _onChanged(_mappedValue);
    }
}

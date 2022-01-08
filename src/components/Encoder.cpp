#include <algorithm>
#include "Encoder.h"

void Encoder::update(unsigned int delta) {
    int clk = _platform->DigitalRead(_pins.clk);

    bool clkChanged = clk != _clk;

    if (clkChanged) {
        int dt = _platform->DigitalRead(_pins.dt);
        int value = _value;

        if (dt != clk) {
            value += _step;
        } else {
            value -= _step;
        }

        value = std::min(value, _range.max);
        value = std::max(value, _range.min);

        if (value != _value) {
            _value = value;
            _onChange(value);
        }
    }

    bool pressed = _platform->DigitalRead(_pins.sw) == LOW;

    if (pressed && !_pressed) {
        _onPressed(_value);
    }

    _clk = clk;
    _pressed = pressed;
}

int Encoder::getValue() const {
    return _value;
}

void Encoder::setValue(int value) {
    value = std::min(value, _range.max);
    value = std::max(value, _range.min);

    _value = value;
}


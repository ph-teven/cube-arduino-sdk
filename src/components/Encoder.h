#ifndef CUBE_ARDUINO_SDK_ENCODER_H
#define CUBE_ARDUINO_SDK_ENCODER_H

#include <functional>
#include <utility>
#include "platform/Platform.h"
#include "ValueRange.h"
#include "utils.h"
#include "Component.h"

// TODO should have min/max and internal state

struct EncoderPins {
    int clk; // output A
    int dt; // output B
    int sw; // button
};

class Encoder : public Component {

public:
    explicit Encoder(
            Platform *platform,
            EncoderPins pins,
            Range range,
            long startValue,
            unsigned long step = 1,
            std::function<void(long)> onChange = [](long) {},
            std::function<void(long)> onPressed = [](long) {}
    ) : _pins(pins),
        _platform(platform),
        _range(range),
        _value(startValue),
        _step(step),
        _onChange(std::move(onChange)),
        _onPressed(std::move(onPressed)) {

        _platform->PinMode(pins.clk, INPUT_PULLUP);
        _platform->PinMode(pins.dt, INPUT_PULLUP);
        _platform->PinMode(pins.sw, INPUT_PULLUP);

        _clk = _platform->DigitalRead(pins.clk);
        _pressed = _platform->DigitalRead(pins.sw) == LOW;
    };

    void update(unsigned long delta) override {
        int clk = _platform->DigitalRead(_pins.clk);

        bool clkChanged = clk != _clk;

        if (clkChanged) {
            auto dt = _platform->DigitalRead(_pins.dt);
            auto value = _value;

            if (dt != clk) {
                value += _step;
            } else {
                value -= _step;
            }

            value = cube::min(value, _range.max);
            value = cube::max(value, _range.min);

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

    long getValue() const {
        return _value;
    }

    void setValue(long value) {
        value = cube::min(value, _range.max);
        value = cube::max(value, _range.min);

        _value = value;
    }

private:
    EncoderPins _pins;
    Platform *_platform;

    Range _range;
    long _value;
    long _step;
    bool _pressed = false;
    int _clk = LOW;
    std::function<void(long)> _onChange;
    std::function<void(long)> _onPressed;
};


#endif //CUBE_ARDUINO_SDK_ENCODER_H

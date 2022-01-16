#ifndef CUBE_ARDUINO_SDK_ENCODER_H
#define CUBE_ARDUINO_SDK_ENCODER_H

#include <functional>
#include <utility>
#include "platform/Platform.h"
#include "ValueRange.h"
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
            int startValue,
            int step = 1,
            std::function<void(int)> onChange = [](int) {},
            std::function<void(int)> onPressed = [](int) {}
    ) : _pins(pins),
        _platform(platform),
        _range(range),
        _value(startValue),
        _step(step),
        _onChange(std::move(onChange)),
        _onPressed(std::move(onPressed)) {

        _platform->pinMode(pins.clk, INPUT_PULLUP);
        _platform->pinMode(pins.dt, INPUT_PULLUP);
        _platform->pinMode(pins.sw, INPUT_PULLUP);

        _clk = _platform->digitalRead(pins.clk);
        _pressed = _platform->digitalRead(pins.sw) == LOW;
    };

    void update(unsigned int delta) override {
        int clk = _platform->digitalRead(_pins.clk);

        bool clkChanged = clk != _clk;

        if (clkChanged) {
            auto dt = _platform->digitalRead(_pins.dt);
            auto value = _value;

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

        bool pressed = _platform->digitalRead(_pins.sw) == LOW;

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
        value = min(value, _range.max);
        value = max(value, _range.min);

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

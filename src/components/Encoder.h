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
            int step,
            std::function<void(int)> onChange,
            std::function<void(int)> onPressed
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

    void update(unsigned int delta) override;

    int getValue() const;

    void setValue(int value);

private:
    EncoderPins _pins;
    Platform *_platform;

    Range _range;
    int _value;
    int _step;
    bool _pressed = false;
    int _clk = LOW;
    std::function<void(int)> _onChange;
    std::function<void(int)> _onPressed;
};


#endif //CUBE_ARDUINO_SDK_ENCODER_H

#include "Button.h"

void Button::update(unsigned int delta) {
    bool pressed = _platform->DigitalRead(_pin) == LOW;

    if (!_pressed && pressed) {
        _onPressed();
    }

    _pressed = pressed;
}

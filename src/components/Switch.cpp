#include "Switch.h"

void Switch::update() {
    bool on = _platform->DigitalRead(_pin) == HIGH;

    if (on != _on) {
        _onToggle(on);
    }

    _on = on;
}

bool Switch::isOn() {
    return _on;
}
#include "Switch.h"

void Switch::update(unsigned int delta) {
    bool on = _platform->DigitalRead(_pin) == HIGH;

    if (on != _on) {
        _onToggle(on);
    }

    _on = on;
}

bool Switch::isOn() const {
    return _on;
}
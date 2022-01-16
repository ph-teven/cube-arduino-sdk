#include "Delta.h"

unsigned int Delta::update() {
    unsigned int now = _platform->millis();
    unsigned int delta = now - _lastUpdate;

    _lastUpdate = now;

    return delta;
}



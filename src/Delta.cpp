#include "Delta.h"

unsigned long Delta::update() {
    auto now = _platform->Millis();
    auto delta = now - _lastUpdate;

    _lastUpdate = now;

    return delta;
}

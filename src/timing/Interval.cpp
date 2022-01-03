#include "Interval.h"

void Interval::update(unsigned int delta) {
    _expiredTime += delta;

    bool expired = _expiredTime > _duration;

    if (expired) {
        _expiredTime = 0;
        _onFinished();
    }
}

void Interval::setDuration(unsigned int duration) {
    if (_duration == duration) {
        return;
    }

    _duration = duration;
}

unsigned int Interval::getDuration() {
    return _duration;
}

void Interval::reset() {
    _expiredTime = 0;
}

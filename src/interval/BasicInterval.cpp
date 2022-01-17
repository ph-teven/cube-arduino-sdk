#include "BasicInterval.h"

void BasicInterval::update(unsigned long delta) {
    _expiredTime += delta;

    bool expired = _expiredTime > _duration;

    if (expired) {
        _expiredTime = 0;
        _onFinished();
    }
}

void BasicInterval::setDuration(unsigned long duration) {
    if (_duration == duration) {
        return;
    }

    _duration = duration;
}

unsigned long BasicInterval::getDuration() {
    return _duration;
}

void BasicInterval::reset() {
    _expiredTime = 0;
}

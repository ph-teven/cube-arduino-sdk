#include "RepeatingCounter.h"

void RepeatingCounter::increment() {
    if (_current + _step > _end) {
        _current = _start;
        _onRepeat();
    } else {
        _current += _step;
    }

    _onChange(_current);
}

long RepeatingCounter::getValue() {
    return _current;
}

void RepeatingCounter::setValue(long value) {
    _current = value;
    _onChange(_current);
}

void RepeatingCounter::setStep(unsigned long step) {
    _step = step;
}

unsigned long RepeatingCounter::getStep() {
    return _step;
}

long RepeatingCounter::getEnd() {
    return _end;
}

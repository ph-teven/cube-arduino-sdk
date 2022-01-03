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

int RepeatingCounter::getValue() {
    return _current;
}

void RepeatingCounter::setValue(int value) {
    _current = value;
    _onChange(_current);
}

void RepeatingCounter::setStep(int step) {
    _step = step;
}

int RepeatingCounter::getStep() {
    return _step;
}

int RepeatingCounter::getEnd() {
    return _end;
}

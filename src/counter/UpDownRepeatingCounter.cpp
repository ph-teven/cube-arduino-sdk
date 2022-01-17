#include "UpDownRepeatingCounter.h"

void UpDownRepeatingCounter::increment() {
    if (_countingUp) {
        _current += _step;

        if (_current == _end) {
            _countingUp = !_countingUp;
        }
    } else {
        _current -= _step;

        if (_current == _start) {
            _countingUp = !_countingUp;
            _onRepeat();
        }
    }

    _onChange(_current);
}

long UpDownRepeatingCounter::getValue() {
    return _current;
}

void UpDownRepeatingCounter::setValue(long value) {
    _current = value;
    _onChange(_current);
}

long UpDownRepeatingCounter::getEnd() {
    return _end;
}

unsigned long UpDownRepeatingCounter::getStep() {
    return _step;
}

void UpDownRepeatingCounter::setStep(unsigned long step) {
    _step = step;
}

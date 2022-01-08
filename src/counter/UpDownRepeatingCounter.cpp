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

int UpDownRepeatingCounter::getValue() {
    return _current;
}

void UpDownRepeatingCounter::setValue(int value) {
    _current = value;
    _onChange(_current);
}

int UpDownRepeatingCounter::getEnd() {
    return _end;
}

int UpDownRepeatingCounter::getStep() {
    return _step;
}

void UpDownRepeatingCounter::setStep(int step) {
    _step = step;
}

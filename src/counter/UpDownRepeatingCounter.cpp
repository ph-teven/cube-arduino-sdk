#include "UpDownRepeatingCounter.h"

void UpDownRepeatingCounter::increment() {
    // 0 1 2 3 2 1 0
    if (_countingUp) {
        _current += 1;

        if (_current == _end) {
            _countingUp = !_countingUp;
        }
    } else {
        _current -= 1;

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
    return 1;
}

void UpDownRepeatingCounter::setStep(int step) {
}

#include "UpDownCounter.h"

void UpDownCounter::increment() {
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

int UpDownCounter::getValue() {
    return _current;
}

void UpDownCounter::setValue(int value) {
    _current = value;
    _onChange(_current);
}

int UpDownCounter::getEnd() {
    return _end;
}

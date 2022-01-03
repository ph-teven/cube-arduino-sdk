#include "ValueRange.h"

int ValueRange::map(Range out) {
    return Platform::Map(_value, _range.min, _range.max, out.min, out.max);
}

int ValueRange::value() {
    return _value;
}

int ValueRange::map(int min, int max) {
    return map(Range{min, max});
}

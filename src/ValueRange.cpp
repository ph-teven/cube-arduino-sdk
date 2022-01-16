#include "ValueRange.h"
#include "utils.h"

long ValueRange::map(Range out) const {
    return cube::map(_value, _range.min, _range.max, out.min, out.max);
}

long ValueRange::value() const {
    return _value;
}

long ValueRange::map(long min, long max) const {
    return map(Range{min, max});
}

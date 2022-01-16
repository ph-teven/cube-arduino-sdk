#ifndef CUBE_ARDUINO_SDK_VALUE_RANGE_H
#define CUBE_ARDUINO_SDK_VALUE_RANGE_H

#include "platform/Platform.h"

struct Range {
    long min;
    long max;
};

class ValueRange {
public:
    explicit ValueRange(long value = 0, Range range = {(long) 0, (long) 0}) : _value(value), _range(range) {}

    long map(Range out) const;

    long map(long min, long max) const;

    long value() const;

private:
    long _value;
    Range _range;
};

#endif //CUBE_ARDUINO_SDK_VALUE_RANGE_H

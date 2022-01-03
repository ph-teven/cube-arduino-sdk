#include "platform/Platform.h"

#ifndef LED_CONTROLLER_PARAMETER_H
#define LED_CONTROLLER_PARAMETER_H

struct Range {
    int min;
    int max;
};

class ValueRange {
public:
    explicit ValueRange(int value = 0, Range range = {0, 0}) : _value(value), _range(range) {}

    int map(Range out);

    int map(int min, int max);

    int value();

private:
    int _value;
    Range _range;
};

#endif //LED_CONTROLLER_PARAMETER_H

#ifndef CUBE_ARDUINO_SDK_CUBEARDUINO_H
#define CUBE_ARDUINO_SDK_CUBEARDUINO_H

#include "platform/Platform.h"
#include "platform/ArduinoPlatform.h"
#include "platform/TestPlatform.h"

#include "components/Button.h"
#include "components/Encoder.h"
#include "components/Poti.h"
#include "components/Switch.h"

#include "counter/RepeatingCounter.h"
#include "interval-counter/RepeatingIntervalCounter.h"
#include "counter/UpDownRepeatingCounter.h"

#include "Delta.h"
#include "interval/Interval.h"

#include "ValueRange.h"

Platform *arduinoPlatform() {
    return new ArduinoPlatform();
}

Platform *testPlatform() {
    return new TestPlatform();
}

#endif //CUBE_ARDUINO_SDK_CUBEARDUINO_H

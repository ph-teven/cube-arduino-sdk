#include "CubeArduino.h"

int main() {
    Platform *platform = arduinoPlatform();
    auto delta = new Delta(platform);

    auto currentDelta = delta->update();

    auto button = new Button(platform, 1, [] {});
    auto switchComponent = new Switch(platform, 1, [](bool toggled) {});
    auto poti = new Poti(platform, 1, range10Bit, [](bool toggled) {});
    auto encoder = new Encoder(
            platform,
            {1, 2, 3},
            {0, 100},
            0,
            1,
            [](int value) {},
            [](int value) {}
    );

    auto basicInterval = new BasicInterval(100, [] {});

    auto repeatingIntervalCounter = new RepeatingIntervalCounter(
            100,
            0,
            3,
            1,
            [](int value) {},
            [] {}
    );

    auto upDownRepeatingIntervalCounter = new UpDownRepeatingIntervalCounter(
            100,
            0,
            3,
            1,
            [](int value) {},
            [] {}
    );

    Updatable *updatables[7] = {
            button,
            switchComponent,
            poti,
            encoder,
            basicInterval,
            repeatingIntervalCounter,
            upDownRepeatingIntervalCounter
    };

    Counter *counters[4] = {
            new RepeatingCounter(0, 3, 1, [](int value) {}, []() {}),
            new UpDownRepeatingCounter(0, 3, 1, [](int value) {}, [] {}),
            repeatingIntervalCounter,
            upDownRepeatingIntervalCounter
    };

    for (auto updatable: updatables) {
        updatable->update(currentDelta);
    }

    for (auto counter: counters) {
        counter->increment();
    }

    repeatingIntervalCounter->increment();
    upDownRepeatingIntervalCounter->increment();
}
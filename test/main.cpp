#include "External.h"
#include "CubeArduino.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(CubeArduino, UpDownRepeatingCounterTest) {
    bool finished = false;
    int foo = -1;

    auto counter = new UpDownRepeatingCounter(
            0,
            3,
            1,
            [&foo](int value) {
                foo = value;
            },
            [&finished]() {
                finished = true;
            }
    );

    EXPECT_EQ(0, counter->getValue());

    counter->increment();
    counter->increment();
    counter->increment();
    EXPECT_EQ(3, counter->getValue());
    EXPECT_EQ(3, foo);

    counter->increment();
    counter->increment();
    counter->increment();
    EXPECT_EQ(0, counter->getValue());
    EXPECT_EQ(0, foo);

    EXPECT_TRUE(finished);
}

TEST(CubeArduino, EncoderTest) {
    int pinClk = 1;
    int pinDt = 2;
    int pinSw = 3;

    auto platform = new TestPlatform();
    auto delta = new Delta(platform);

    int pressedCount = false;

    auto encoder = new Encoder(
            platform,
            EncoderPins{pinClk, pinDt, pinSw},
            Range{0, 255},
            0,
            1,
            [](int value) {},
            [&pressedCount](int value) {
                pressedCount++;
            }
    );

    platform->DigitalWrite(pinSw, HIGH);
    encoder->update(delta->update());

    platform->DigitalWrite(pinSw, LOW);
    encoder->update(delta->update());

    EXPECT_EQ(1, pressedCount);
}

TEST(CubeArduino, ButtonTest) {
    int pin = 1;

    Platform *platform = new TestPlatform();
    auto delta = new Delta(platform);

    platform->DigitalWrite(pin, HIGH);

    bool pressed = false;

    auto *button = new Button(platform, pin, [&pressed] {
        pressed = true;
    });

    button->update(delta->update());
    EXPECT_TRUE(pressed);
}

TEST(CubeArduino, PotiTest) {
    int pin = 1;

    Platform *platform = new TestPlatform();
    auto delta = new Delta(platform);
    int analogValue = 542;
    platform->AnalogWrite(pin, analogValue);

    int foo = -1;

    auto poti = new Poti(platform, pin, Range{0, 256}, [&foo, &platform](int value) {
        foo = value;
    });

    EXPECT_EQ(135, poti->getValue());

    platform->AnalogWrite(pin, analogValue + 100);

    for (int i = 0; i < 100; i++) {
        poti->update(delta->update());
    }

    EXPECT_EQ(160, foo);
}

TEST(CubeArduino, BasicIntervalTest) {
    bool finished = false;

    auto interval = new BasicInterval(10, [&finished]() {
        finished = true;
    });

    EXPECT_EQ(10, interval->getDuration());
    interval->update(11);
    EXPECT_TRUE(finished);
}

TEST(CubeArduino, DeltaTest) {
    auto platform = new TestPlatform();
    auto delta = new Delta(platform);

    EXPECT_EQ(0, delta->update());
    platform->setTime(50);
    EXPECT_EQ(50, delta->update());
}

TEST(CubeArduino, RepeatingCounterTest) {
    bool finished = false;
    int foo = -1;

    auto counter = new RepeatingCounter(
            0,
            4,
            1,
            [&foo](int value) {
                foo = value;
            },
            [&finished]() {
                finished = true;
            }
    );

    EXPECT_EQ(0, counter->getValue());

    counter->increment();
    counter->increment();
    counter->increment();
    EXPECT_EQ(3, counter->getValue());
    EXPECT_EQ(3, foo);

    counter->increment();
    EXPECT_TRUE(finished);
    EXPECT_EQ(0, counter->getValue());
}


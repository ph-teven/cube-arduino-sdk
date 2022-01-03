#include <unity.h>
#include "CubeArduino.h"
#include "../../.pio/libdeps/native/ArduinoFake/src/Arduino.h"

void test_UpDownCounter() {
    bool finished = false;
    int foo = -1;

    auto counter = new UpDownCounter(
            0,
            3,
            [&foo](int value) {
                foo = value;
            },
            [&finished]() {
                finished = true;
            }
    );

    TEST_ASSERT_EQUAL(0, counter->getValue());

    counter->increment();
    counter->increment();
    counter->increment();
    TEST_ASSERT_EQUAL(3, counter->getValue());
    TEST_ASSERT_EQUAL(3, foo);

    counter->increment();
    counter->increment();
    counter->increment();
    TEST_ASSERT_EQUAL(0, counter->getValue());
    TEST_ASSERT_EQUAL(0, foo);

    TEST_ASSERT_TRUE(finished);
}

void test_encoder() {
    int pinClk = 1;
    int pinDt = 2;
    int pinSw = 3;

    auto platform = new TestPlatform();

    int pressedCount = false;

    auto encoder = new Encoder(
            EncoderPins{pinClk, pinDt, pinSw},
            platform,
            Range{0, 255},
            0,
            1,
            [](int value) {
            },
            [&pressedCount](int value) {
                pressedCount++;
            }
    );

    platform->DigitalWrite(pinSw, HIGH);
    encoder->update();

    platform->DigitalWrite(pinSw, LOW);
    encoder->update();

    TEST_ASSERT_EQUAL(1, pressedCount);
}

void test_button() {
    int pin = 1;

    Platform *platform = new TestPlatform();
    platform->DigitalWrite(pin, HIGH);

    bool pressed = false;

    auto *button = new Button(platform, pin, [&pressed] {
        pressed = true;
    });

    button->update();
    TEST_ASSERT_TRUE(pressed)
}

void test_poti() {
    int pin = 1;

    auto platform = new TestPlatform();
    int analogValue = 542;
    platform->AnalogWrite(pin, analogValue);

    int foo = -1;

    auto poti = new Poti(platform, pin, Range{0, 256}, [&foo, &platform](int value) {
        foo = value;
    });

    TEST_ASSERT_EQUAL(135, poti->getValue());

    platform->AnalogWrite(pin, analogValue + 100);

    for (int i = 0; i < 100; i++) {
        poti->update();
    }

    TEST_ASSERT_EQUAL(160, foo);
}

void test_interval() {
    bool finished = false;

    auto interval = new Interval(10, [&finished]() {
        finished = true;
    });

    TEST_ASSERT_EQUAL(10, interval->getDuration());
    interval->update(11);
    TEST_ASSERT_TRUE(finished)
}

void test_delta() {
    auto platform = new TestPlatform();
    auto delta = new Delta(platform);

    TEST_ASSERT_EQUAL(0, delta->update());
    platform->setTime(50);
    TEST_ASSERT_EQUAL(50, delta->update());
}

void test_repeating_counter() {
    bool finished = false;
    int foo = -1;

    auto counter = new RepeatingCounter(
            0,
            4,
            [&foo](int value) {
                foo = value;
            },
            [&finished]() {
                finished = true;
            },
            1
    );

    TEST_ASSERT_EQUAL(0, counter->getValue());

    counter->increment();
    counter->increment();
    counter->increment();
    TEST_ASSERT_EQUAL(3, counter->getValue());
    TEST_ASSERT_EQUAL(3, foo);

    counter->increment();
    TEST_ASSERT_TRUE(finished);
    TEST_ASSERT_EQUAL(0, counter->getValue());
}

void setUp(void) {
    ArduinoFakeReset();
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_UpDownCounter);
    RUN_TEST(test_encoder);
    RUN_TEST(test_poti);
    RUN_TEST(test_button);
    RUN_TEST(test_interval);
    RUN_TEST(test_delta);
    RUN_TEST(test_repeating_counter);

    return UNITY_END();
}

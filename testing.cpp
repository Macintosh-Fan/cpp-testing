#include "testing.hpp"

ClockTest::ClockTest() : startTime(0), endTime(0) {}

void ClockTest::start() {
    startTime = clock();
}

void ClockTest::end() {
    endTime = clock();
}

[[nodiscard]] clock_t ClockTest::getTestTime() const {
    return endTime - startTime;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#ifndef CPP_TESTING_TESTING_HPP
#define CPP_TESTING_TESTING_HPP

#include <ctime>

/**
 * An abstract class for code testing.
 *
 * @author Macintosh_Fan
 */
class Test {
protected:
    /**
     * The method for initializing the test.
     */
    virtual void start() = 0;

    /**
     * The method for finalizing the test.
     */
    virtual void end() = 0;

public:
    /**
     * Runs the test.
     */
    virtual void run() = 0;
};

/**
 * An abstract class for code testing with start and end times, using clock_t and clock().
 *
 * @author Macintosh_Fan
 */
class ClockTest : public Test {
    /**
     * The start time.
     */
    clock_t startTime;

    /**
     * The end time.
     */
    clock_t endTime;

protected:
    /**
     * Used for starting the test by setting the initial time.
     */
    void start() final;

    /**
     * Used for ending the test by setting the final time.
     */
    void end() final;

public:
    /**
     * Default constructor.
     */
    ClockTest();

    /**
     * @return the test time, as clock_t
     */
    [[nodiscard]] clock_t getTestTime() const;
};

#endif

#pragma clang diagnostic pop

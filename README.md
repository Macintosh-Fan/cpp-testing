# C++ Testing
This is just a simple project for making code testing easier, by utilizing object-oriented programming.

Example:
```cpp
#include <iostream>

/**
 * Data type for running the tests.
 */
typedef unsigned int test_t;

/**
 * Number of times to run the test.
 */
constexpr test_t TEST_TIMES = 1'000;

/**
 * Iteration count for the loop.
 */
constexpr test_t ITERATIONS = 10'000;

/**
 * A class for testing the increment operator a certain number of times.
 *
 * @author Macintosh_Fan
 */
class IncrementTest : public ClockTest {
public:
    /**
     * Runs the test.
     */
    void run() override {
        start();
        for (test_t i = 0; i < ITERATIONS; i++, i++);
        end();
    }
};

/**
 * A class for testing the addition operator.
 * 
 * @author Macintosh_Fan
 */
class AddTest : public ClockTest {
public:
    /**
     * Runs the test.
     */
    void run() override {
        start();
        for (test_t i = 0; i < ITERATIONS; i += 2);
        end();
    }
};

/**
 * The main function.
 *
 * @return exit code
 * @author Macintosh_Fan
 */
int main() {
    IncrementTest incrementTest = IncrementTest();
    AddTest addTest = AddTest();

    test_t incrementTestScore = 0;
    test_t addTestScore = 0;
    for (test_t i = 0; i < TEST_TIMES; i++) {
        incrementTest.run();
        addTest.run();

        clock_t incrementTestTime = incrementTest.getTestTime();
        clock_t addTestTime = addTest.getTestTime();

        if (incrementTestTime < addTestTime) {
            std::cout << incrementTestTime << " < " << addTestTime << '\n';
            std::cout << "Increment beat add by " << (addTestTime - incrementTestTime) << '\n';
            std::cout << '\n';
            incrementTestScore++;
        } else if (incrementTestTime > addTestTime) {
            std::cout << incrementTestTime << " > " << addTestTime << '\n';
            std::cout << "Add beat increment by " << (incrementTestTime - addTestTime) << '\n';
            std::cout << '\n';
            addTestScore++;
        } else {
            std::cout << incrementTestTime << " = " << addTestTime << '\n';
        }
    }

    std::cout << "Increment test score: " << incrementTestScore << '\n';
    std::cout << "Add test score: " << addTestScore << '\n';

    return 0;
}
```

/**
 * @brief example of thread_local usage
 */

#include "thread_local_variables.hpp"

#include <future>
#include <iostream>

thread_local unsigned short copied_value {0}; // copied to each thread
unsigned short shared_value {0}; // common to each thread

/**
 *
 */
void threadFunction(const unsigned short& sleepTime) {

    constexpr unsigned short ITERATIONS_AMOUNT {10};
    for (
        unsigned short i = 0;
        i < ITERATIONS_AMOUNT;
        i += 1
    ) {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(sleepTime)
        );

        copied_value += 1;
        shared_value += 1;

        std::cout << "copied value (sp: " << sleepTime << "): " << copied_value << std::endl;
        std::cout << "shared value (sp: " << sleepTime << "): " << shared_value << std::endl;
    }
}

/**
 *
 */
void runFunctionWithThreadLocal() {

    constexpr unsigned short FIRST_TASK_SLEEP_TIME {500};
    auto firstFuture = std::async(
        threadFunction,
        FIRST_TASK_SLEEP_TIME
    );

    constexpr unsigned short SECOND_TASK_SLEEP_TIME {1000};
    auto secondFuture = std::async(
        threadFunction,
        SECOND_TASK_SLEEP_TIME
    );

    firstFuture.wait();
    secondFuture.wait();
}

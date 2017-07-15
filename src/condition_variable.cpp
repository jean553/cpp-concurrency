/**
 * @brief condition variable usage example
 */

#include "condition_variable.hpp"

#include <thread>
#include <chrono>
#include <iostream>

/**
 *
 */
void firstThreadFunction(std::condition_variable& cv) {

    constexpr unsigned short SLEEP_TIME {3000};
    std::this_thread::sleep_for(
        std::chrono::milliseconds(SLEEP_TIME)
    );

    std::cout << "notify thread" << std::endl;

    cv.notify_one();

    std::cout << "thread notified" << std::endl;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(SLEEP_TIME)
    );

    std::cout << "terminate first thread" << std::endl;
}

/**
 *
 */
void functionWithConditionVariable() {

    std::condition_variable cv;

    std::thread firstThread(
        firstThreadFunction,
        std::ref(cv)
    );

    firstThread.join();
}

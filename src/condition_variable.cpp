/**
 * @brief condition variable usage example
 */

#include "condition_variable.hpp"

#include <thread>
#include <iostream>

/**
 *
 */
void firstThreadFunction(
    std::condition_variable& cv,
    std::mutex& mutex
) {

    std::cout << "first thread started" << std::endl;

    constexpr unsigned short SLEEP_TIME {5000};
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
void secondThreadFunction(
    std::condition_variable& cv,
    std::mutex& mutex
) {
    std::cout << "second thread started" << std::endl;

    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock);

    std::cout << "terminate second thread" << std::endl;
}

/**
 *
 */
void functionWithConditionVariable() {

    std::condition_variable cv;
    std::mutex mutex;

    std::thread firstThread(
        firstThreadFunction,
        std::ref(cv),
        std::ref(mutex)
    );

    std::thread secondThread(
        secondThreadFunction,
        std::ref(cv),
        std::ref(mutex)
    );

    firstThread.join();
    secondThread.join();
}

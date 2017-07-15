/**
 * @brief RAII thread example to make it non-joinable
 */

#include "raii_thread.hpp"

#include <iostream>

/**
 *
 */
RAIIThread::RAIIThread(
    const ThreadAction& action,
    std::thread&& thread
) : 
    action(action),
    thread(std::move(thread))
{
}

/**
 *
 */
RAIIThread::~RAIIThread() {

    if (not thread.joinable()) {
        return;
    }

    if (action == ThreadAction::Join) {
        thread.join();
    } else {
        thread.detach();
    } 
}

/**
 *
 */
void runThread() {

    constexpr unsigned short MAX_VALUE {10};
    for(
        auto i = 0;
        i < MAX_VALUE;
        i += 1
    ) {
        std::cout << i << std::endl;

        constexpr unsigned short SLEEP_TIME {1000};
        std::this_thread::sleep_for(
            std::chrono::milliseconds(SLEEP_TIME)
        );
    }
}

/**
 *
 */
void runRAIIThread() {

    std::thread thread(runThread);

    RAIIThread raiiThread(
        RAIIThread::ThreadAction::Join,
        std::move(thread)
    );
}

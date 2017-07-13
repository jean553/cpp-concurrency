/**
 * @brief simple function executed as a thread
 */

#include <iostream>
#include <thread>

/**
 *
 */
void displayFromTo(
    const unsigned short& start,
    const unsigned short& end
) {

    for(
        auto i = start;
        i < end;
        i += 1
    ) {
        std::cout << i << std::endl;
    }
}

/**
 *
 */
void runSimpleThread() {

    constexpr unsigned short FIRST_THREAD_START {0};
    constexpr unsigned short FIRST_THREAD_END {100};

    std::thread thread(
        displayFromTo,
        FIRST_THREAD_START,
        FIRST_THREAD_END
    );

    thread.join();
}

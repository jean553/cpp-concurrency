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
    const unsigned short& end,
    const unsigned short& sleepTime
) {

    for(
        auto i = start;
        i < end;
        i += 1
    ) {
        std::cout << i << std::endl;

        std::this_thread::sleep_for(
            std::chrono::milliseconds(sleepTime)
        );
    }
}

/**
 *
 */
void runSimpleThread() {

    constexpr unsigned short FIRST_THREAD_START {0};
    constexpr unsigned short FIRST_THREAD_END {10};
    constexpr unsigned short FIRST_SLEEP_TIME {1000};

    std::thread firstThread(
        displayFromTo,
        FIRST_THREAD_START,
        FIRST_THREAD_END,
        FIRST_SLEEP_TIME
    );

    constexpr unsigned short SECOND_THREAD_START {100};
    constexpr unsigned short SECOND_THREAD_END {110};
    constexpr unsigned short SECOND_SLEEP_TIME {500};

    std::thread secondThread(
        displayFromTo,
        SECOND_THREAD_START,
        SECOND_THREAD_END,
        SECOND_SLEEP_TIME
    );

    firstThread.join();
    secondThread.join();
}

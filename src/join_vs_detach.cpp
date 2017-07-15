/**
 * @brief join and detach usage example
 */

#include <thread>
#include <iostream>

/**
 *
 */
void runIntoThread(
    const unsigned short& threadId,
    const unsigned short& sleepTime
) {

    constexpr unsigned short MAX_VALUE {10};
    for(
        auto i = 0;
        i < MAX_VALUE;
        i += 1
    ) {
        std::cout << threadId << " : " << i << std::endl;

        std::this_thread::sleep_for(
            std::chrono::milliseconds(sleepTime)
        );
    }
}

/**
 *
 */
void executeThreadWithJoin() {

    constexpr unsigned short FIRST_THREAD_ID {1};
    constexpr unsigned short FIRST_THREAD_SLEEP_TIME {500};
    std::thread firstThread(
        runIntoThread,
        FIRST_THREAD_ID,
        FIRST_THREAD_SLEEP_TIME
    );

    constexpr unsigned short SECOND_THREAD_ID {2};
    constexpr unsigned short SECOND_THREAD_SLEEP_TIME {1000};
    std::thread secondThread(
        runIntoThread,
        SECOND_THREAD_ID,
        SECOND_THREAD_SLEEP_TIME
    );

    firstThread.join();
    secondThread.detach();

    std::cout << "finished" << std::endl;
}

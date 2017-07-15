/**
 * @brief example of std::mutex usage
 */

#include "mutex.hpp"

#include <thread>
#include <mutex>

/**
 *
 */
void saveContent(
    const std::string& key,
    const unsigned short& data,
    std::mutex& mutex,
    std::map<std::string, unsigned short>& container
) {
    constexpr unsigned short LONG_ACTION_TIME {3000};
    std::this_thread::sleep_for(
        std::chrono::milliseconds(LONG_ACTION_TIME)
    );

    std::lock_guard<std::mutex> guard(mutex);
    container[key] = data;
}

/**
 *
 */
void functionThatNeedsMutex() {

    std::map<std::string, unsigned short> container;
    std::mutex mutex;

    constexpr unsigned short FIRST_DATA {10};
    std::thread firstThread(
        saveContent,
        "first_key",
        FIRST_DATA,
        std::ref(mutex),
        std::ref(container)
    );

    constexpr unsigned short SECOND_DATA {10};
    std::thread secondThread(
        saveContent,
        "second_key",
        SECOND_DATA,
        std::ref(mutex),
        std::ref(container)
    );

    firstThread.join();
    secondThread.join();
}

/**
 * @brief task usage example
 */

#include <iostream>
#include <future>

/**
 *
 */
const unsigned short waitThenGetValue() {

    constexpr unsigned short SLEEP_TIME {5000};
    std::this_thread::sleep_for(
        std::chrono::milliseconds(SLEEP_TIME)
    );

    constexpr unsigned short RETURNED_VALUE {5};
    return RETURNED_VALUE;
}

/**
 *
 */
void runSimpleTask() {

    std::future<unsigned short> result = std::async(waitThenGetValue);

    auto value = result.get();
    std::cout << value << std::endl;
}

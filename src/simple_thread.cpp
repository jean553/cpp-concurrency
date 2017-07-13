/**
 * @brief simple function executed as a thread
 */

#include <iostream>
#include <thread>

/**
 *
 */
void displayNumbersUntilTen() {

    for(
        auto i = 0;
        i < 10;
        i += 1
    ) {
        std::cout << i << std::endl;
    }
}

/**
 *
 */
void runSimpleThread() {

    std::thread thread(displayNumbersUntilTen);
    thread.join();
}

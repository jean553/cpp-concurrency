/**
 * @brief condition variable usage example
 */

#include <condition_variable>

/**
 * @brief a first thread function;
 * waits three seconds, update the condition variable
 * and waits three other seconds
 *
 * @param reference to the condition variable to use to notify another thread
 * @param reference to the mutex to use
 */
void firstThreadFunction(
    std::condition_variable& cv,
    std::mutex& mutex
);

/**
 * @brief a second thread function;
 * waits three seconds, update the condition variable
 * and waits three other seconds
 *
 * @param reference to the condition variable to use to notify another thread
 * @param reference to the mutex to use
 */
void secondThreadFunction(
    std::condition_variable& cv,
    std::mutex& mutex
);

/**
 * @brief spaws two threads; one thread communicates
 * with the other using condition variable
 */
void functionWithConditionVariable();

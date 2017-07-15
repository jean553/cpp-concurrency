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
 */
void firstThreadFunction(std::condition_variable& cv);

/**
 * @brief spaws two threads; one thread communicates
 * with the other using condition variable
 */
void functionWithConditionVariable();

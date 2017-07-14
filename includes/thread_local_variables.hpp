/**
 * @brief example of thread_local usage
 */

/**
 * @brief simple thread function that declares thread_local variables
 *
 * @param sleep time between each iteration of the value
 */
void threadFunction(const unsigned short& sleepTime);

/**
 * @brief runs a function with thread_local
 */
void runFunctionWithThreadLocal();

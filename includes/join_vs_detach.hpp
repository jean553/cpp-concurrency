/**
 * @brief join and detach usage example
 */

/**
 * @brief function into a thread
 *
 * @param threadId an unique thread id
 * @param sleepTime the sleep time for each loop iteration
 */
void runIntoThread(
    const unsigned short& threadId,
    const unsigned short& sleepTime
);

/**
 * @brief execute two threads: one with join() and one with detach()
 */
void executeThreadsWithJoinAndDetach();

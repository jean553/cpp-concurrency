/**
 * @brief RAII thread example to make it non-joinable
 */

#include <thread>

class RAIIThread {

public:

    /**
     * @brief action to execute at the end of the thread,
     * join() or detach()
     */
    enum class ThreadAction {
        Join, /** < call join() to finish the thread */
        Detach /** < call detach() to finish the thread */
    };

    /**
     * @brief wrap a std::thread into a RAII class
     * ensuring the thread is correctly terminated
     * no matter what happens during the execution
     *
     * @param action call join or detach for the given thread
     * @param thread the thread to wrap
     */
    RAIIThread(
        const ThreadAction& action,
        std::thread&& thread
    );

    /**
     * @brief destructor, terminates the thread
     * correctly by calling join() or detach()
     * if the thread is joinable (running or ready to run)
     */
    ~RAIIThread();

private:

    ThreadAction action;
    std::thread thread;
};

/**
 * @brief function to be executed into a thread
 */
void runThread();

/**
 * @brief example usage of RAII Thread class
 */
void runRAIIThread();

#include "simple_thread.hpp"
#include "simple_task.hpp"
#include "thread_local_variables.hpp"
#include "join_vs_detach.hpp"
#include "raii_thread.hpp"
#include "mutex.hpp"

#include <iostream>

int main()
{
    functionThatNeedsMutex();

    return EXIT_SUCCESS;
}

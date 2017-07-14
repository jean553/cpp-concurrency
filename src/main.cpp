#include "simple_thread.hpp"
#include "simple_task.hpp"
#include "thread_local_variables.hpp"

#include <iostream>

int main()
{
    runFunctionWithThreadLocal();

    return EXIT_SUCCESS;
}

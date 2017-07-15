#include "simple_thread.hpp"
#include "simple_task.hpp"
#include "thread_local_variables.hpp"
#include "join_vs_detach.hpp"

#include <iostream>

int main()
{
    executeThreadWithJoin();

    return EXIT_SUCCESS;
}

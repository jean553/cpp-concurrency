# cpp-concurrency

Basic concurrency code snippets in C++.

## Compilation

```
mkdir build && cd build/
cmake ..
make
```

## Execution

```
./bin/cpp-concurrency
```

## CMake

The current CMake script supports CMake 2.8 and higher.

```cmake
cmake_minimum_required(VERSION 2.8)
```

Set the name of the project.

```cmake
project(cpp-concurrency)
```

Find the `Threads` package.
This is the `module` mode of CMake to find a package:
if the `findThreads.cmake` file is found, its content is executed by CMake;
the `.cmake` file usually contains the whole procedure to find and use external libraries
into the current project. They provide dependency information for the target.
They also perform all the preliminary checks indicating the library is correctly
installed on the current system and can be used as well.

```cmake
find_package(Threads)
```

Set the output path of the generated binary.

```cmake
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
```

The generated executable is not optimized for debug.

```cmake
set(CMAKE_BUILD_TYPE Release)
```

We compile using C++14, and we display all the warnings.

```cmake
add_compile_options(-std=c++14 -Wall)
```

Create a set of all the sources files.

```cmake
file(
    GLOB
    sources
    src/*
)
```

Integrate the includes files directory.

```cmake
include_directories(includes)
```

Specify the executable name after compilation.

```cmake
add_executable(
    cpp-concurrency
    ${sources}
)
```

The libraries of the `Threads` package are used during the linking process.
The command below adds `-lthread ...` to the compilation command.

```cmake
target_link_libraries(cpp-concurrency ${CMAKE_THREAD_LIBS_INIT})
```

## Concurrency theory

### Threads

Threads are independent sequences of execution.
Threads are started by processes and run into the same memory space.
Processes run in different memory spaces.

The "memory space" management/organization depends of the OS implementation,
but it's usually a space owned by one process (and many threads if the process is multithreaded).

![Image 1](images/threads_concurrency.png)

#### Hardware threads vs Software threads

Hardware threads are a feature of the processor. This is the entity that really makes calculations.
The amount of hardware threads is fixed and depends of the CPU.

Software threads are started by processes/OS, and managed by the OS.
They are sent to the hardware threads for execution.
Usually, if a software thread is blocking (waiting for an IO),
a hardware thread is able to take another software thread and executes it.

![Image 2](images/hardware_and_software_threads.png)

#### Basic concurrency with threads

The following code (in `simple_thread`) starts two threads,
and waits for each one to finish.

```cpp
std::thread firstThread(procedureToRun);

std::thread secondThread(procedureToRun);

firstThread.join();
secondThread.join();
```

Unlike `std::async` tasks, it is not possible to return values from `std::thread` functions.
If a `std::thread` function throws an exception, the program stops.
When using `std::thread`, there is no automatic management for the repartition and
oversubscription problems.

### Tasks

#### Simple tasks usage

An example of this feature can be found into `simple_task`.

A task is a function passed to `std::async`.
By using this function, a thread "might" be created to execute the passed function.
The standard library analyzes by itself if the creation of a new thread
is really necessary for the method (according to the processor hardware threads,
the CPU caches, the CPU specificities...). In some cases, the `std::async` method
will simply execute the given function in the same thread that asks for the task
result (`get` function).

```cpp
std::future<int> task = std::async(asynchronousFunction);

/* a lot of code */

auto result = task.get();
```

#### Oversubscription problem

This is a very common multi-threading problem.
This problem occures when the amount of available hardware threads
is lesser than the amount of non-blocking software threads,
ready to be executed.

The operation system allows each software thread to be executed
for a given time. When the time is over, another software thread
is executed by a hardware thread.

Every software switch is a `context switch` (the CPU hardware thread
must be refreshed in order to execute the new given thread).

`std::async` is a solution to this problem, as it may execute
the given function without any new thread creation.

#### Work stealing

Work stealing algorithms are used in multi-threading environments.

When threads are created, their instructions are put inside a queue,
in order to be executed by the hardware threads/processors.
When a hardware thread or a processor has nothing to do,
it checks the instructions queue of the other threads and
"steals" them to put them into its own queue.

#### `std::launch::async` vs `std::launch::deferred`

Instead of using `std::async`, we can use one of the two following functions:
 * `std::launch::async` passed method is executed asynchronously, into a different thread,
 * `std::launch::deferred` passed method is executed synchronously at the `get` or `wait` method invocation;
if no one of these two methods is called by the future object, the passed method is never executed.

If `std::async` is simply called, one of the two method above is applied. It could be a synchronous or
an asynchronous call. The `std::async` method will judge by itself which execution way is better
according to the current execution (oversubscription, work stealing, CPU...).

```cpp

/* function is executed asynchronously in a new thread */
auto future = std::async(
    std::launch::async,
    function
);

/* function is executed synchronously into the same thread when calling wait() */
auto future = std::async(
    std::launch::deferred,
    function
);

/* function is executed synchronously OR asynchronously */
auto future = std::async(function);

```

### `thread_local` variables

A variable declared with `thread_local` indicates that the given
variable is created for every new created thread.

An example can be found in `thread_local_variables`.

```cpp
thread_local unsigned short copied_value {10};
unsigned short shared_value {10};

void threadFunction() {

    /* shared_value is equal to the last value that has been set by a thread */
    /* copied_value is guarantee to be equal to 10 */

    copied_value += 1;
    shared_value += 1;
}

auto future = std::async(
    std::launch::async,
    threadFunction
);
```

### Check threads(s) amount of a running process

```bash
ps -e -T | grep cpp-concurrency
```

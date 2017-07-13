cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Release)
project(cpp-concurrency CXX)
find_package(Threads)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(EXECUTABLE cpp-concurrency)

add_compile_options(-pthread -std=c++14 -Wall)

file(
    GLOB
    sources
    src/*
)

include_directories(includes)

add_executable(
    ${EXECUTABLE}
    src/main.cpp
    ${sources}
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")
target_link_libraries(cpp-concurrency ${CMAKE_THREAD_LIBS_INIT})

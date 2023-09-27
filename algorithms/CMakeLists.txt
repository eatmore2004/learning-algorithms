cmake_minimum_required(VERSION 3.25)

project(algorithms)
set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES main.cpp)

add_executable(algorithms_run ${SOURCE_FILES})

include_directories(algolib)
add_subdirectory(algolib)

target_link_libraries(algorithms_run algolib_lib)

add_subdirectory(algolib_tests)
add_subdirectory(algolib_benchmarks)
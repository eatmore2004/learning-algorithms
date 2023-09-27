project(algolib_tests)
add_subdirectory(lib)

add_executable(algolib_tests_run algolib_test.cpp)
target_link_libraries(algolib_tests_run algolib_lib)
target_link_libraries(algolib_tests_run gtest gtest_main)

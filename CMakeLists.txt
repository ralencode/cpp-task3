cmake_minimum_required(VERSION 3.10)
project(doubly_linked_list)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)

add_executable(dll_demo
    main.cpp
    doubly_linked_list.h
    doubly_linked_list.tpp
)

add_executable(dll_tests
    tests.cpp
    doubly_linked_list.h
    doubly_linked_list.tpp
)
target_link_libraries(dll_tests GTest::GTest GTest::Main)

enable_testing()
add_test(NAME dll_tests COMMAND dll_tests)

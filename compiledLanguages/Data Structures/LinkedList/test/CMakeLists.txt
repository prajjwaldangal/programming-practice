cmake_minimum_required(VERSION 3.8)

set (This LinkedListTests)

set(Sources
    LinkedListTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} public
    gtest_main
    LinkedList
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
cmake_minimum_required(VERSION 3.8)

set(This LinkedList)

project(${This} C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    LinkedList.cpp
)

set(Sources
    implLnkLst.cpp
)

add_library(${This} STATIC ${Source} ${Headers})

add_subdirectory(test)
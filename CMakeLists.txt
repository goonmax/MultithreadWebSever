cmake_minimum_required(VERSION 3.8)

set(This Example)

project(${this} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    mutex.hpp
    )
set(Sources
    mutex.cpp
    )


add_library(${This} STATIC ${Sources} ${Headers})


add_subdirectory(test)

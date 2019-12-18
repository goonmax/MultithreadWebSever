cmake_minimum_required(VERSION 3.8)

set(Sources
    mutex.cpp
    )


add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    WS 
    )



add_test(
    NAME ${THIS}
    COMMAND ${This}
    )


cmake_minimum_required(VERSION 3.13.3)

set(This ttictactoe)

set(Sources
    tictactoe_test.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    tictactoe
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
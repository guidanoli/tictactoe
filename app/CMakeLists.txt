cmake_minimum_required(VERSION 3.13.3)

set(This cmdtictactoe)

set(Sources
    main.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    tictactoe
)
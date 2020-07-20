set(This tictactoe)

set(Sources
    state.cpp
    board.cpp
)

set(Headers
    state.hpp
    board.hpp
    types.hpp
)

add_library(${This} STATIC ${Sources} ${Headers})

target_include_directories(${This} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
add_library(tictactoe
    state.hpp
    state.cpp
    board.hpp
    board.cpp
    types.hpp
    defines.hpp)
target_include_directories(tictactoe PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}")
add_library(tictactoe
    state.hpp
    state.cpp)
target_include_directories(tictactoe PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}")
#ifndef TICTACTOE_STATE_H
#define TICTACTOE_STATE_H

#include "defines.hpp"
#include "types.hpp"
#include "board.hpp"

TICTACTOE_NAMESPACE_BEGIN

class State
{
	Symbol m_turn;
	Board m_board;
	Phase m_phase;
public:
	// Start with an empty board and
	// with one of the players beggining
	State(bool cross_begins);

	// Get turn (current player)
	Symbol getTurn() const;

	// Get constant reference to board
	Board const& getBoard() const;

	// Get current phase
	Phase getPhase() const;

	// Put current players' symbol in tile t
	// Returns true if successful
	bool update(Tile t);
};

TICTACTOE_NAMESPACE_END

#endif
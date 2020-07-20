#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include "defines.hpp"
#include "types.hpp"

TICTACTOE_NAMESPACE_BEGIN

class Board
{
	Symbol m_matrix[9];
public:
	// Start with an empty board
	Board();

	// Getter and setter
	Symbol getTileSymbol(Tile t) const;
	void setTileSymbol(Tile t, Symbol s);
};

TICTACTOE_NAMESPACE_END

#endif
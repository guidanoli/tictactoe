#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include "types.hpp"

#include <optional>

namespace tictactoe
{

	class Board
	{
		Symbol m_matrix[9];
	public:
		// Start with an empty board
		Board();

		// Getter and setter
		std::optional<Symbol> getTileSymbol(Tile t) const;
		bool setTileSymbol(Tile t, Symbol s);
	private:
		static std::optional<size_t> getIndex(Tile t);
	};

}

#endif
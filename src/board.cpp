#include "board.hpp"

#include <algorithm>

using namespace tictactoe;
using namespace std;

Board::Board()
{
	fill(m_matrix, m_matrix + 9, Symbol::EMPTY);
}

optional<Symbol> Board::getTileSymbol(Tile t) const
{
	auto idx_opt = getIndex(t);
	if (!idx_opt)
		return nullopt;
	return m_matrix[*idx_opt];
}

bool Board::setTileSymbol(Tile t, Symbol s)
{
	auto idx_opt = getIndex(t);
	if (!idx_opt)
		return false;
	m_matrix[*idx_opt] = s;
	return true;
}

optional<size_t> Board::getIndex(Tile t)
{
	if (!TileCheck(t))
		return nullopt;
	return static_cast<size_t>(t) - static_cast<size_t>(First<Tile>);
}
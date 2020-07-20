#include "state.hpp"

using namespace tictactoe;

State::State(bool cross_begins) :
	m_turn(cross_begins ? Symbol::CROSS : Symbol::CIRCLE),
	m_board(),
	m_phase(Phase::RUNNING)
{}

Symbol State::getTurn() const
{
	return m_turn;
}

Board const& State::getBoard() const
{
	return m_board;
}

Phase State::getPhase() const
{
	return m_phase;
}

bool State::update(Tile t)
{
	if (m_phase != Phase::RUNNING)
		return false;
	auto symbol_at_t = m_board.getTileSymbol(t);
	if (!symbol_at_t)
		return false;
	if (*symbol_at_t != Symbol::EMPTY)
		return false;
	m_board.setTileSymbol(t, m_turn);
	updatePhase();
	nextTurn();
	return true;
}

void State::nextTurn()
{
	if (m_turn == Symbol::CIRCLE)
		m_turn = Symbol::CROSS;
	else
		m_turn = Symbol::CIRCLE;
}

void State::updatePhase()
{
	static const Tile combinations[][3] = {
		{ Tile::A0, Tile::A1, Tile::A2 },
		{ Tile::B0, Tile::B1, Tile::B2 },
		{ Tile::C0, Tile::C1, Tile::C2 },
		{ Tile::A0, Tile::B0, Tile::C0 },
		{ Tile::A1, Tile::B1, Tile::C1 },
		{ Tile::A2, Tile::B2, Tile::C2 },
		{ Tile::A0, Tile::B1, Tile::C2 },
		{ Tile::A2, Tile::B1, Tile::C0 }
	};
	for (auto const& combination : combinations) {
		Symbol symbols[3];
		for (int i = 0; i < 3; ++i)
			symbols[i] = *m_board.getTileSymbol(combination[i]);
		if (symbols[0] != Symbol::EMPTY &&
			symbols[0] == symbols[1] && symbols[1] == symbols[2]) {
			m_phase = (symbols[0] == Symbol::CROSS) ?
				Phase::CROSS_WON : Phase::CIRCLE_WON;
			return;
		}
	}
	bool has_empty_tile = false;
	for (Tile t = Tile::A0; t < Tile::MAX; ++t) {
		if (*m_board.getTileSymbol(t) == Symbol::EMPTY) {
			has_empty_tile = true;
			break;
		}
	}
	if (!has_empty_tile)
		m_phase = Phase::CATS_GAME;
}
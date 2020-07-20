#include <iostream>

#include "board.hpp"
#include "types.hpp"
#include "state.hpp"

#include <gtest/gtest.h>

using namespace std;
using namespace tictactoe;

TEST(BoardTests, InitialState)
{
	Board b;
	for (Tile t = First<Tile>; t < Tile::MAX; ++t) {
		auto symbol_opt = b.getTileSymbol(t);
		ASSERT_TRUE(symbol_opt) << "t=" << static_cast<int>(t);
		auto symbol = *symbol_opt;
		EXPECT_EQ(symbol, Symbol::EMPTY) << "t=" << static_cast<int>(t);
	}
	EXPECT_FALSE(b.getTileSymbol(Tile::MIN));
	EXPECT_FALSE(b.getTileSymbol(Tile::MAX));
}

TEST(BoardTests, SetAndGet)
{
	Board b;
	b.setTileSymbol(Tile::A1, Symbol::CIRCLE);
	auto symbol_opt = b.getTileSymbol(Tile::A1);
	ASSERT_TRUE(symbol_opt);
	EXPECT_EQ(*symbol_opt, Symbol::CIRCLE);
}

TEST(TypeTests, TileCheck)
{
	for (Tile t = First<Tile>; t < Tile::MAX; ++t)
		EXPECT_TRUE(TileCheck(t));
	EXPECT_FALSE(TileCheck(Tile::MIN));
	EXPECT_FALSE(TileCheck(Tile::MAX));
}

TEST(TypeTests, SymbolCheck)
{
	for (Symbol s = First<Symbol>; s < Symbol::MAX; ++s)
		EXPECT_TRUE(SymbolCheck(s));
	EXPECT_FALSE(SymbolCheck(Symbol::MIN));
	EXPECT_FALSE(SymbolCheck(Symbol::MAX));
}

TEST(TypeTests, PhaseCheck)
{
	for (Phase ph = First<Phase>; ph < Phase::MAX; ++ph)
		EXPECT_TRUE(PhaseCheck(ph));
	EXPECT_FALSE(PhaseCheck(Phase::MIN));
	EXPECT_FALSE(PhaseCheck(Phase::MAX));
}

TEST(StateTests, InitialState)
{
	auto cross_st = State(true);
	EXPECT_EQ(cross_st.getTurn(), Symbol::CROSS);
	EXPECT_EQ(cross_st.getPhase(), Phase::RUNNING);
	for (Tile t = First<Tile>; t < Tile::MAX; ++t) {
		auto symbol_opt = cross_st.getBoard().getTileSymbol(t);
		ASSERT_TRUE(symbol_opt) << "t=" << static_cast<int>(t);
		auto symbol = *symbol_opt;
		EXPECT_EQ(symbol, Symbol::EMPTY) << "t=" << static_cast<int>(t);
	}
	auto circle_st = State(false);
	EXPECT_EQ(circle_st.getTurn(), Symbol::CIRCLE);
	EXPECT_EQ(circle_st.getPhase(), Phase::RUNNING);
	for (Tile t = First<Tile>; t < Tile::MAX; ++t) {
		auto symbol_opt = circle_st.getBoard().getTileSymbol(t);
		ASSERT_TRUE(symbol_opt) << "t=" << static_cast<int>(t);
		auto symbol = *symbol_opt;
		EXPECT_EQ(symbol, Symbol::EMPTY) << "t=" << static_cast<int>(t);
	}
}

class GameSimulation
{
	State st;
public:
	GameSimulation(bool crosses_first) : st(crosses_first) {}
	State const& getState() { return st; }
	void feedMoves(Tile const* begin, Tile const* end)
	{
		for (Tile const* t = begin; t != end; ++t)
		{
			EXPECT_TRUE(st.update(*t)) <<
				"Tile = " << static_cast<int>(*t) << endl <<
				"Phase = " << static_cast<int>(st.getPhase()) << endl <<
				"Turn = " << static_cast<int>(st.getTurn());
		}
	}
};

TEST(StateTests, CatsGame)
{
	auto game = GameSimulation(true);
	static const Tile moves[] = {
		Tile::A0,
		Tile::C2,
		Tile::C0,
		Tile::B0,
		Tile::B1,
		Tile::A2,
		Tile::A1,
		Tile::C1,
		Tile::B2
	};
	game.feedMoves(moves, moves + size(moves));
	EXPECT_EQ(game.getState().getPhase(), Phase::CATS_GAME);
}

TEST(StateTests, CrossWon)
{
	auto game = GameSimulation(true);
	static const Tile moves[] = {
		Tile::A0,
		Tile::B1,
		Tile::B0,
		Tile::A2,
		Tile::C0
	};
	game.feedMoves(moves, moves + size(moves));
	EXPECT_EQ(game.getState().getPhase(), Phase::CROSS_WON);
}

TEST(StateTests, CirclesWon)
{
	auto game = GameSimulation(false);
	static const Tile moves[] = {
		Tile::A0,
		Tile::B1,
		Tile::B0,
		Tile::A2,
		Tile::C0
	};
	game.feedMoves(moves, moves + size(moves));
	EXPECT_EQ(game.getState().getPhase(), Phase::CIRCLE_WON);
}
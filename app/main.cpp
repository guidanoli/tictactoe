#include <optional>
#include <cassert>
#include <iostream>

#include "state.hpp"

using namespace std;
using namespace tictactoe;

void printTurn(Symbol s)
{
	char c;
	switch (s) {
	case Symbol::CIRCLE:
		c = 'O';
		break;
	case Symbol::CROSS:
		c = 'X';
		break;
	default:
		assert(0);
		c = '?';
		break;
	}
	cout << "Turn: " << c << endl;
}

void printBoard(Board const& b)
{
	int cnt = 0;
	cout << "  A B C\n0 ";
	for (Tile t = First<Tile>; t < Tile::MAX; ++t) {
		auto symbol_opt = b.getTileSymbol(t);
		assert(symbol_opt);
		auto symbol = *symbol_opt;
		char c;
		switch (symbol) {
		case Symbol::EMPTY:
			c = '_';
			break;
		case Symbol::CIRCLE:
			c = 'O';
			break;
		case Symbol::CROSS:
			c = 'X';
			break;
		default:
			assert(0);
			c = '?';
			break;
		}
		cout << c << " ";
		++cnt;
		if (cnt % 3 == 0)
			cout << endl;
		if (cnt % 3 == 0 && cnt < 9)
			cout << (cnt / 3) << " ";
	}
}

optional<Tile> maybeGetTile()
{
	char column;
	int column_idx;
	int line_idx;
	
	cout << "Tile = ";
	cin >> column >> line_idx;
	
	if (column >= 'a' && column <= 'c')
		column_idx = column - 'a';
	else if (column >= 'A' && column <= 'C')
		column_idx = column - 'A';
	else
		return nullopt;

	if (line_idx < 0 || line_idx > 2)
		return nullopt;

	int idx = column_idx + 3 * line_idx;

	return static_cast<Tile>(static_cast<int>(First<Tile>) + idx);
}

void printPhase(Phase ph)
{
	string msg;
	switch (ph) {
	case Phase::RUNNING:
		msg = "Ongoing...";
		break;
	case Phase::CIRCLE_WON:
		msg = "O won!";
		break;
	case Phase::CROSS_WON:
		msg = "X won!";
		break;
	case Phase::CATS_GAME:
		msg = "Cat's game...";
		break;
	default:
		msg = "?";
		assert(0);
		break;
	}
	cout << msg << endl;
}

optional<bool> maybeGetBool(const char* yes, const char* no)
{
	cout << "* " << no << endl;
	cout << "* " << yes << endl;
	cout << ">>> ";
	string opt;
	cin >> opt;
	if (opt == yes)
		return true;
	else if (opt == no)
		return false;
	else
		return nullopt;
}

int main(int argc, char** argv)
{
	cout << "Who begins?" << endl;
	auto crosses = maybeGetBool("X", "O");
	while (!crosses) {
		cout << "Invalid input" << endl;
		crosses = maybeGetBool("X", "O");
	}
	State s(*crosses);
	while (s.getPhase() == Phase::RUNNING) {
		cout << endl;
		printBoard(s.getBoard());
		printTurn(s.getTurn());
		auto tile = maybeGetTile();
		while (!tile || !s.update(*tile)) {
			cout << "Invalid tile" << endl;
			tile = maybeGetTile();
		}
	}
	printBoard(s.getBoard());
	printPhase(s.getPhase());
	return 0;
}
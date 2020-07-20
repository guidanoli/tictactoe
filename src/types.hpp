#ifndef TICTACTOE_TYPES_H
#define TICTACTOE_TYPES_H

#include "defines.hpp"

TICTACTOE_NAMESPACE_BEGIN

//
//      |      |
//  A0  |  B0  |  C0
// _____|______|______
//      |      |
//  A1  |  B1  |  C1
// _____|______|______
//      |      |
//  A2  |  B2  |  C2
//      |      |
//

enum class Tile
{
	MIN,
	A0, B0, C0,
	A1, B1, C1,
	A2, B2, C2,
	MAX,
};

enum class Symbol
{
	MIN,
	EMPTY,
	CROSS,
	CIRCLE,
	MAX
};

enum class Phase
{
	MIN,
	RUNNING,
	CROSS_WON,
	CIRCLE_WON,
	MAX,
};

ADD_CHECK_OPERATOR_ON(Tile)
ADD_CHECK_OPERATOR_ON(Symbol)
ADD_CHECK_OPERATOR_ON(Phase)

TICTACTOE_NAMESPACE_END

#endif
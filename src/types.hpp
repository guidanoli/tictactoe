#ifndef TICTACTOE_TYPES_H
#define TICTACTOE_TYPES_H

#define CHECK_OPERATOR_ON(T) \
inline constexpr bool T ## Check(T t) \
{ \
	return (static_cast<int>(t) > static_cast<int>(T::MIN)) && \
	       (static_cast<int>(t) < static_cast<int>(T::MAX)); \
}

#define FIRST_OPERATOR_ON(T) \
template<> \
constexpr T First<T> = static_cast<T>(static_cast<int>(T::MIN) + 1);

#define ADD_OPERATOR_ON(T) \
inline constexpr T operator+(T t1, T t2) { \
	return static_cast<T>(static_cast<int>(t1) + static_cast<int>(t2)); \
} \
inline constexpr T& operator+=(T& t1, T& t2) { \
	return t1 = t1 + t2; \
} \
inline constexpr T& operator++(T& t) { \
	return t = static_cast<T>(static_cast<int>(t) + 1); \
}

namespace tictactoe
{

	template<typename T>
	constexpr T First = T();

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
		CATS_GAME,
		MAX,
	};

	FIRST_OPERATOR_ON(Tile)
	FIRST_OPERATOR_ON(Symbol)
	FIRST_OPERATOR_ON(Phase)

	CHECK_OPERATOR_ON(Tile)
	CHECK_OPERATOR_ON(Symbol)
	CHECK_OPERATOR_ON(Phase)

	ADD_OPERATOR_ON(Tile)
	ADD_OPERATOR_ON(Symbol)
	ADD_OPERATOR_ON(Phase)

}

#undef CHECK_OPERATOR_ON
#undef ADD_OPERATOR_ON
#undef FIRST_OPERATOR_ON

#endif
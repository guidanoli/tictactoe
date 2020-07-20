#ifndef TICTACTOE_DEFINES_H
#define TICTACTOE_DEFINES_H

#define TICTACTOE_NAMESPACE_BEGIN namespace tictactoe {
#define TICTACTOE_NAMESPACE_END }

#define ADD_CHECK_OPERATOR_ON(T) \
inline constexpr bool T ## Check(T t) \
{ \
	return (static_cast<int>(t) > static_cast<int>(T::MIN)) && \
	       (static_cast<int>(t) < static_cast<int>(T::MAX)); \
}

#endif
#include "Bishop.h"

void Bishop::generateFreeMoves()
{

}

inline Bitboard Bishop::getFreeMoves1(CKey field)
{
	return _bishop1_free_moves[field];
}
inline Bitboard Bishop::getFreeMoves3(CKey field)
{
	return _bishop3_free_moves[field];
}
inline Bitboard Bishop::getFreeMoves7(CKey field)
{
	return _bishop7_free_moves[field];
}
inline Bitboard Bishop::getFreeMoves9(CKey field)
{
	return _bishop9_free_moves[field];
}
Bitboard Bishop::cutRangeMoves(Bitboard moves, Bitboard enemy, Bitboard friends,
	Bitboard(Bishop:: * pMovesOppositeDirection)(CKey), CKey(Figure:: * pFirstBlocker)(Bitboard))
{
	Bitboard result = 0;

	Bitboard blockers = moves & (enemy | friends);
	if (blockers)
	{
		CKey key = (this->*pFirstBlocker)(blockers);
		Bitboard move_from_blocked = (this->*pMovesOppositeDirection)(key);
		result = (moves & move_from_blocked);
		result |= (convertFromCKey(key) & enemy);
	}
	else
		result = moves;

	return result;
}

Bitboard Bishop::getMoves1(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves1(field);
	return cutRangeMoves(free_moves, enemy, friends, &Bishop::getFreeMoves9, &Bishop::firstBlockerDown);
}
Bitboard Bishop::getMoves3(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves3(field);
	return cutRangeMoves(free_moves, enemy, friends, &Bishop::getFreeMoves7, &Bishop::firstBlockerUp);
}
Bitboard Bishop::getMoves7(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves3(field);
	return cutRangeMoves(free_moves, enemy, friends, &Bishop::getFreeMoves3, &Bishop::firstBlockerDown);
}
Bitboard Bishop::getMoves9(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves9(field);
	return cutRangeMoves(free_moves, enemy, friends, &Bishop::getFreeMoves1, &Bishop::firstBlockerUp);
}
Bitboard Bishop::getFreeMoves(CKey field)
{
	return (getFreeMoves1(field) |
			getFreeMoves3(field) |
			getFreeMoves7(field) |
			getFreeMoves9(field));
}
Bitboard Bishop::getMoves(CKey field, Bitboard enemy, Bitboard friends)
{
	return (getMoves1(field, enemy, friends) |
			getMoves3(field, enemy, friends) |
			getMoves7(field, enemy, friends) |
			getMoves9(field, enemy, friends));
}
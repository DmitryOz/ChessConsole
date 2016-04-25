#include "Bishop.h"

Bishop::Bishop()
{
	generateFreeMoves();
}
void Bishop::generateFreeMoves()
{
	const int lim = 8;
	for (int v = 0; v < lim; v++)
	{
		for (int h = 0; h < lim; h++)
		{
			CKey key = convertToCKeyFromLines(v, h);
			Bitboard result9 = 0;
			Bitboard result7 = 0;
			Bitboard result3 = 0;
			Bitboard result1 = 0;

			for (int i = v + 1, j = h + 1; i < lim && j < lim; i++, j++)
				result9 |= convertToBitboardFromLines(i, j);

			for (int i = v - 1, j = h - 1; i >= 0 && j>=0 ; i--, j--)
				result1 |= convertToBitboardFromLines(i, j);

			for (int i = v - 1, j = h + 1; i >= 0 && j < lim; i--, j++)
				result3 |= convertToBitboardFromLines(i, j);

			for (int i = v + 1, j = h - 1; i < lim && j >= 0; i++, j--)
				result7 |= convertToBitboardFromLines(i, j);

			_bishop9_free_moves[key] = result9;
			_bishop7_free_moves[key] = result7;
			_bishop3_free_moves[key] = result3;
			_bishop1_free_moves[key] = result1;
		}
	}
}

Bitboard Bishop::getFreeMoves1(CKey field)
{
	return _bishop1_free_moves[field];
}
Bitboard Bishop::getFreeMoves3(CKey field)
{
	return _bishop3_free_moves[field];
}
Bitboard Bishop::getFreeMoves7(CKey field)
{
	return _bishop7_free_moves[field];
}
Bitboard Bishop::getFreeMoves9(CKey field)
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
	return cutRangeMoves(free_moves, enemy, friends, &Bishop::getFreeMoves7, &Bishop::firstBlockerDown);
}
Bitboard Bishop::getMoves7(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves7(field);
	return cutRangeMoves(free_moves, enemy, friends, &Bishop::getFreeMoves3, &Bishop::firstBlockerUp);
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
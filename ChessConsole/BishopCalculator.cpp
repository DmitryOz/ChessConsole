#include "BishopCalculator.h"

BishopCalculator::BishopCalculator()
{
	generateFreeMoves();
}
void BishopCalculator::generateFreeMoves()
{
	const int lim = 8;
	for (int v = 0; v < lim; v++)
	{
		for (int h = 0; h < lim; h++)
		{
			CKey key = MoveConverter::convertToCKey(v, h);
			Bitboard result9 = 0;
			Bitboard result7 = 0;
			Bitboard result3 = 0;
			Bitboard result1 = 0;

			for (int i = v + 1, j = h + 1; i < lim && j < lim; i++, j++)
				result9 |= MoveConverter::convertToBitboard(i, j);

			for (int i = v - 1, j = h - 1; i >= 0 && j>=0 ; i--, j--)
				result1 |= MoveConverter::convertToBitboard(i, j);

			for (int i = v - 1, j = h + 1; i >= 0 && j < lim; i--, j++)
				result3 |= MoveConverter::convertToBitboard(i, j);

			for (int i = v + 1, j = h - 1; i < lim && j >= 0; i++, j--)
				result7 |= MoveConverter::convertToBitboard(i, j);

			_bishop9_free_moves[key] = result9;
			_bishop7_free_moves[key] = result7;
			_bishop3_free_moves[key] = result3;
			_bishop1_free_moves[key] = result1;
		}
	}
}

Bitboard BishopCalculator::getFreeMoves1(CKey field)
{
	return _bishop1_free_moves[field];
}
Bitboard BishopCalculator::getFreeMoves3(CKey field)
{
	return _bishop3_free_moves[field];
}
Bitboard BishopCalculator::getFreeMoves7(CKey field)
{
	return _bishop7_free_moves[field];
}
Bitboard BishopCalculator::getFreeMoves9(CKey field)
{
	return _bishop9_free_moves[field];
}
Bitboard BishopCalculator::cutRangeMoves(Bitboard moves, Bitboard enemy, Bitboard friends,
	Bitboard(BishopCalculator:: * pMovesOppositeDirection)(CKey), CKey(MoveCalculator:: * pFirstBlocker)(Bitboard))
{
	Bitboard result = 0;

	Bitboard blockers = moves & (enemy | friends);
	if (blockers)
	{
		CKey key = (this->*pFirstBlocker)(blockers);
		Bitboard move_from_blocked = (this->*pMovesOppositeDirection)(key);
		result = (moves & move_from_blocked);
		result |= (MoveConverter::convertToBitboard(key) & enemy);
	}
	else
		result = moves;

	return result;
}
Bitboard BishopCalculator::getMoves1(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves1(field);
	return cutRangeMoves(free_moves, enemy, friends, &BishopCalculator::getFreeMoves9, &BishopCalculator::firstBlockerDown);
}
Bitboard BishopCalculator::getMoves3(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves3(field);
	return cutRangeMoves(free_moves, enemy, friends, &BishopCalculator::getFreeMoves7, &BishopCalculator::firstBlockerDown);
}
Bitboard BishopCalculator::getMoves7(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves7(field);
	return cutRangeMoves(free_moves, enemy, friends, &BishopCalculator::getFreeMoves3, &BishopCalculator::firstBlockerUp);
}
Bitboard BishopCalculator::getMoves9(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves9(field);
	return cutRangeMoves(free_moves, enemy, friends, &BishopCalculator::getFreeMoves1, &BishopCalculator::firstBlockerUp);
}
Bitboard BishopCalculator::getFreeMoves(CKey field)
{
	return (getFreeMoves1(field) |
			getFreeMoves3(field) |
			getFreeMoves7(field) |
			getFreeMoves9(field));
}
Bitboard BishopCalculator::getMoves(CKey field, Bitboard enemy, Bitboard friends)
{
	return (getMoves1(field, enemy, friends) |
			getMoves3(field, enemy, friends) |
			getMoves7(field, enemy, friends) |
			getMoves9(field, enemy, friends));
}
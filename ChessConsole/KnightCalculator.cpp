#include "KnightCalculator.h"

KnightCalculator::KnightCalculator()
{
	generateMoves();
}
void KnightCalculator::generateMoves()
{
	const int lim = 8;
	for (int v = 0; v < lim; v++)
	{
		for (int h = 0; h < lim; h++)
		{
			Bitboard moves = 0;
			CKey key = MoveConverter::convertToCKey(v, h);
			if (v + 1 < lim && h - 2 >= 0)
				moves |= MoveConverter::convertToBitboard(v + 1, h - 2);
			if (v - 1 >= 0 && h - 2 >= 0)
				moves |= MoveConverter::convertToBitboard(v - 1, h - 2);

			if (v + 1 < lim && h + 2 < lim)
				moves |= MoveConverter::convertToBitboard(v + 1, h + 2);
			if (v - 1 >= 0 && h + 2 < lim)
				moves |= MoveConverter::convertToBitboard(v - 1, h + 2);

			if (v + 2 < lim && h - 1 >= 0)
				moves |= MoveConverter::convertToBitboard(v + 2, h - 1);
			if (v - 2 >= 0 && h - 1 >= 0)
				moves |= MoveConverter::convertToBitboard(v - 2, h - 1);

			if (v + 2 < lim && h + 1 < lim)
				moves |= MoveConverter::convertToBitboard(v + 2, h + 1);
			if (v - 2 >= 0 && h + 1 < lim)
				moves |= MoveConverter::convertToBitboard(v - 2, h + 1);

			_knight_moves[key] = moves;
		}
	}
}
Bitboard KnightCalculator::getFreeMoves(CKey field)
{
	return _knight_moves[field];
}
Bitboard KnightCalculator::getMoves(CKey field, Bitboard friends)
{
	Bitboard moves = getFreeMoves(field);
	Bitboard blockers = moves & friends;
	moves ^= blockers;
	return moves;
}
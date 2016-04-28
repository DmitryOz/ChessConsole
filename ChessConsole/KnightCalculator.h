#pragma once

#include "MoveCalculator.h"

class KnightCalculator : public MoveCalculator
{
	private:

		Bitboard _knight_moves[MAX_FIELDS];

		void generateMoves();

	public:

		Bitboard getMoves(CKey field, Bitboard enemy, Bitboard friends);
		Bitboard getFreeMoves(CKey field);
		KnightCalculator();
};
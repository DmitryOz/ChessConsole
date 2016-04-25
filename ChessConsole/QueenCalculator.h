#pragma once

#include "BishopCalculator.h"
#include "RookCalculator.h"

class QueenCalculator : public BishopCalculator, public RookCalculator
{
	public:

		Bitboard getFreeMoves(CKey field);
		Bitboard getMoves(CKey field, Bitboard enemy, Bitboard friends);
};
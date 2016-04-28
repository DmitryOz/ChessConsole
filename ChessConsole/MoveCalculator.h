#pragma once

#include "MoveConverter.h"

class MoveCalculator
{
	protected:

		static const CKey MAX_FIELDS = 64;

		virtual CKey firstBlockerDown(Bitboard x);							
		virtual CKey firstBlockerUp(Bitboard x);

	public:

		virtual Bitboard getMoves(CKey field, Bitboard enemy, Bitboard friends) = 0;
		virtual Bitboard getFreeMoves(CKey field) = 0;
};
#pragma once

#include "MoveConverter.h"

class MoveCalculator
{
	protected:

		static const CKey MAX_FIELDS = 64;

		CKey	 firstBlockerDown(Bitboard x);							
		CKey	 firstBlockerUp(Bitboard x);
};
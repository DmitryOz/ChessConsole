#pragma once

#include "PositionData.h"

class Figure
{
	protected:

		static const CKey MAX_FIELDS = 64;

		Bitboard convertFromCKey(CKey key);	
		CKey	 convertFromLines(HLine v, VLine h);			
		CKey	 firstBlockerDown(Bitboard x);							
		CKey	 firstBlockerUp(Bitboard x);
};
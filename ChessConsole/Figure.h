#pragma once

#include "PositionData.h"

class Figure
{
	protected:

		static const CKey MAX_FIELDS = 64;

		Bitboard convertToBitboardFromLines(int v, int h);
		CKey	 convertToCKeyFromLines(int v, int h);		
		CKey	 convertFromLines(HLine v, VLine h);			
		CKey	 firstBlockerDown(Bitboard x);							
		CKey	 firstBlockerUp(Bitboard x);

	public:

		Bitboard convertFromCKey(CKey key);


};
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

		/*
		Bitboard cutRangeMoves(Bitboard moves, Bitboard enemy, Bitboard friends,
			Bitboard(Figure:: * pMovesOppositeDirection)(CKey), CKey(Figure:: * pFirstBlocker)(Bitboard))
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
		*/
};
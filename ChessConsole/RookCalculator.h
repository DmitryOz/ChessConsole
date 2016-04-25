#pragma once
#include "MoveCalculator.h"

class RookCalculator : public MoveCalculator
{
	private:		

		Bitboard _rook8_free_moves[MAX_FIELDS];
		Bitboard _rook2_free_moves[MAX_FIELDS];
		Bitboard _rook4_free_moves[MAX_FIELDS];
		Bitboard _rook6_free_moves[MAX_FIELDS];

	private:

		void generateFreeMoves();		

		inline Bitboard getFreeMoves8(CKey field);		
		inline Bitboard getFreeMoves2(CKey field);	
		inline Bitboard getFreeMoves4(CKey field);
		inline Bitboard getFreeMoves6(CKey field);

		inline Bitboard cutRangeMoves(Bitboard moves, Bitboard enemy, Bitboard friends,
			Bitboard(RookCalculator:: * pMovesOppositeDirection)(CKey), CKey(MoveCalculator:: * pFirstBlocker)(Bitboard));


		inline Bitboard getMoves2(CKey field, Bitboard enemy, Bitboard friends);
		inline Bitboard getMoves8(CKey field, Bitboard enemy, Bitboard friends);
		inline Bitboard getMoves4(CKey field, Bitboard enemy, Bitboard friends);
		inline Bitboard getMoves6(CKey field, Bitboard enemy, Bitboard friends);		

	public:

		Bitboard getFreeMoves(CKey field);
		Bitboard getMoves(CKey field, Bitboard enemy, Bitboard friends);

		RookCalculator();
};
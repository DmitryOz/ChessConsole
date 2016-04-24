#pragma once

#include "Figure.h"

class Bishop : public Figure
{
	private:

		static const CKey MAX_FIELDS = 64;

		Bitboard _bishop1_free_moves[MAX_FIELDS];
		Bitboard _bishop3_free_moves[MAX_FIELDS];
		Bitboard _bishop7_free_moves[MAX_FIELDS];
		Bitboard _bishop9_free_moves[MAX_FIELDS];

	private:

		void generateFreeMoves();

		inline Bitboard getFreeMoves1(CKey field);
		inline Bitboard getFreeMoves3(CKey field);
		inline Bitboard getFreeMoves7(CKey field);
		inline Bitboard getFreeMoves9(CKey field);

		inline Bitboard cutRangeMoves(Bitboard moves, Bitboard enemy, Bitboard friends,
			Bitboard(Bishop:: * pMovesOppositeDirection)(CKey), CKey(Figure:: * pFirstBlocker)(Bitboard));


		inline Bitboard getMoves1(CKey field, Bitboard enemy, Bitboard friends);
		inline Bitboard getMoves3(CKey field, Bitboard enemy, Bitboard friends);
		inline Bitboard getMoves7(CKey field, Bitboard enemy, Bitboard friends);
		inline Bitboard getMoves9(CKey field, Bitboard enemy, Bitboard friends);

	public:

		Bitboard getFreeMoves(CKey field);
		Bitboard getMoves(CKey field, Bitboard enemy, Bitboard friends);

		Bishop();


};
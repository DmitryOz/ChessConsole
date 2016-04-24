#pragma once

#include "Bishop.h"
#include "Rook.h"

class Queen : public Bishop, public Rook
{
	public:

		Bitboard getFreeMoves(CKey field);
		Bitboard getMoves(CKey field, Bitboard enemy, Bitboard friends);
};
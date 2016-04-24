#pragma once

#include <string>

class Move
{
	public:

		enum MovedFigure		{ Pawn, Knight, Bishop, Rook, Queen, King, };
		enum MoveActionType		{ Simple, Take,	};
		enum MoveResultType		{ Simple, Check, DoubleCheck, Checkmate, Stealmate };
		enum MoveSpecialType	{ UsualMove, LongCastling, ShortCastling, Passant, BecomeQueen, BecomeRock, BecomeBishop, BecomeKnight,	};	

	private:

		short			_estimation;
		unsigned char	_move_coordinates;

};

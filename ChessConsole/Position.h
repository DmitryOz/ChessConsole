#pragma once

#include "PositionData.h"
#include <vector>
#include "Move.h"

#include "KnightCalculator.h"
#include "BishopCalculator.h"
#include "RookCalculator.h"
#include "QueenCalculator.h"

class Position
{
	public:

		typedef short Estimation;
		

		static const short WHITE_WIN = 9999;
		static const short BLACK_WIN = -9999;
		static const short NOT_SET   = 32767;

	private:
	
		PositionData _data;
		Color		 _turn;

		KnightCalculator _knight_calc;
		RookCalculator	_rook_calc;
		BishopCalculator _bishop_calc;
		QueenCalculator	_queen_calc;

	public:

		std::vector<Move> getMoveList();
		void addFigure(Color color, FiguresType type, CKey key);

		Position()
			:_turn(Color::White) {}
};
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

		std::vector<ChessField> _from_vec;
		std::vector<ChessField> _to_vec;
		std::vector<Move> _moves_vec;

		void addMovesToVec(Bitboard IN_figures, MoveCalculator * calc, Bitboard enemy, Bitboard friends);			
		
	public:

		const std::vector<Move> & getMovesVec();
		void addFigure(Color color, FiguresType type, CKey key);
		void changeColor();

		Position()
			:_turn(Color::White) {}
};
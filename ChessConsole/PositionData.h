#pragma once

#include <vector>
#include "GlobalDefinitions.h"

struct PositionData
{
	typedef unsigned long long Bitboard;

	enum Color		 { White, Black };
	enum FiguresType { Pawns, Knights, Bishops, Rooks, Queens };

	static const int number_of_colors		= 2;	
	static const int number_of_figure_types = 5;

	Bitboard _white_king;
	Bitboard _black_king;

	Bitboard _white_mask;
	Bitboard _black_mask;	
	
	struct SingleFigureArray
	{
		static const int max_figures = 10;
		
		//Interface:

		int size()						{ return 0; }
		Bitboard begin()				{ return 0; }
		Bitboard next(bool * is_end)	{ return 0; }
		void remove(Bitboard) {}
		void create(Bitboard) {}
	};

	private:

		inline void getSingle(Bitboard val);
		inline unsigned long long high_bit(unsigned long long  x);			
};
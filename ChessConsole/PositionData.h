#pragma once

#include "GlobalDefinitions.h"

struct PositionData
{
	public:

		static const int NUMBER_OF_COLORS = 2;	
		static const int FIGURE_TYPES	  = 5;

		CKey		_king[NUMBER_OF_COLORS];
		Bitboard	_figures[NUMBER_OF_COLORS][FIGURE_TYPES];	

		PositionData()
		{
			for (int i = 0; i < NUMBER_OF_COLORS; i++)
			{
				for (int j = 0; j < FIGURE_TYPES; j++)
				{
					_figures[i][j] = 0;
				}
			}
			_king[White] = E1;
			_king[Black] = E8;

			
		}
};
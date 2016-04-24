#pragma once

#include "Move.h"
#include "PositionData.h"
#include <cstdlib>
#include <vector>

class Position
{
	public:

		typedef short Estimation;
		

		static const short WHITE_WIN = 9999;
		static const short BLACK_WIN = -9999;
		static const short NOT_SET   = 0xFFFF;

	private:
	
		PositionData _data;
		
};
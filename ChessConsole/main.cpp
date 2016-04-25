#include "PositionData.h"

#include "RookCalculator.h"
#include "BishopCalculator.h"
#include "QueenCalculator.h"
#include "KnightCalculator.h"

#include "BitboardViewer.h"
#include "Position.h"
#include <string>

int main()
{
	BitboardViewer viewer;
	Position pos;
	pos.addFigure(White, Knight, G1);
	pos.addFigure(White, Knight, C3);
	pos.addFigure(White, Knight, F3);
	pos.addFigure(White, Knight, B1);
	auto res = pos.getMoveList();

	KnightCalculator calc;
	Bitboard m = calc.getMoves(C1, 0);
	viewer.show(m);
	
	std::cin.get();
	
	return 0;
}
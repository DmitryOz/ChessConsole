#include "PositionData.h"

#include "RookCalculator.h"
#include "BishopCalculator.h"
#include "QueenCalculator.h"
#include "KnightCalculator.h"

#include "BitboardViewer.h"
#include "Position.h"
#include <string>
#include <iostream>
#include <time.h>


int main()
{
	BitboardViewer viewer;
	Position pos;
	pos.addFigure(White, Knight, E5);
	pos.addFigure(White, Queen, E4);
	pos.addFigure(White, Bishop, C2);

	pos.addFigure(Black, Bishop, C4);
	pos.addFigure(Black, Knight, D5);
	pos.addFigure(Black, Rook, E3);
	pos.addFigure(Black, Bishop, F4);
	pos.addFigure(Black, Rook, G6);
	pos.addFigure(Black, Queen, G2);

	const int lim = 25521875; //5104320;// 52521875; //Brutforce depth = 5;//5104320;//
	unsigned long long i = 0;

	clock_t start = clock();
	for (; i < lim; i++)
	{
		auto & moves_ref = pos.getMovesVec();
		pos.changeColor();
	}
	clock_t elapsed = clock() - start;
	double time_elapsed = (double)elapsed / CLOCKS_PER_SEC;

	std::cout << "Operations: " << i << std::endl;
	std::cout << "Time: "		<< time_elapsed << std::endl;
	std::cout << "Operation per second: " << (unsigned long long)((double)i / (double)time_elapsed) << std::endl;

	KnightCalculator calc;

	Bitboard m = calc.getMoves(C1, 0,0);
	viewer.show(m);
	
	std::cin.get();
	
	return 0;
}
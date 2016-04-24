#include "PositionData.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "BitboardViewer.h"
#include <string>

int main()
{
	BitboardViewer viewer;
	Bitboard res;	

	Rook r;
	res = r.getMoves(A4, 0x44, 0x8000022);
	viewer.show(res);
	std::cout << std::endl;
	std::cout << std::endl;

	res = r.getFreeMoves(C7);
	viewer.show(res);
	std::cout << std::endl;
	std::cout << std::endl;

	Bishop b;
	res = b.getFreeMoves(B5);
	viewer.show(res);
	std::cout << std::endl;
	std::cout << std::endl;

	Queen q;
	res = q.getFreeMoves(E4);
	viewer.show(res);
	std::cout << std::endl;
	std::cout << std::endl;	

	std::cin.get();
	
	return 0;
}
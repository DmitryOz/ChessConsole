#include "PositionData.h"
#include "Rook.h"
#include "BitboardViewer.h"
#include <string>

int main()
{
	BitboardViewer viewer;
	Rook r;
	int a = sizeof(r);
		
	Bitboard res;	

	const unsigned long long lim = 0xFFFFFFFFFF - 15;
	unsigned long long i = 0;
	for (; i < lim; i++)
	{
		res = r.getMoves(A4, i, 0x8000022);
	}		

	res = r.getMoves(A4, 0x44, 0x8000022);
	viewer.show(res);

	std::cout << std::endl;
	std::cout << std::endl;

	res = r.getFreeMoves(C7);
	viewer.show(res);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::to_string(i);

	std::cin.get();
	
	return 0;
}
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
	Figure f;

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

	//Queen with bolckers:
	
	Bitboard blockers1 = 0;
	
	blockers1 |= f.convertFromCKey(A4);
	blockers1 |= f.convertFromCKey(B2);
	blockers1 |= f.convertFromCKey(C3);
	blockers1 |= f.convertFromCKey(D2);
	blockers1 |= f.convertFromCKey(E3);
	blockers1 |= f.convertFromCKey(F2);
	blockers1 |= f.convertFromCKey(G4);
	blockers1 |= f.convertFromCKey(G7);

	Bitboard blockers2 = 0;

	blockers2 |= f.convertFromCKey(A7);
	blockers2 |= f.convertFromCKey(B6);
	blockers2 |= f.convertFromCKey(D5);
	blockers2 |= f.convertFromCKey(D7);
	blockers2 |= f.convertFromCKey(E6);
	blockers2 |= f.convertFromCKey(F6);
	blockers2 |= f.convertFromCKey(H7);
	blockers2 |= f.convertFromCKey(H4);	

	res = q.getMoves(D4,blockers2,blockers1);
	viewer.show(res);
	std::cout << std::endl;
	std::cout << std::endl;

	
	std::cin.get();
	
	return 0;
}
#include "Position.h"

std::vector<Move> Position::getMoveList()
{
	std::vector<Move> result;

	Bitboard knights = _data._figures[_turn][FiguresType::Knight];
	//Bitboard bishops = _data._figures[_turn][FiguresType::Bishop];
	//Bitboard rooks	 = _data._figures[_turn][FiguresType::Rook];
	//Bitboard queens  = _data._figures[_turn][FiguresType::Queen];

	auto knight_list	= MoveConverter::divideToCKeys(knights);
	//auto bishop_list	= MoveConverter::divideToCKeys(bishops);
	//auto rook_list		= MoveConverter::divideToCKeys(rooks);
	//auto queen_list		= MoveConverter::divideToCKeys(queens);

	for (int i = 0; i < knight_list.size(); i++)
	{
		Bitboard knight_moves =  _knight_calc.getMoves(knight_list[i], knights);
		auto toList = MoveConverter::divideToCKeys(knight_moves);
		for (int j = 0; j < toList.size(); j++)
			result.push_back(Move(knight_list[i], toList[j]));
	}

	return result;
}
void Position::addFigure(Color color, FiguresType type, CKey key)
{
	if (type != FiguresType::King)
		_data._figures[color][type] |= MoveConverter::convertToBitboard(key);
	else
		_data._king[color] = key;
}
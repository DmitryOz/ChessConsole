#include "Position.h"

const std::vector<Move> & Position::getMovesVec()
{
	_moves_vec.clear();

	Bitboard friend_knights = _data._figures[_turn][FiguresType::Knight];
	Bitboard friend_bishops = _data._figures[_turn][FiguresType::Bishop];
	Bitboard friend_rooks = _data._figures[_turn][FiguresType::Rook];
	Bitboard friend_queens = _data._figures[_turn][FiguresType::Queen];

	Bitboard enemy_knights = _data._figures[!_turn][FiguresType::Knight];
	Bitboard enemy_bishops = _data._figures[!_turn][FiguresType::Bishop];
	Bitboard enemy_rooks = _data._figures[!_turn][FiguresType::Rook];
	Bitboard enemy_queens = _data._figures[!_turn][FiguresType::Queen];

	Bitboard friends = friend_knights | friend_bishops | friend_rooks | friend_queens;
	Bitboard enemy = enemy_knights | enemy_bishops | enemy_rooks | enemy_queens;

	addMovesToVec(friend_knights, &_knight_calc, enemy, friends);
	addMovesToVec(friend_bishops, &_bishop_calc, enemy, friends);
	addMovesToVec(friend_rooks, &_rook_calc, enemy, friends);
	addMovesToVec(friend_queens, &_queen_calc, enemy, friends);	

	return _moves_vec;
}
void Position::addFigure(Color color, FiguresType type, CKey key)
{
	if (type != FiguresType::King)
		_data._figures[color][type] |= MoveConverter::convertToBitboard(key);
	else
		_data._king[color] = key;
}
void Position::addMovesToVec(Bitboard IN_figures, MoveCalculator * calc, Bitboard enemy, Bitboard friends)
{
	_from_vec.clear();
	_from_vec.reserve(4);
	MoveConverter::divideToChessFields(IN_figures, _from_vec);
	Bitboard moves;
	for (int i = 0; i < _from_vec.size(); i++)
	{
		moves = calc->getMoves(_from_vec[i], enemy, friends);
		if (moves)
		{
			_to_vec.clear();
			_to_vec.reserve(10);
			MoveConverter::divideToChessFields(moves, _to_vec);
			for (int j = 0; j < _to_vec.size(); j++)
				_moves_vec.push_back(Move(_from_vec[i], _to_vec[j]));
		}
	}
}
void Position::changeColor()
{
	bool * pTurn = (bool *) &_turn;
	*pTurn = !(*pTurn);
}

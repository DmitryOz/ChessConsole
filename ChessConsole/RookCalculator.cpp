#include "RookCalculator.h"

RookCalculator::RookCalculator()
{
	generateFreeMoves();
}
Bitboard RookCalculator::getFreeMoves8(CKey field)
{
	return _rook8_free_moves[field];
} 		 
Bitboard RookCalculator::getFreeMoves2(CKey field)
{
	return _rook2_free_moves[field];
}
Bitboard RookCalculator::getFreeMoves4(CKey field)
{
	return _rook4_free_moves[field];
}
Bitboard RookCalculator::getFreeMoves6(CKey field)
{
	return _rook6_free_moves[field];
}

Bitboard RookCalculator::cutRangeMoves(Bitboard moves, Bitboard enemy, Bitboard friends,
	Bitboard(RookCalculator:: * pMovesOppositeDirection)(CKey), CKey(MoveCalculator:: * pFirstBlocker)(Bitboard))
{
	Bitboard result = 0;

	Bitboard blockers = moves & (enemy | friends);
	if (blockers)
	{
		CKey key = (this->*pFirstBlocker)(blockers);
		Bitboard move_from_blocked = (this->*pMovesOppositeDirection)(key);
		result = (moves & move_from_blocked);
		result |= (MoveConverter::convertToBitboard(key) & enemy);
	}
	else
		result = moves;

	return result;
}
Bitboard RookCalculator::getMoves2(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves2(field);
	return cutRangeMoves(free_moves, enemy, friends, &RookCalculator::getFreeMoves8, &RookCalculator::firstBlockerDown);
}
Bitboard RookCalculator::getMoves8(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves8(field);
	return cutRangeMoves(free_moves, enemy, friends, &RookCalculator::getFreeMoves2, &RookCalculator::firstBlockerUp);
}
Bitboard RookCalculator::getMoves4(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves4(field);
	return cutRangeMoves(free_moves, enemy, friends, &RookCalculator::getFreeMoves6, &RookCalculator::firstBlockerDown);
}
Bitboard RookCalculator::getMoves6(CKey field, Bitboard enemy, Bitboard friends)
{
	Bitboard free_moves = getFreeMoves6(field);
	return cutRangeMoves(free_moves, enemy, friends, &RookCalculator::getFreeMoves4, &RookCalculator::firstBlockerUp);
}
Bitboard RookCalculator::getFreeMoves(CKey field)
{
		return (	getFreeMoves2(field) | 
					getFreeMoves4(field) |
					getFreeMoves6(field) |
					getFreeMoves8(field) );
}
Bitboard RookCalculator::getMoves(CKey field, Bitboard enemy, Bitboard friends)
{
	return (getMoves2(field, enemy, friends) |
			getMoves4(field, enemy, friends) |
			getMoves6(field, enemy, friends) |
			getMoves8(field, enemy, friends));
}
void	 RookCalculator::generateFreeMoves()
{
	for (int byte_number = 0; byte_number < 8; byte_number++)
	{
		for (int bit_number = 0; bit_number < 8; bit_number++)
		{
			//Generate Vertical:
			Bitboard result = 0;
			unsigned char * pResult = ((unsigned char *)& result);
			unsigned char mask_vertical = (0xFF ^ (1 << bit_number));
			unsigned char mask_8 = (0xFF ^ (1 << bit_number)) ^ ((unsigned char)((1 << bit_number) - 1));
			unsigned char mask_2 = mask_vertical ^ mask_8;

			//moveUP vertical moves:
			pResult[byte_number] = mask_8;
			_rook8_free_moves[(byte_number << 3) | bit_number] = result;
			result = 0;
			//moveDown vertical moves:
			pResult[byte_number] = mask_2;
			_rook2_free_moves[(byte_number << 3) | bit_number] = result;


			//Generate Left:
			Bitboard result_left = 0;

			unsigned char * pResultLeft = ((unsigned char *)&result_left);
			for (int i = 0; i < byte_number; i++)
				pResultLeft[i] = (1 << bit_number);

			_rook4_free_moves[(byte_number << 3) | bit_number] = result_left;

			//Generate Right:
			Bitboard result_right = 0;
			unsigned char * pResultRight = ((unsigned char *)&result_right);

			if (byte_number != 7)
			{
				for (int i = byte_number + 1; i < 8; i++)
					pResultRight[i] = (1 << bit_number);
			}

			_rook6_free_moves[(byte_number << 3) | bit_number] = result_right;
		}
	}
}

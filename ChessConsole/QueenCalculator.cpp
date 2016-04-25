#include "QueenCalculator.h"

Bitboard QueenCalculator::getFreeMoves(CKey field)
{
	return (RookCalculator::getFreeMoves(field) | BishopCalculator::getFreeMoves(field));
}
Bitboard QueenCalculator::getMoves(CKey field, Bitboard enemy, Bitboard friends)
{
	return (RookCalculator::getMoves(field,enemy,friends) | BishopCalculator::getMoves(field, enemy, friends));
}
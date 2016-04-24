#include "Queen.h"

Bitboard Queen::getFreeMoves(CKey field)
{
	return (Rook::getFreeMoves(field) | Bishop::getFreeMoves(field));
}
Bitboard Queen::getMoves(CKey field, Bitboard enemy, Bitboard friends)
{
	return (Rook::getMoves(field,enemy,friends) | Bishop::getMoves(field, enemy, friends));
}
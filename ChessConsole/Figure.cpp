#include "Figure.h"

Bitboard Figure::convertToBitboardFromLines(int v, int h)
{
	return ((Bitboard)1 << ((v << 3) | h));
}
CKey	 Figure::convertToCKeyFromLines(int v, int h)
{
	return ((v << 3) | h);
}
CKey	 Figure::convertFromLines(HLine v, VLine h)
{
	return ((v << 3) | h);
}
Bitboard Figure::convertFromCKey(CKey key)
{
	return ((Bitboard)1 << key);
}
CKey	 Figure::firstBlockerDown(Bitboard blockers)
{
	const Bitboard t = 1;
	int bit_number = 0;
	if (blockers >= t << (32 + bit_number))	bit_number += 32;
	if (blockers >= t << (16 + bit_number))	bit_number += 16;
	if (blockers >= t << (8 + bit_number))	bit_number += 8;
	if (blockers >= t << (4 + bit_number))	bit_number += 4;
	if (blockers >= t << (2 + bit_number))	bit_number += 2;
	if (blockers >= t << (1 + bit_number))	bit_number += 1;

	return bit_number;
}
CKey	 Figure::firstBlockerUp(Bitboard blockers)
{
	int bit_number = 0;
	while (blockers)
	{
		if (blockers & 0x01)
			return bit_number;

		blockers >>= 1;
		bit_number++;
	}

	return 0;
}


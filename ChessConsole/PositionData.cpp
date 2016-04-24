#include "PositionData.h"

inline void PositionData::getSingle(Bitboard val)
{
	Bitboard res;
	while (val)
	{
		res = high_bit(val);
		val ^= res;		
		//write to buffer here;
	}
}	
inline unsigned long long PositionData::high_bit(unsigned long long  x) {
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x |= x >> 32;

	return x - (x >> 1);
}
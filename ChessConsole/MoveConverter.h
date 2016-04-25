#pragma once

#include "GlobalDefinitions.h"
#include <vector>

class MoveConverter
{
	public:

		static Bitboard convertToBitboard(int v, int h)
		{
			return ((Bitboard)1 << ((v << 3) | h));
		}
		static Bitboard convertToBitboard(CKey key)
		{
			return ((Bitboard)1 << key);
		}

		static CKey	 convertToCKey(int v, int h)
		{
			return ((v << 3) | h);
		}
		static CKey	 convertToCKey(HLine v, VLine h)
		{
			return ((v << 3) | h);
		}

		static std::vector<ChessField> divideToCKeys(Bitboard moves)
		{
			std::vector<ChessField> result;
			while (moves)
			{
				const Bitboard t = 1;
				CKey bit_number = A1;
				if (moves >= t << (32 + bit_number))	bit_number += 32;
				if (moves >= t << (16 + bit_number))	bit_number += 16;
				if (moves >= t << (8 + bit_number))		bit_number += 8;
				if (moves >= t << (4 + bit_number))		bit_number += 4;
				if (moves >= t << (2 + bit_number))		bit_number += 2;
				if (moves >= t << (1 + bit_number))		bit_number += 1;

				moves ^= convertToBitboard(bit_number);
				result.push_back((ChessField)bit_number);
			}	

			return result;
		}	
	
};
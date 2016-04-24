#pragma once

#include <iostream>
#include "GlobalDefinitions.h"

class BitboardViewer
{
	public:

	void show(Bitboard value)
	{
		unsigned char * pValue = ((unsigned char *)&value);
		
		for (int bit_number = 7; bit_number >= 0; bit_number--)
		{
			for (int byte_number = 0; byte_number < 8; byte_number++)
			{
				if (pValue[byte_number] & (1 << bit_number))
					std::cout << "+";
				else
					std::cout << "-";	
			}
			std::cout << std::endl;
		}		
	}
};
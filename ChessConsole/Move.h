#pragma once

#include "GlobalDefinitions.h"

struct Move
{
	ChessField _from;
	ChessField _to;

	Move() {}

	Move(CKey from, CKey to)
		:_from((ChessField)from), _to((ChessField)to) {}
};
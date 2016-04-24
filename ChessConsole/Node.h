#pragma once

#include "Position.h"
#include "Move.h"
#include <atomic>

std::_Atomic_counter_t counter;

class Node
{
	private:

		Node * _parent;
		Node * _brother;
		Node * _child;		

	private:

		static std::atomic<unsigned long long> _number_of_nodes;
				
	public:

		Node() { _number_of_nodes++; }
		
		int getNodesNumber() const { return _number_of_nodes; }
		

};

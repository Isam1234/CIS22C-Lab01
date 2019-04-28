// Template for the stack class

#ifndef _STACK_
#define _STACK_
#include "List.h" //list class

template< class STACKTYPE >
class Stack : private List<STACKTYPE>
{
public:

	int size() const
	{
		return getLength();
	}
	void push(const STACKTYPE &data)
	{
		insert(data, 0);
	}


	bool pop(STACKTYPE &data)
	{
		return remove(data, 0);
	}

	bool isStackEmpty() const
	{
		return this->isEmpty();
	}


	void printStack() const
	{
		this->print();
	}
};


#endif
#pragma once

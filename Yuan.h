/*
******************************************
*           Psuedocode Yuan.h          *
******************************************
Definition for the Dollar subclass

*/
#ifndef YUAN_H
#define YUAN_H

#include "Currency.h"
#include <string>

using namespace std;

// Yuan class inherited from currency class
class Yuan : public Currency
{
private:


public:

	//Constructors
	Yuan(unsigned wV, unsigned fV) : Currency("Yuan", "fen", wV, fV)
	{
	}

	Yuan() : Currency("Yuan", "fen")
	{
	}

	void updateCurrencyVal();

	// Overloaded Operators
	Yuan operator + (const Yuan &);
	Yuan operator + (const double);
	Yuan operator - (const Yuan &);
	Yuan operator - (const double);
	Yuan operator = (const Yuan &);
	Yuan operator = (const double);

	friend std::ostream& operator << (std::ostream &, const Yuan &);
	friend std::istream& operator >> (std::istream &, Yuan &);
};

#endif
#pragma once

/*
******************************************
*           Psuedocode Yen.h          *
******************************************
Definition for the Dollar subclass

*/
#ifndef YEN_H
#define YEN_H

#include "Currency.h"
#include <string>

using namespace std;

// Yen class inherited from currency class
class Yen : public Currency
{
private:

public:

	//Constructors
	Yen(unsigned wV, unsigned fV) : Currency("Yen", "sen", wV, fV)
	{
	}

	Yen() : Currency("Yen", "sen")
	{
	}

	void updateCurrencyVal();

	// Overloaded Operators
	Yen operator + (const Yen &);
	Yen operator + (const double);
	Yen operator - (const Yen &);
	Yen operator - (const double);
	Yen operator = (const Yen &);
	Yen operator = (const double);

	friend std::ostream& operator << (std::ostream &, const Yen &);
	friend std::istream& operator >> (std::istream &, Yen &);
};

#endif
#pragma once

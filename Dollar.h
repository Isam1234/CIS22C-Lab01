/*
******************************************
*           Psuedocode Dollar.h          *
******************************************
Definition for the Dollar subclass

*/
#ifndef DOLLAR_H
#define DOLLAR_H

#include "Currency.h"
#include <string>

using namespace std;

// Dollar class inherited from currency class
class Dollar : public Currency
{
private:


public:

	//Constructors
	Dollar(unsigned wV, unsigned fV) : Currency("Dollar", "Cent", wV, fV)
	{

	}

	Dollar() : Currency("Dollar", "Cent")
	{

	}

	void updateCurrencyVal();

	// Overloaded Operators
	Dollar operator + (const Dollar &);
	Dollar operator + (const double);
	Dollar operator - (const Dollar &);
	Dollar operator - (const double);
	Dollar operator = (const Dollar &);
	Dollar operator = (const double);

	friend std::ostream& operator << (std::ostream &, const Dollar &);
	friend std::istream& operator >> (std::istream &, Dollar &);

};

#endif
#pragma once

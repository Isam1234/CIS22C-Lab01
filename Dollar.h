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
/*
Psuedocode for the specific currency delarations:
There should be two constructores, one with default parameters and one with specific arguments
The class will have overloaded operators for addition, subtraction, comparison, input and output 
The class will have a function to update the values for the currency
*/
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

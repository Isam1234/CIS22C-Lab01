/*
******************************************
*           Psuedocode Euro.h          *
******************************************
Definition for the Dollar subclass

*/
#ifndef EURO_H
#define EURO_H

#include "Currency.h"
#include <string>

using namespace std;
/*
Psuedocode for the specific currency delarations:
There should be two constructores, one with default parameters and one with specific arguments
The class will have overloaded operators for addition, subtraction, comparison, input and output 
The class will have a function to update the values for the currency
*/
// Euro class inherited from currency class
class Euro : public Currency
{
private:


public:

	//Constructors
	Euro(unsigned wV, unsigned fV) : Currency("Euro", "Cent", wV, fV)
	{
	}

	Euro() : Currency("Euro", "Cent")
	{
	}

	void updateCurrencyVal();

	// Overloaded Operators
	Euro operator + (const Euro &);
	Euro operator + (const double);
	Euro operator - (const Euro &);
	Euro operator - (const double);
	Euro operator = (const Euro &);
	Euro operator = (const double);

	friend std::ostream& operator << (std::ostream &, const Euro &);
	friend std::istream& operator >> (std::istream &, Euro &);

};

#endif
#pragma once

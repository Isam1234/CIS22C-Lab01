/*
******************************************
*           Psuedocode Rupee.h          *
******************************************
Definition for the Dollar subclass

*/
#ifndef RUPEE_H
#define RUPEE_H

#include "Currency.h"
#include <string>

using namespace std;
/*
Psuedocode for the specific currency delarations:
There should be two constructores, one with default parameters and one with specific arguments
The class will have overloaded operators for addition, subtraction, comparison, input and output 
The class will have a function to update the values for the currency
*/
// Rupee class inherited from currency class
class Rupee : public Currency
{
private:


public:

	//Constructors
	Rupee(unsigned wV, unsigned fV) : Currency("Rupee", "paise", wV, fV)
	{
	}

	Rupee() : Currency("Rupee", "paise")
	{
	}

	void updateCurrencyVal();

	// Overloaded Operators
	Rupee operator + (const Rupee &);
	Rupee operator + (const double);
	Rupee operator - (const Rupee &);
	Rupee operator - (const double);
	Rupee operator = (const Rupee &);
	Rupee operator = (const double);

	friend std::ostream& operator << (std::ostream &, const Rupee &);
	friend std::istream& operator >> (std::istream &, Rupee &);
};

#endif
#pragma once

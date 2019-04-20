
#ifndef POUND_H
#define POUND_H

#include "Currency.h"
using namespace std;

//Pound class inherited form currency class
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

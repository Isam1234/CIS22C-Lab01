#ifndef EURO_H
#define EURO_H

#include "Currency.h"

using namespace std;

//Pound class inherited form currency class
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

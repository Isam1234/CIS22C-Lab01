#ifndef RUPEE_H
#define RUPEE_H

#include "Currency.h"

using namespace std;

//Dinar class inherited form currency class
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
	Rupee operator + (const Rupee &x);
	Rupee operator + (const double);
	Rupee operator - (const Rupee &);
	Rupee operator - (const double);
	Rupee operator = (const Rupee &);
	Rupee operator = (const double);

	friend std::ostream& operator << (std::ostream &, const Rupee &);
	friend std::istream& operator >> (std::istream &, Rupee &);
};

#endif

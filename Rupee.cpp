/*
******************************************
*           Psuedocode Rupee.cpp          *
******************************************
Roll fractional parts of currency into whole parts
Update whole and fractional values
Return new currency values
Add money to currency
Return new currency values
Subtract money from currency
Return new currency values
Check amount
Return amount

*/
#include "Rupee.h"
#include <cmath>

// Update whole and fractional parts
void Rupee::updateCurrencyVal()
{
	if (fractVal > 100)
	{
		wholeVal += fractVal / 1000;

		fractVal = fractVal % 1000;
	}
}

//Operator overload implementation
Rupee Rupee::operator + (const Rupee &x)
{
	Rupee newRupee;

	newRupee.setWholeVal(this->wholeVal + x.getWholeVal());
	newRupee.setFractVal(this->fractVal + x.getFractVal());
	newRupee.updateCurrencyVal();

	return newRupee;
}
Rupee Rupee::operator + (const double x)
{
	Rupee newRupee;

	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newRupee.setWholeVal(this->wholeVal + static_cast<unsigned>(whole));

	// Fractional part
	newRupee.setFractVal(this->fractVal + static_cast<unsigned>(fract));

	// Update currency values
	newRupee.updateCurrencyVal();

	return newRupee;
}
Rupee Rupee::operator - (const Rupee &x)
{
	Rupee newRupee;

	newRupee.setWholeVal(this->wholeVal - x.getWholeVal());
	newRupee.setFractVal(this->fractVal - x.getFractVal());
	newRupee.updateCurrencyVal();

	return newRupee;
}
Rupee Rupee::operator - (const double x)
{
	Rupee newRupee;

	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newRupee.setWholeVal(this->wholeVal - static_cast<unsigned>(whole));

	// Fractional part
	newRupee.setFractVal(this->fractVal - static_cast<unsigned>(fract));

	// Update currency values
	newRupee.updateCurrencyVal();

	return newRupee;
}
Rupee Rupee::operator = (const Rupee &x)
{
	Rupee newRupee;

	newRupee.setWholeVal(x.getWholeVal());
	newRupee.setFractVal(x.getFractVal());
	newRupee.updateCurrencyVal();

	return newRupee;
}
Rupee Rupee:: operator = (const double x)
{
	Rupee newRupee;
	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newRupee.setWholeVal(static_cast<unsigned>(whole));

	// Fractional part
	newRupee.setFractVal(static_cast<unsigned>(fract));

	// Update currency values
	newRupee.updateCurrencyVal();

	return newRupee;
}

std::ostream& operator << (std::ostream &out, const Rupee &x)
{
	double currencyValue = x.getWholeVal() + x.getFractVal();
	out << to_string(currencyValue);
	return out;
}
std::istream& operator >> (std::istream &in, Rupee &x)
{
	double fract,
		whole,
		val;

	in >> val;

	// Extract whole and fractional parts
	fract = modf(val, &whole);
	fract *= 100;
	fract = round(fract);

	Rupee newRupee;

	x.setWholeVal(static_cast<unsigned>(whole) + x.getWholeVal());
	x.setFractVal(fract + x.getFractVal());
	x.updateCurrencyVal();
	return in;
}

/*
******************************************
*           Psuedocode Euro.cpp          *
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
#include "Euro.h"
#include <cmath>

// Update whole and fractional parts
void Euro::updateCurrencyVal()
{
	if (fractVal > 100)
	{
		wholeVal += fractVal / 100;

		fractVal = fractVal % 100;
	}
}

//Operator overload implementation
Euro Euro::operator + (const Euro &x)
{
	Euro newEuro;

	newEuro.setWholeVal(this->wholeVal + x.getWholeVal());
	newEuro.setFractVal(this->fractVal + x.getFractVal());
	newEuro.updateCurrencyVal();

	return newEuro;
}
Euro Euro::operator + (const double x)
{
	Euro newEuro;

	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newEuro.setWholeVal(this->wholeVal + static_cast<unsigned>(whole));

	// Fractional part
	newEuro.setFractVal(this->fractVal + static_cast<unsigned>(fract));

	// Update currency values
	newEuro.updateCurrencyVal();

	return newEuro;
}
Euro Euro::operator - (const Euro &x)
{
	Euro newEuro;

	newEuro.setWholeVal(this->wholeVal - x.getWholeVal());
	newEuro.setFractVal(this->fractVal - x.getFractVal());
	newEuro.updateCurrencyVal();

	return newEuro;
}
Euro Euro::operator - (const double x)
{
	Euro newEuro;

	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newEuro.setWholeVal(this->wholeVal - static_cast<unsigned>(whole));

	// Fractional part
	newEuro.setFractVal(this->fractVal - static_cast<unsigned>(fract));

	// Update currency values
	newEuro.updateCurrencyVal();

	return newEuro;
}
Euro Euro::operator = (const Euro &x)
{
	Euro newEuro;

	newEuro.setWholeVal(x.getWholeVal());
	newEuro.setFractVal(x.getFractVal());
	newEuro.updateCurrencyVal();

	return newEuro;
}
Euro Euro:: operator = (const double x)
{
	Euro newEuro;
	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newEuro.setWholeVal(static_cast<unsigned>(whole));

	// Fractional part
	newEuro.setFractVal(static_cast<unsigned>(fract));

	// Update currency values
	newEuro.updateCurrencyVal();

	return newEuro;
}

std::ostream& operator << (std::ostream &out, const Euro &x)
{
	double currencyValue = x.getWholeVal() + x.getFractVal();
	out << to_string(currencyValue);
	return out;
}
std::istream& operator >> (std::istream &in, Euro &x)
{
	double fract,
		whole,
		val;

	in >> val;

	// Extract whole and fractional parts
	fract = modf(val, &whole);
	fract *= 100;
	fract = round(fract);

	Euro newEuro;

	x.setWholeVal(static_cast<unsigned>(whole) + x.getWholeVal());
	x.setFractVal(fract + x.getFractVal());
	x.updateCurrencyVal();
	return in;
}

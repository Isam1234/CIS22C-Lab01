
#include "Dollar.h"
#include <cmath>

// Update whole and fractional parts
void Dollar::updateCurrencyVal()
{
	if (fractVal > 100)
	{
		wholeVal += fractVal / 100;

		fractVal = fractVal % 100;
	}
}

//Operator overload implementation
Dollar Dollar::operator + (const Dollar &x)
{
	Dollar newDollar;

	newDollar.setWholeVal(this->wholeVal + x.getWholeVal());
	newDollar.setFractVal(this->fractVal + x.getFractVal());
	newDollar.updateCurrencyVal();

	return newDollar;
}
Dollar Dollar::operator + (const double x)
{
	Dollar newDollar;

	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newDollar.setWholeVal(this->wholeVal + static_cast<unsigned>(whole));

	// Fractional part
	newDollar.setFractVal(this->fractVal + static_cast<unsigned>(fract));

	// Update currency values
	newDollar.updateCurrencyVal();

	return newDollar;
}
Dollar Dollar::operator - (const Dollar &x)
{
	Dollar newDollar;

	newDollar.setWholeVal(this->wholeVal - x.getWholeVal());
	newDollar.setFractVal(this->fractVal - x.getFractVal());
	newDollar.updateCurrencyVal();

	return newDollar;
}
Dollar Dollar::operator - (const double x)
{
	Dollar newDollar;

	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newDollar.setWholeVal(this->wholeVal - static_cast<unsigned>(whole));

	// Fractional part
	newDollar.setFractVal(this->fractVal - static_cast<unsigned>(fract));

	// Update currency values
	newDollar.updateCurrencyVal();

	return newDollar;
}
Dollar Dollar::operator = (const Dollar &x)
{
	Dollar newDollar;

	newDollar.setWholeVal(x.getWholeVal());
	newDollar.setFractVal(x.getFractVal());
	newDollar.updateCurrencyVal();

	return newDollar;
}
Dollar Dollar:: operator = (const double x)
{
	Dollar newDollar;

	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newDollar.setWholeVal(static_cast<unsigned>(whole));

	// Fractional part
	newDollar.setFractVal(static_cast<unsigned>(fract));

	// Update currency values
	newDollar.updateCurrencyVal();

	return newDollar;
}

std::ostream& operator << (std::ostream &out, const Dollar &x)
{
	double currencyValue = x.getWholeVal() + x.getFractVal();
	out << to_string(currencyValue);
	return out;
}
std::istream& operator >> (std::istream &in, Dollar &x)
{
	double fract,
		whole,
		val;

	in >> val;

	// Extract whole and fractional parts
	fract = modf(val, &whole);
	fract *= 100;
	fract = round(fract);

	Dollar newDollar;

	x.setWholeVal(static_cast<unsigned>(whole) + x.getWholeVal());
	x.setFractVal(fract + x.getFractVal());
	x.updateCurrencyVal();

	return in;
}

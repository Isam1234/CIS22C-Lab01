/*
******************************************
*           Psuedocode Dollar.cpp          *
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
#include "Dollar.h"
#include <cmath>
/*Psuedocode for general Currency type:
update the currency when the fractional part is either above 99 or below 0 
create an addition operator that creates a new object and sets the input amount into the values
of the new object and then adds the object to the existing class.
The addition operator will also modify objects' types into types that can be used for combining whole values 
and fraction values of different types
The subtraction operator should effectivelydo the same thing as the addition operator.
The equals operator and comparison operators should either assign the value of a new object to
the current value in the wallet/class or determine if they are bigger or smaller values in the new object than
in the current values in the wallet/class.
The output stream operator should get the values in the wallet and return that value as a string
The input stream operator should get the input from the user and assign it to the wallet or 
appropriate class so that it may be used later on in the program.
*/
// Update whole and fractional parts
void Dollar::updateCurrencyVal()
{
	if (fractVal > 100)
	{
		wholeVal += fractVal / 100;

		fractVal = fractVal % 100;
	}
	else if (fractVal < 0)
	{
		wholeVal -= 1;
		fractVal += 100;
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

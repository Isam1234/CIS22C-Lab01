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
void Euro::updateCurrencyVal()
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

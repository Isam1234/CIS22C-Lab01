
#include "Yuan.h"

// Update whole and fractional parts
void Yuan::updateCurrencyVal()
{
	if (fractVal > 100)
	{
		wholeVal += fractVal / 100;

		fractVal = fractVal % 100;
	}
}

//Operator overload implementation
Yuan Yuan::operator + (const Yuan &x)
{
	Yuan newYuan;

	newYuan.setWholeVal(this->wholeVal + x.getWholeVal());
	newYuan.setFractVal(this->fractVal + x.getFractVal());
	newYuan.updateCurrencyVal();

	return newYuan;
}
Yuan Yuan::operator + (const double x)
{
	Yuan newYuan;

	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newYuan.setWholeVal(this->wholeVal + static_cast<unsigned>(whole));

	// Fractional part
	newYuan.setFractVal(this->fractVal + static_cast<unsigned>(fract));

	// Update currency values
	newYuan.updateCurrencyVal();

	return newYuan;
}
Yuan Yuan::operator - (const Yuan &x)
{
	Yuan newYuan;

	newYuan.setWholeVal(this->wholeVal - x.getWholeVal());
	newYuan.setFractVal(this->fractVal - x.getFractVal());
	newYuan.updateCurrencyVal();

	return newYuan;
}
Yuan Yuan::operator - (const double x)
{
	Yuan newYuan;

	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newYuan.setWholeVal(this->wholeVal - static_cast<unsigned>(whole));

	// Fractional part
	newYuan.setFractVal(this->fractVal - static_cast<unsigned>(fract));

	// Update currency values
	newYuan.updateCurrencyVal();

	return newYuan;
}
Yuan Yuan::operator = (const Yuan &x)
{
	Yuan newYuan;

	newYuan.setWholeVal(x.getWholeVal());
	newYuan.setFractVal(x.getFractVal());
	newYuan.updateCurrencyVal();

	return newYuan;
}
Yuan Yuan:: operator = (const double x)
{
	Yuan newYuan;
	double fract, whole;

	// Extract whole and fractional parts
	fract = modf(x, &whole);
	fract *= 100;
	fract = round(fract);

	// Whole part
	newYuan.setWholeVal(static_cast<unsigned>(whole));

	// Fractional part
	newYuan.setFractVal(static_cast<unsigned>(fract));

	// Update currency values
	newYuan.updateCurrencyVal();

	return newYuan;
}

std::ostream& operator << (std::ostream &out, const Yuan &x)
{
	double currencyValue = x.getWholeVal() + x.getFractVal();
	out << to_string(currencyValue);
	return out;
}
std::istream& operator >> (std::istream &in, Yuan &x)
{
	double fract,
		whole,
		val;

	in >> val;

	// Extract whole and fractional parts
	fract = modf(val, &whole);
	fract *= 100;
	fract = round(fract);

	Yuan newYuan;

	x.setWholeVal(static_cast<unsigned>(whole) + x.getWholeVal());
	x.setFractVal(fract + x.getFractVal());
	x.updateCurrencyVal();
	return in;
}

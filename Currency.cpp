#include <iostream>
#include "Currency.h" 

Currency::~Currency()
{
}

void Currency::empty() {
	Whole = 0;
	Fract = 0;
}

bool Currency::is_Empty()
{
	bool a = false;
	if (Whole == 0 && Fract == 0)
	{
		a = true;
	}
	return a;
}


std::istream& operator >> (std::istream  &in, Currency &c1)
{
	in >> c1.Whole;
	in >> c1.Fract;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Currency& c2)
{
	out << c2.Cur << "," << c2.Whole << "," << c2.Fract << "," << c2.Coin;
	return out;
}

Currency operator + (Currency const &c1, Currency const &c2) {
	Currency cur;
	cur.Whole = c1.Whole + c2.Whole;
	cur.Fract = c1.Fract + c2.Fract;
	if (cur.Fract >= 100)
	{
		cur.Whole = cur.Whole + (cur.Fract / 100);

		cur.Fract = (cur.Fract % 100);
	}
	return cur;
}

Currency operator - (Currency const &c1, Currency const &c2) {
	Currency cur;
	if (c1.Whole < c2.Whole) {

		std::cout << "Error!!! There is not suficient money" << std::endl;
	}
	else if (c1.Whole == c2.Whole && c1.Fract < c2.Fract) {

		std::cout << "Error!!! There is not suficient money" << std::endl;
	}
	else {
		cur.Whole = c1.Whole - c2.Whole;
		cur.Fract = c1.Fract - c2.Fract;

		if (cur.Fract < 0)
		{
			cur.Whole = (cur.Whole - 1);

			cur.Fract = ((c1.Fract + 100) - c2.Fract);
		}
	}
	return cur;
}
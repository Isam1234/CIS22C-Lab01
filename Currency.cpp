/*
******************************************
*       Psuedocode Currency.cpp          *
******************************************
Mutators and accessors
- 

*/
#include "Currency.h"

using namespace std;

Currency::Currency(string wN, string fN, unsigned wV, unsigned fV) : wholeName(wN), fractName(fN), wholeVal(wV), fractVal(fV)
{

}

Currency::Currency(string wN, string fN) : wholeName(wN), fractName(fN), wholeVal(0), fractVal(0)
{

}

// Mutators
void Currency::setWholeName(std::string wN)
{
	wholeName = wN;
}

void Currency::setFractName(std::string fN)
{
	fractName = fN;
}

void Currency::setWholeVal(const unsigned wV)
{
	wholeVal = wV;
}
void Currency::setFractVal(const unsigned fV)
{
	fractVal = fV;
}
void Currency::setZero()
{
	//wholeVal = 0;
	//fractVal = 0;
}

// Accessors
std::string Currency::getWholeName() const
{
	return wholeName;
}
std::string Currency::getFractName() const
{
	return fractName;
}
unsigned Currency::getWholeVal() const
{
	return wholeVal;
}
double Currency::getFractVal() const
{
	return fractVal;
}

//function that returns a bool to check if currency is empty
bool Currency::isZero() const
{
	if (wholeVal == 0 && fractVal == 0)
		return true;
	else
		return false;
}

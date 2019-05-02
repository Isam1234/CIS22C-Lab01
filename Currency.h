/*
******************************************
*           Psuedocode Currency.h        *
******************************************
Definitions for the Currency class

*/
#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <iostream>
/*
Psuedocode for currency class:
The currency class will have values that can only be accessed by methods
these attributes will be name, amount in whole, amount in fraction, and fraction name
The class needs constructors, one default, one with parameters.
The setters will take an argument that will be used for setting values in the class.
There will be an empty method that will set all the values to zero
there will be getters that will return all the values in the class.
The function that will tell the program if there is money in the wallet is either yes or no.
*/
class Currency
{
private:
	std::string wholeName;			// Name of Whole Part
	std::string fractName;			// Name of Fractional Part

protected:
	unsigned wholeVal,				// Value of Whole Part
		fractVal;					// Value of Fractional Part

public:
	// Constructor
	Currency(std::string, std::string, unsigned, unsigned);
	Currency(std::string, std::string);
	void setWholeName(std::string);
	void setFractName(std::string);
	void setWholeVal(const unsigned);
	void setFractVal(const unsigned);
	void setZero();
	std::string getWholeName() const;
	std::string getFractName() const;
	unsigned getWholeVal() const;
	double getFractVal() const;

	bool isZero() const;

	// Update whole and fractional parts
	virtual void updateCurrencyVal() = 0;


};

#endif


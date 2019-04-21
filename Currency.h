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

	// Mutators
	void setWholeName(std::string);
	void setFractName(std::string);
	void setWholeVal(const unsigned);
	void setFractVal(const unsigned);
	void setZero();

	// Accessors
	std::string getWholeName() const;
	std::string getFractName() const;
	unsigned getWholeVal() const;
	double getFractVal() const;

	bool isZero() const;

	// Update whole and fractional parts
	virtual void updateCurrencyVal() = 0;


};

#endif
#pragma once

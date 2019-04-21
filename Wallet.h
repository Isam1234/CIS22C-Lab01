/*
******************************************
*           Psuedocode Wallet.h          *
******************************************
Definitions for the Wallet class

*/
#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <iostream>

#include "Currency.h"
#include "Dollar.h"
#include "Rupee.h"
#include "Euro.h"
#include "Yen.h"
#include "Yuan.h"

class Wallet
{
private:
	// Currency Pointer for each currency type
	Currency *cPtr[5];

public:

	//enumerators to hold currency types
	static enum currencyFlag
	{
		DOLLAR,
		RUPEE,
		EURO,
		YEN,
		YUAN
	};

	//defaullt constructor
	Wallet();

	//default destructor
	~Wallet();

	int numOfCurrencies() const;
	bool checkCurrencyExist(currencyFlag);
	void addMoney(currencyFlag, const double);
	void subtractMoney(currencyFlag, const double);
	double getMoney(currencyFlag);
	void emptyWallet();
	bool checkIfEmpty();

};

#endif
#pragma once

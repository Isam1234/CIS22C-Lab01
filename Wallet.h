#pragma once
#include "Currency.h"
class Wallet
{
	Currency Curr[ARRAY_SIZE];
public:
	Currency & operator[] (const int index);
	int moneyAmount();
	void gain(int, int, int);
	void spend(int, int, int);
	bool moneyAvailable(int);
	bool isWalletEmpty();
	void empty(int);
};

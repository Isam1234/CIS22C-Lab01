#include <iostream>
#include <string>
#include "Wallet.h" 
#include "Currency.h" 
using namespace std;

Currency& Wallet::operator[] (const int i)
{
	return *(Curr[i]);
}

bool Wallet::isWalletEmpty() {
	bool f = false;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		f = Curr[i]->is_Empty();
		if (!f) {
			return f;
		}
	}
	return true;
}

int Wallet::moneyAmount()
{
	bool f = false;
	int n = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		f = Curr[i]->is_Empty();
		if (!f) {
			n++;
		}

	}
	return n;
}

bool Wallet::moneyAvailable(int cType) {
	return !Curr[cType]->is_Empty();
}

void Wallet::gain(int curType, int w, int f)
{
	Currency tmp1("", w, f, "");
	//curr[curType] = (curr[curType] + tmp1);
}

void Wallet::spend(int curType, int w, int f)
{
	Currency tmp1("", w, f, "");
	//curr[curType] = curr[curType] - tmp1;


}
void Wallet::empty(int curType) {
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		(Curr[curType])->empty();
	}
}
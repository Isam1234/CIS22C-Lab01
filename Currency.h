#pragma once
#include <iostream>
#include <string>
int const ARRAY_SIZE = 5;
typedef enum
{
	DOLLAR,
	EURO,
	YUAN,
	RUPEE,
	YEN,
} currencyType;

class Currency
{
	std::string Cur;
	int Whole;
	int Fract;
	std::string Coin;
public:
	Currency() {}
	Currency(std::string cn, int w, int f, std::string c) :
		Cur(cn), Whole(w), Fract(f), Coin(c) {}
	virtual ~Currency();
	void empty();
	bool is_Empty();
	friend std::istream& operator>>(std::istream& in, Currency &c1);
	friend std::ostream& operator<<(std::ostream& out, const Currency &c2);
	friend Currency operator + (Currency const &c1, Currency const &c2);
	friend Currency operator - (Currency const &c1, Currency const &c2);
};

class Yuan : public Currency
{
public:
	Yuan() : Currency("Yuan", 0, 0, "Fen") {}
	~Yuan() {}
};

class Yen :public Currency
{
public:
	Yen() : Currency("Yen", 0, 0, "Sen") {}
	~Yen() {}
};

class Euro :public Currency
{
public:
	Euro() : Currency("Euro", 0, 0, "Cent") {}
	~Euro() {}
};

class Dollar : public Currency
{
public:
	Dollar() : Currency("Dollar", 0, 0, "Cent") {}
	~Dollar() {}
};

class Rupee : public Currency
{
public:
	Rupee() : Currency("Rupee", 0, 0, "Paise") {}
	~Rupee() {}
private:
};

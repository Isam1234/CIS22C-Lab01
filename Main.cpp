#include "Wallet.h"
#include "Currency.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Currency *currency[ARRAY_SIZE];
	currency[DOLLAR] = new Dollar();
	currency[EURO] = new Euro();
	currency[YUAN] = new Yuan();
	currency[RUPEE] = new Rupee();
	currency[YEN] = new Yen();
	Wallet w;
	w[DOLLAR] = *(currency[DOLLAR]);
	w[EURO] = *(currency[EURO]);
	w[YUAN] = *(currency[YUAN]);
	w[RUPEE] = *(currency[RUPEE]);
	w[YEN] = *(currency[YEN]);
	string in; 
	while (true) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\t\t\tWallet" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		char choice;
		cout << "---------------------------" << endl;
		cout << "(1)View Amounts of Currency" << endl;
		cout << "(2)Add Money               " << endl;
		cout << "(3)Remove Money            " << endl;
		cout << "(4)Zero out Money          " << endl;
		cout << "(5)Report                  " << endl;
		cout << "(6)Exit                    " << endl;
		cout << "---------------------------" << endl;
		cout << "Enter Choice(1,2,3,4,5,6):";
		cin >> choice;
		if (choice == '1') {
			cout << "---------------------------" << endl;
			cout << "Currency Held: " << endl;
			cout << "Dollars: " << w[DOLLAR] << endl;
			cout << "Yen:     " << w[EURO] << endl;
			cout << "Euro:    " << w[YUAN] << endl;
			cout << "Rupee:   " << w[RUPEE] << endl;
			cout << "Yuan:    " << w[YEN] << endl;

		}
		if (choice == '2') {
			char choice2 = 'y';
			do {
				cout << "---------------------------" << endl;
				cout << "Currency Held: " << endl;
				cout << "Dollars: " << w[DOLLAR] << endl;
				cout << "Yen:     " << w[EURO] << endl;
				cout << "Euro:    " << w[YUAN] << endl;
				cout << "Rupee:   " << w[RUPEE] << endl;
				cout << "Yuan:    " << w[YEN] << endl;

				string type;
				int amnt;
				int decAmnt;
				cout << "Type of Currency(USD,YEN,EUR,RUP,YUN)?:";
				cin >> type;
				if (type == "USD") {
					cout << "enter Dollar amount: ";
					cin >> amnt;
					cout << "enter Cents amount: ";
					cin >> decAmnt;
					w.gain(DOLLAR, amnt, decAmnt);
				}
				else if (type == "EUR") {
					cout << "enter Euro amount: ";
					cin >> amnt;
					cout << "enter Cents amount: ";
					cin >> decAmnt;
					w.gain(EURO, amnt, decAmnt);
				}
				else if (type == "YUAN") {
					cout << "enter Yuan amount: ";
					cin >> amnt;
					cout << "enter fen amount: ";
					cin >> decAmnt;
					w.gain(YUAN, amnt, decAmnt);
				}
				else if (type == "RUP") {
					cout << "enter rupee amount: ";
					cin >> amnt;
					cout << "enter paise amount: ";
					cin >> decAmnt;
					w.gain(RUPEE, amnt, decAmnt);
				}
				else if (type == "YEN") {
					cout << "enter yen amount: ";
					cin >> amnt;
					cout << "enter sen amount: ";
					cin >> decAmnt;
					w.gain(YEN, amnt, decAmnt);
				}
				else {
					cout << "Choice not recognized" << endl;
				}
				cout << "add more money?(y/n):";
				cin >> choice2;

			} while (choice2 == 'y' || choice2 == 'Y');
			choice2 = 'y';
		}
		else if (choice == '3') {
			cout << "---------------------------" << endl;
			cout << "Currency Held: " << endl;
			cout << "Dollars: " << w[DOLLAR] << endl;
			cout << "Yen:     " << w[EURO] << endl;
			cout << "Euro:    " << w[YUAN] << endl;
			cout << "Rupee:   " << w[RUPEE] << endl;
			cout << "Yuan:    " << w[YEN] << endl;

			string type;
			int amnt;
			int decAmnt;

			cout << "Type of Currency(USD,YEN,EUR,RUP,YUN)?:";
			cin >> type;
			if (type == "USD") {
				cout << "enter Dollar amount: ";
				cin >> amnt;
				cout << "enter Cents amount: ";
				cin >> decAmnt;
				w.spend(DOLLAR, amnt, decAmnt);
			}
			else if (type == "EUR") {
				cout << "enter Euro amount: ";
				cin >> amnt;
				cout << "enter Cents amount: ";
				cin >> decAmnt;
				w.spend(EURO, amnt, decAmnt);
			}
			else if (type == "YUN") {
				cout << "enter Yuan amount: ";
				cin >> amnt;
				cout << "enter fen amount: ";
				cin >> decAmnt;
				w.spend(YUAN, amnt, decAmnt);
			}
			else if (type == "RUP") {
				cout << "enter rupee amount: ";
				cin >> amnt;
				cout << "enter paise amount: ";
				cin >> decAmnt;
				w.spend(RUPEE, amnt, decAmnt);
			}
			else if (type == "YEN") {
				cout << "enter yen amount: ";
				cin >> amnt;
				cout << "enter sen amount: ";
				cin >> decAmnt;
				w.spend(YEN, amnt, decAmnt);
			}
			else {
				cout << "Choice not recognized" << endl;
			}
		}
		else if (choice == '4') {
			char choice3;
			cout << "(1)Dollars" << endl;
			cout << "(2)Euro   " << endl;
			cout << "(3)Yuan   " << endl;
			cout << "(4)Rupee  " << endl;
			cout << "(5)Yen    " << endl;
			cout << "(6)All    " << endl;
			cout << "Enter which Currency type you wish to zero out: ";
			cin >> choice3;
			switch (choice3) {
			case '1':
				w.empty(DOLLAR);
				break;
			case '2':
				w.empty(EURO);
				break;
			case '3':
				w.empty(YUAN);
				break;
			case '4':
				w.empty(RUPEE);
				break;
			case '5':
				w.empty(YEN);
				break;
			case '6':
				w.empty(DOLLAR);
				w.empty(EURO);
				w.empty(YUAN);
				w.empty(RUPEE);
				w.empty(YEN);
				break;
			}
			cout << "---------------------------" << endl;
			cout << "Currency Held: " << endl;
			cout << "Dollars: " << w[DOLLAR] << endl;
			cout << "Yen:     " << w[EURO] << endl;
			cout << "Euro:    " << w[YUAN] << endl;
			cout << "Rupee:   " << w[RUPEE] << endl;
			cout << "Yuan:    " << w[YEN] << endl;

		}
		else if (choice == '5') {
			cout << "---------------------------" << endl;
			cout << "Currency Held: " << endl;
			cout << "Dollars: " << w[DOLLAR] << endl;
			cout << "Yen:     " << w[EURO] << endl;
			cout << "Euro:    " << w[YUAN] << endl;
			cout << "Rupee:   " << w[RUPEE] << endl;
			cout << "Yuan:    " << w[YEN] << endl;

		}
		else if (choice == '6') {
			break;
		}
		else {
			cout << "choice not recognized :))" << endl;
		}
	}
	return 0;
}

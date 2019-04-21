/*
*****************************************
*
*       Lab 1 - Wallet Program
*          Isa Muran (+1)
*          Laurie Hupman
*
****************************************/
#include <iostream>
#include <iomanip>
#include "Wallet.h"

using namespace std;

/*
*****************************************
*        Function protocols
*****************************************
*/
void addMoney(Wallet&);
void subtractMoney(Wallet&);
void viewWallet(Wallet&);
void emptyWallet(Wallet&);

/*
******************************************
*           Psuedocode Main              *
******************************************
Declare varibles to input choice from user
Diplay menu and take user input
Switch to perform user request
if choice is 1
call add money function
if choice is 2
call subtract money function
if choice is 3
call function that display money
if choice is 4
call function which removes all money
if choice is 5
close program
else
display error
*/
/*
Psuedocode for the main: 
create a wallet object
initiate a menu that will take a choice from the user
That choice will let them add money or take away money or view/empty the wallet.
*/
int main()
{
	Wallet myWallet;

	bool loop = false;

	while (loop == false)
	{
		int choice = 0;

		cout << endl << "	***YOUR WALLET***" << endl << endl;
		cout << "	 1: Add Money" << endl;
		cout << "	 2: Subtract Money" << endl;
		cout << "	 3: View Wallet" << endl;
		cout << "	 4: Empty Wallet" << endl;
		cout << "	 5: EXIT" << endl << endl;
		cout << "	 Enter your choice: ";

		cin >> choice;


		switch (choice)
		{
		case 1:
			system("cls");
			addMoney(myWallet);
			system("cls");
			break;

		case 2:
			system("cls");
			subtractMoney(myWallet);
			system("cls");
			break;

		case 3:
			system("cls");
			viewWallet(myWallet);
			system("cls");
			break;

		case 4:
			system("cls");
			emptyWallet(myWallet);
			system("cls");
			break;

		case 5:
			loop = true;
			delete myWallet;
			break;

		default:
			cout << "\t\t**Please enter a valid choice**\n" << endl; //error message when choice is not from the menu
			break;

		}

		system("cls"); //clear screen 

	}

	return 0;
}

/*
******************************************
*           Add Money Function           *
******************************************
Declare varibles to input choice from user
Diplay menu and take user input
Switch to perform user request
if choice is 1
take input value
add input to currency 1
if choice is 2
take input value
add input to currency 2
if choice is 3
take input value
add input to currency 3
if choice is 4
take input value
add input to currency 4
if choice is 5
take input value
add input to currency 5
if choice is 6
return to previous menu
else
display error
*/
/*
Psuedocode for addition:
create a menu that will ask the user to enter the currency of their choice and the amount they want to add.
once they have done so, tell them that you have added to the wallet and display the menu once mroe.
*/
void addMoney(Wallet &myWallet)
{

	bool loop = false;

	while (loop == false)
	{
		int choice = 0;

		double currency = 0;

		cout << endl << "	***Add Money to your wallet***" << endl << endl
			<< "	 1: Dollar" << endl
			<< "	 2: Rupee" << endl
			<< "	 3: Euro" << endl
			<< "	 4: Yen" << endl
			<< "	 5: Yuan" << endl
			<< "	 6: Exit" << endl << endl
			<< "	 Choice: ";
		cin >> choice;


		switch (choice)
		{
		case 1:
			cout << "How much would you like to add? (Format: n.nn)\n";
			cin >> currency;
			myWallet.addMoney(Wallet::DOLLAR, currency);

			cout << "Added " << fixed << setprecision(2) << currency << " in dollars to wallet\n" << endl;
			break;

		case 2:
			cout << "How much would you like to add? (Format: n.nn)\n";
			cin >> currency;
			myWallet.addMoney(Wallet::RUPEE, currency);

			cout << "Added " << fixed << setprecision(2) << currency << " in Rupee to wallet\n" << endl;
			break;

		case 3:
			cout << "How much would you like to add? (Format: n.nn)\n";
			cin >> currency;
			myWallet.addMoney(Wallet::EURO, currency);

			cout << "Added " << fixed << setprecision(2) << currency << " in euros to wallet\n" << endl;
			break;

		case 4:
			cout << "How much would you like to add? (Format: n.nn)\n";
			cin >> currency;
			myWallet.addMoney(Wallet::YEN, currency);

			cout << "Added " << fixed << setprecision(2) << currency << " in Yen to wallet\n" << endl;
			break;

		case 5:
			cout << "How much would you like to add? (Format: n.nn)\n";
			cin >> currency;
			myWallet.addMoney(Wallet::YUAN, currency);

			cout << "Added " << fixed << setprecision(2) << currency << " in Yuan to wallet\n" << endl;
			break;

		case 6:
			loop = true;
			break;

		default:
			cout << "\t\t**Please enter a valid choice**\n" << endl;
			break;

		}

	}
}

/*
******************************************
*      Subtract Money Function           *
******************************************
Declare varibles to input choice from user
Diplay menu and take user input
Switch to perform user request
if choice is 1
take input value
Subtract input from currency 1
if choice is 2
take input value
Subtract input from currency 2
if choice is 3
take input value
Subtract input from currency 3
if choice is 4
take input value
Subtract input from currency 4
if choice is 5
take input value
Subtract input from currency 5
if choice is 6
return to previous menu
else
display error
*/
/*
Psuedocode for subtraction:
create a menu that will allow a user to enter their desired currency and desired amount to take away.
check to see if the user has that much money in his wallet to subtract and subtract if the conditions are met.
once you have prompted that the subtraction has happened, feed the user back into the choice that they want for 
their desired currency.
*/
void subtractMoney(Wallet &myWallet)
{
	bool loop = false;

	while (loop == false)
	{
		int choice = 0;

		double currency = 0;

		cout << endl << "	***Subtract Money from your wallet***" << endl << endl
			<< "	 1: Dollar" << endl
			<< "	 2: Rupee" << endl
			<< "	 3: Euro" << endl
			<< "	 4: Yen" << endl
			<< "	 5: Yuan" << endl
			<< "	 6: Exit" << endl << endl
			<< "	 Choice: ";
		cin >> choice;


		switch (choice)
		{
		case 1:
			cout << "How much would you like to subtract? (Format: n.nn)\n";
			cin >> currency;
			myWallet.subtractMoney(Wallet::DOLLAR, currency);

			cout << "Subtracted " << fixed << setprecision(2) << currency << " in dollars to wallet\n" << endl;
			break;

		case 2:
			cout << "How much would you like to subtract? (Format: n.nn)\n";
			cin >> currency;
			myWallet.subtractMoney(Wallet::RUPEE, currency);

			cout << "Subtracted " << fixed << setprecision(2) << currency << " in Rupee to wallet\n" << endl;
			break;

		case 3:
			cout << "How much would you like to subtract? (Format: n.nn)\n";
			cin >> currency;
			myWallet.subtractMoney(Wallet::EURO, currency);

			cout << "Subtracted " << fixed << setprecision(2) << currency << " in euros to wallet\n" << endl;
			break;

		case 4:
			cout << "How much would you like to subtract? (Format: n.nn)\n";
			cin >> currency;
			myWallet.subtractMoney(Wallet::YEN, currency);

			cout << "Subtracted " << fixed << setprecision(2) << currency << " in Yen to wallet\n" << endl;
			break;

		case 5:
			cout << "How much would you like to subtract? (Format: n.nn)\n";
			cin >> currency;
			myWallet.subtractMoney(Wallet::YUAN, currency);

			cout << "Subtracted " << fixed << setprecision(2) << currency << " in Yuan to wallet\n" << endl;
			break;

		case 6:
			loop = true;
			break;

		default:
			cout << "\t\t**Please enter a valid choice**\n" << endl;
			break;

		}

	}
}
/*
Psuedocode for view function:
Display the contents of the wallet to the user's screen.
pretty simple.
*/
//Get values from wallet class and display them on screen
void viewWallet(Wallet &myWallet)
{
	cout << endl << "\t\t~Viewing Wallet~" << endl << endl
		<< "\t1: Dollars: " << fixed << setprecision(2) << myWallet.getMoney(Wallet::DOLLAR) << "\n"
		<< "\t2: Rupee: " << fixed << setprecision(2) << myWallet.getMoney(Wallet::RUPEE) << "\n"
		<< "\t3: Euro: " << fixed << setprecision(2) << myWallet.getMoney(Wallet::EURO) << "\n"
		<< "\t4: Yen: " << fixed << setprecision(2) << myWallet.getMoney(Wallet::YEN) << "\n"
		<< "\t5: Yuan: " << fixed << setprecision(2) << myWallet.getMoney(Wallet::YUAN) << "\n"
		<< endl << endl;

	system("pause");
}
// Psuedocode for empty function: Call the empty wallet function and tell the user when the wallet is emptied.
//Calls function from wallet class to set all values to zero
void emptyWallet(Wallet &myWallet)
{
	cout << endl << "	***Emptying Wallet...***" << endl;

	myWallet.emptyWallet();

	cout << endl << "	***Wallet Emptied***" << endl;

	system("pause");
}

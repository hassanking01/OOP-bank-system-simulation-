#pragma once
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clscurrency.h"
class clsfindcurrency : protected clsScreen
{
	enum shois {countery = 1 , currencycode =2};
	static void findbyname() {
		string readcountery = clsInputValidate::readString("\t\t\t\t\t\t enter the counter you want to search for : ");

		clscurrency currency = clscurrency::find(readcountery);
		while (currency.isEmpry())
		{
			cout << "\t\t\t\t\t\t we couldn't find this counter pleas try again \n";
			readcountery = clsInputValidate::readString("\t\t\t\t\t\t enter the counter you want to search for : ");
			currency = clscurrency::find(readcountery);

		}
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";
		cout << "\n\t\t\t\t\t\t|   countery    :" << left << setw(41) << " " + currency.countery << "|";
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

		cout << "\n\t\t\t\t\t\t| currency name :" << left << setw(41) << " " + currency.currencyname << "|";
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

		cout << "\n\t\t\t\t\t\t| currency code :" << left << setw(41) << " " + currency.currencycode << "|";
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

		cout << "\n\t\t\t\t\t\t|      Rate     :" << left << setw(41) << " " + to_string(currency.currencyrate) << "|";
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";
	}
	static void findbycode() {
		string readcode = clsInputValidate::readString("\t\t\t\t\t\t enter the currency code you want to search for : ");
	 vector	<clscurrency> currencyc = clscurrency::findcode(readcode);
		while (currencyc.size() == 0)
		{
			cout << "\t\t\t\t\t\t we couldn't find this code pleas try again \n";
			readcode = clsInputValidate::readString("\t\t\t\t\t\t enter the currency code you want to search for : ");
			currencyc = clscurrency::findcode(readcode);

		}
		for (clscurrency currency : currencyc) {
			cout << endl;
			cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";
			cout << "\n\t\t\t\t\t\t|   countery    :" << left << setw(41) << " " + currency.countery << "|";
			cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

			cout << "\n\t\t\t\t\t\t| currency name :" << left << setw(41) << " " + currency.currencyname << "|";
			cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

			cout << "\n\t\t\t\t\t\t| currency code :" << left << setw(41) << " " + currency.currencycode << "|";
			cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

			cout << "\n\t\t\t\t\t\t|      Rate     :" << left << setw(41) << " " + to_string(currency.currencyrate) << "|";
			cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

		}
	}

	static void readinput(shois i) {
		switch (i)
		{
		case clsfindcurrency::countery:
			findbyname();
			break;
		case clsfindcurrency::currencycode:
			findbycode();
			break;
		default:
			break;
		}
	}

public:
	static void findcurrecny() {


		int list = clsInputValidate::readIntBetween(1, 2, "\t\t\t\t\t\t do you want to search by counter name or currency code \n\t\t\t\t\t\t [1] counter name \n\t\t\t\t\t\t [2] currency code \n\t\t\t\t\t\t enter a number in this list : " , "\t\t\t\t\t\t Invalid number pleas try again");

		readinput((shois)list);


	}
};


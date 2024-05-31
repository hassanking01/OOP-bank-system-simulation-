#pragma once
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clscurrency.h"
class clsUpdatecurrencyrate : protected clsScreen
{
	static void findbycode() {
		string readcode = clsInputValidate::readString("\t\t\t\t\t\t enter the currency code you want to search for : ");
		vector	<clscurrency> currencyc = clscurrency::findcode(readcode);
		while (currencyc.size() == 0)
		{
			cout << "\t\t\t\t\t\t we couldn't find this code pleas try again \n";
			readcode = clsInputValidate::readString("\t\t\t\t\t\t enter the currency code you want to search for : ");
			currencyc = clscurrency::findcode(readcode);

		}
		string masseg = "\t\t\t\t\t\t enter the new rate : ";
		float rate = clsInputValidate::readDouble(masseg, "Invalid number");
		clscurrency::enSave result;
		for (clscurrency & currency : currencyc) {
			currency.currencyrate = rate;
			cout << endl;
			result = currency.save();
			switch (result)
			{
			case clscurrency::svSuccessfully:
				cout << "\t\t\t\t\t\t done successfully \n";
				break;
			case clscurrency::svEmptyObject:
				cout << "\t\t\t\t\t\t error the obgect is empty \n";
				break;
			default:
				break;
			}
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

public:
	static void updaterate() {
		system("cls");
		_DrowHeader("update rate screen");
		findbycode();
	}
};


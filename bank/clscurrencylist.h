#pragma once
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clscurrency.h"
class clscurrencylist : protected clsScreen
{

	static void printcurrency(clscurrency currency) {
		cout << "\n\t\t\t\t\t\t";
		cout << "|" << left << setw(33) << "      " + currency.countery;
		cout << "|" << left << setw(6) << " " + currency.currencycode ;
		cout << "|" << left << setw(41) << " " + currency.currencyname;
		cout << "|" << left << setw(33) << "   " + to_string(currency.currencyrate) << "|";
		cout << "\n\t\t\t\t\t\t|--------------------------------------------------------------------------------------------------------------------|";
	}
public:
	static void _currencylist() {
		vector <clscurrency> vtcurrencyes = clscurrency::GetcurrencyesData();
		string list = "(" + to_string(vtcurrencyes.size()) + ") currencis";
		_DrowHeader("currency list ", list);

		cout << "\n\t\t\t\t\t\t|--------------------------------------------------------------------------------------------------------------------|";

		cout << "\n\t\t\t\t\t\t";
		cout << "|" << left << setw(33) << "      countery";
		cout << "|" << left << setw(6) << " code ";
		cout << "|" << left << setw(41) << "   currency name ";
		cout << "|" << left << setw(33) << "   currency Rate" << "|";
		cout << "\n\t\t\t\t\t\t|--------------------------------------------------------------------------------------------------------------------|";

		for (clscurrency currnecy : vtcurrencyes) {
			printcurrency(currnecy);
		}

	}
};


#pragma once
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clscurrency.h"
class clscurrnceycalculator : protected clsScreen
{


public :
	static void calculator() {

		_DrowHeader("currency calculator screen");
		string currency1 = clsInputValidate::readString("\t\t\t\t\t\t enter the first currencey code : ");
		vector <clscurrency> currency1code = clscurrency::findcode(currency1);
		while (currency1code.size() == 0)
		{
			cout << "\n\t\t\t\t\t\t the is no currency white this code try again .\n";
			currency1 = clsInputValidate::readString("\t\t\t\t\t\t enter the first currencey code : ");
			currency1code = clscurrency::findcode(currency1);
		}
		cout << "\n";
		string currency2 = clsInputValidate::readString("\t\t\t\t\t\t enter the sicend currency code : ");
		
		vector <clscurrency> currency2code = clscurrency::findcode(currency2);
		while (currency2code.size() == 0)
		{
			cout << "\n\t\t\t\t\t\t the is no currency white this code try again .\n";
			currency2 = clsInputValidate::readString("\t\t\t\t\t\t enter the first currencey code : ");
			currency1code = clscurrency::findcode(currency2);
		}
		cout << endl;
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";
		cout << "\n\t\t\t\t\t\t|   countery    :" << left << setw(41) << " " + currency1code[0].countery << "|";
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

		cout << "\n\t\t\t\t\t\t| currency name :" << left << setw(41) << " " + currency1code[0].currencyname << "|";
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

		cout << "\n\t\t\t\t\t\t| currency code :" << left << setw(41) << " " + currency1code[0].currencycode << "|";
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";

		cout << "\n\t\t\t\t\t\t|      Rate     :" << left << setw(41) << " " + to_string(currency1code[0].currencyrate) << "|";
		cout << "\n\t\t\t\t\t\t|---------------------------------------------------------|";


		float exstchangeamount = clsInputValidate::readDouble("\n\t\t\t\t\t\t enter the extchange amount : " , "\t\t\t\t\t\t Invalid number try again.");

		cout << "\n\t\t\t\t\t------------------------------------------------------------------------\n";
		float amountTousd = exstchangeamount / currency1code[0].currencyrate;
		cout <<"\t\t\t\t\t\t" << exstchangeamount <<  " " + currency1code[0].currencycode + " = " << amountTousd * currency2code[0].currencyrate << " " << currency2code[0].currencycode;
	}
};


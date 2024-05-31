#pragma once
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clscurrencylist.h"
#include "clsfindcurrency.h"
#include "clsUpdatecurrencyrate.h"
#include "clscurrnceycalculator.h"
class clsShowcurrencyExtchangeMenu : protected clsScreen
{
	enum menu { currencislist = 1, findcurrency = 2, update_rate = 3, currency_calculator = 4, main_menu = 5 };

	//done
	static void _currencislist() {
		//cout << "\t\t\t\t\t\tcurrencis list will be here soon" << endl;
		clscurrencylist::_currencylist();
	}

	//done
	static void _findcurrency() {
		//cout << "\t\t\t\t\t\tfind currency will be here soon" << endl;
		clsfindcurrency::findcurrecny();
	}

	//done
	static void _update_rate() {
		//cout << "\t\t\t\t\t\tupdate rate will be here soon" << endl;
		clsUpdatecurrencyrate::updaterate();
	}

	//done
	static void _currency_calculator() {
		//cout << "\t\t\t\t\t\tcurrency calculator will be here soon" << endl;
		clscurrnceycalculator::calculator();
	}


	static void _GobacktocurrencyMenu() {
		cout << "\n\t\t\t\t\t\t press any key to go back to currency menu";
		system("pause>0");
		ShowcurrencyMenu();
	}

	static void _ReaduserInput(menu list) {
		system("cls");
		switch (list)
		{
		case clsShowcurrencyExtchangeMenu::currencislist:
			_currencislist();
			_GobacktocurrencyMenu();
			break;
		case clsShowcurrencyExtchangeMenu::findcurrency:
			_findcurrency();
			_GobacktocurrencyMenu();

			break;
		case clsShowcurrencyExtchangeMenu::update_rate:
			_update_rate();
			_GobacktocurrencyMenu();

			break;
		case clsShowcurrencyExtchangeMenu::currency_calculator:
			_currency_calculator();
			_GobacktocurrencyMenu();
			break;
		case clsShowcurrencyExtchangeMenu::main_menu:
          ;
		}
	}
public :
	static void ShowcurrencyMenu() {
		system("cls");
		_DrowHeader("cuurrency menu scrren");
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|              currencis list    [1]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|               find currency    [2]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|          update currency rate  [3]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|            currency calculatoe [4]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                  main menu     [5]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		int list = clsInputValidate::readIntBetween(1, 5, "\t\t\t\t\t\t enter number from the list : ", "\t\t\t\t\t\t Invalid number! try again ");
		_ReaduserInput((menu)list);
	}
};


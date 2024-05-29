#pragma once
#include "clsInputValidate.h"

#include "clsClient.h"
#include "clsScreen.h"
#include "clsShowClientsList.h"
class clsTotaleBalance : protected clsScreen
{


public:

	static void TotaleBalance() {
		if (!checkaccess(section::Totale_balance)) {
			return;
		}
		
		_DrowHeader("Total Balance screen");

		clsShowClientsList::ShowClientsList();
		float TotalBalance = clsClient::TotalBalanc();
		
		cout << "\t\t\t\t\t\t|-----------------------------------------|\n";
		cout << "\t\t\t\t\t\t| Totale balance is :   " << left << setw(18) << TotalBalance << "|\n";
		cout << "\t\t\t\t\t\t|-----------------------------------------|\n";
	}
};


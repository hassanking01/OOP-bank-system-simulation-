#pragma once
#include "clsInputValidate.h"

#include "clsClient.h"
#include "clsScreen.h"
#include "clsDeposite.h"
#include "clsWithdraw.h"
#include "clsTotaleBalance.h"
#include "clsSendMoney.h"
class clsTransactionsMenu : protected clsScreen
{
	enum enSection
	{
		Deposite =1,
		Withdraw = 2,
		Totale_balance = 3,
		Send_Money = 4,
		main_menu = 5
	};
	static void _GoBackToTransactions() {
		
		cout << "\n\t\t\t\t\t\t press any key to go back ";
		system("pause>0");
		TransactionsMenu();
	}

	//done
	static void _Deposite(){
		clsDeposite::Deposite();
	
	}

	//done
	static void _Withdraw(){
		clsWithdraw::Withdraw();
	}

	//done
	static void _TotaleBalance(){
	
		clsTotaleBalance::TotaleBalance();
	}

	// done
	static void _SendMoney(){
	  
		clsSendMoney::SendMoney();

	}


	

	static void _ReadUserInput(enSection section) {
		system("cls");

		switch (section)
		{
		case clsTransactionsMenu::Deposite:
			_Deposite();
			_GoBackToTransactions();
			break;
		case clsTransactionsMenu::Withdraw:
			_Withdraw();
			_GoBackToTransactions();
			break;
		case clsTransactionsMenu::Totale_balance:
			_TotaleBalance();
			_GoBackToTransactions();
			break;
		case clsTransactionsMenu::Send_Money:
			_SendMoney();
			_GoBackToTransactions();
			break;
		case clsTransactionsMenu::main_menu:


		  ;

		}
	
	}
public:
	static void TransactionsMenu() {
		system("cls");
		_DrowHeader("Transa ctions Menu");
	
		int list;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                 Deposite       [1]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                  Withdraw      [2]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|             Totale balance     [3]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                 Send Money     [4]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                 Main Menu      [5]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		list = clsInputValidate::readIntBetween(1, 6, "\t\t\t\t\t\t enter number from the list : ", "Invalid number");
		_ReadUserInput((enSection)list);
	}
};


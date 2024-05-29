#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h"

#include "clsShowClientsList.h"
#include "clsAddClient.h"
#include "clsShowClientInfo.h"
#include "clsDeletclient.h"
#include "clsTransactionsMenu.h"
#include "clsUpdateclientinfo.h"
#include "clsManageUsers.h"
#include "clsLogout.h"
#include "glogal.h"
#include "clsLoginRegister.h"
using namespace std;
class clsShowMainMenu : public clsScreen 
{
	
private:
	enum enSection {
		clientsList = 2,
		addClient =1,
		clientInfo =3,
		deleteClient = 4,
		updateClientInfo = 5,
		transactionsMenu = 6,
		manageUsersMenu = 7,
		logout = 8,

	        
	
	};
	
	
	
	
	// done
	static void _ShowClientsList() {
		/*cout << "Show Client list will be here soon...";*/
		clsShowClientsList::ShowClientsList();

	}
	
	//done
	static void _AddClient() {
		/*cout << "Show Client Info will be here soon...";*/
		clsAddClient::Addclient();
	
	}

	//done
	static void _ShowClientInfo() {
		/*cout << "Show Client Info will be here soon...";*/
		clsShowClientInfo::ShowClientInfo();

	}

	//done
	static void _Deletclient() {
	 /*cout << "Delet client will be here soon...";*/
		clsDeletclient::Deleteclient();

	}
	
	//done
	static void _UpdateClientInfo() {
		/*cout << "Update Client Info will be here soon...";*/
		clsUpdateclientinfo::Updateclientinfo();

	}

	//done
	static void _TransactionsMenu() {
		/*cout << "Transactions Menu will be here soon...";*/
		clsTransactionsMenu::TransactionsMenu();

	}

	//done
	static void _ManageUsersMenu() {
		//cout << "Manage Users Menu will be here soon...";
		clsManageUsers::ManageUsers();

	}

	//done
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMenuScreen();
	}

	static void _Logout() {
		/*cout << "Logout will be here soon...";*/
		clsLogout::Logout();
	}

	static void _ReadUserInputList(enSection section) {
		system("cls");
		switch (section)
		{
		case clsShowMainMenu::clientsList:
			_ShowClientsList();
			_GoBackToMainMenue();
			break;
		case clsShowMainMenu::addClient:
			_AddClient();
			_GoBackToMainMenue();
			break;
		case clsShowMainMenu::clientInfo:
			_ShowClientInfo();
			_GoBackToMainMenue();
			break;
		case clsShowMainMenu::deleteClient:
			_Deletclient();
			_GoBackToMainMenue();
			break;
		case clsShowMainMenu::updateClientInfo:
			_UpdateClientInfo();
			_GoBackToMainMenue();
			break;
		case clsShowMainMenu::transactionsMenu:
			_TransactionsMenu();
			_GoBackToMainMenue();
			break;
		case clsShowMainMenu::manageUsersMenu:
			_ManageUsersMenu();
			_GoBackToMainMenue();
			break;
		case clsShowMainMenu::logout:
			_Logout();
			
			
		
		}
	}
public:
	static void ShowMenuScreen() {
		system("cls");
		_DrowHeader("Main Menu");


		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|              Add New client    [1]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|             View clients list  [2]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                Client info     [3]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                Delete client   [4]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|            Update client info  [5]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                Transactions    [6]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                 Manage users   [7]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                    Log out     [8]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
	int listNumber = clsInputValidate::readIntBetween(1, 8, "\n\n\n\t\t\t\t\t\t enter a number in the list : ", "\t\t\t\t\t\tInvalid number! pleas try again");
	   _ReadUserInputList((enSection)listNumber);
	}
};


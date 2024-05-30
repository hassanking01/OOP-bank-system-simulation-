#pragma once
#include "glogal.h"
#include <iostream>

using namespace std;





class clsScreen
{

	static void declined() {
		
	}
protected:
	static enum section {
		clientsList = 2,
		addClient = 1,
		clientInfo = 3,
		deleteClient = 4,
		updateClientInfo = 5,
		transactionsMenu = 6,
		manageUsersMenu = 7,
		userslist = 8,
		addnewuser = 9,
		userInfo = 10,
		Deleteuser = 11,
		updateuser = 12,
		loginregister = 13,
		Deposite = 14,
		Withdraw = 15,
		Totale_balance = 16,
		Send_Money = 17,
		
		
	};
	static bool checkaccess(section s) {
		if (!curentUser.have_access(int(s)))
		{
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|                                                                  |" << endl;
			cout << "\t\t\t\t\t\t|  " << left << setw(64) << "You Dont have Accsess to " + sectons[(int)s] + " contact your admin";
			cout << "|" << endl;
			cout << "\t\t\t\t\t\t|                                                                  |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------|" << endl;
			return false;
		}
		return true;
	}
	static void _DrowHeader(string titel, string subtitel = "") {
	

		cout << "\t\t\t\t\t-----------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t\t\t\t\t" << titel << endl;
		if (subtitel != "") {
			cout << "\t\t\t\t\t\t\t\t\t" << subtitel << endl;

		}
		clsDate date;
		cout << "\t\t\t\t\t-----------------------------------------------------------------------------\n\n\n";
		cout << "\t\t\t\t\t\t\t\tuser : " << curentUser.username << endl;
		cout << "\t\t\t\t\t\t\t\tdate : " << date.DateToString() << endl;
		cout << endl << endl;
	

	}
};


#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "glogal.h"
#include "clsDate.h"
#include <fstream>
#include <vector>
#include <ctime>
#include "clsLoginRegister.h"
#include "clsScreen.h"
class clsLoginRegisterScreen : protected clsScreen
{


	static void _printrecord(clsLoginRegister user) {
		cout << left << setw(40) << "|         " + user.date;
		cout << left << setw(27) << "|   "  + user.username;
		cout << left << setw(27) << "|    " + user.password;
		cout << left << setw(27) << "|         " + user.permisstion << "|";
		
	}

public:
	static void showLoginrefister() {
		if (!checkaccess(section::loginregister)) {
			return;
		}
		
		vector <clsLoginRegister> vtLogs = clsLoginRegister::GetLoginRegist();
		string subtitel = "(" + to_string(vtLogs.size()) + ") Records .";
		_DrowHeader("Login Register Screen", subtitel );
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------------------------------------------------|";
		cout << "\n\t\t\t\t\t\t";
		cout << left << setw(40) << "|                 date";
		cout << left << setw(27) << "|         username";
		cout << left << setw(27) << "|         password";
		cout << left << setw(27) << "|     permisstion" <<"|";
		cout << "\n\t\t\t\t\t\t|------------------------------------------------------------------------------------------------------------------------|";
		for (clsLoginRegister& user : vtLogs) {
			cout << "\n\t\t\t\t\t\t";
			_printrecord(user);
			
			cout << "\n\t\t\t\t\t\t|------------------------------------------------------------------------------------------------------------------------|";
		}
	}
};


#pragma once
#include "clsInputValidate.h"

#include "clsClient.h"
#include "clsUser.h"
#include "clsScreen.h"
class clsUserList : protected clsScreen
{
	static void _PrintUser(clsUser user) {
		cout << left << setw(27) << "| "+ user.username;
		cout << left << setw(27) << "|  " + user.password;
		cout << left << setw(27) << "|     "+to_string(user.permisstion);
		cout << left << setw(17) << "|   "+ user.firstname;
		cout << left << setw(17) << "|   "+user.lastname;
		cout << left << setw(27) << "|     "+user.phonenumber;
		cout << left << setw(35) << "|  "+user.Email << endl;
	}

public:

	static void UserList() {
		vector <clsUser> vtusers = clsUser::Getuserdata();
		string users = "(" + to_string(vtusers.size()) + ") users";
		_DrowHeader("User List Screen" , users);

		cout << "|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";

		cout << left << setw(27) << "|  user's username   ";
		cout << left << setw(27) << "|  password   ";
		cout << left << setw(27) << "|  user's Permissions |" ;
		cout << left << setw(17) << "|   FirstName   ";
		cout << left << setw(17) << "|   LastName   ";
		cout << left << setw(27) << "|     Phone Number   ";
		cout << left << setw(35) << "|              Email   ";
		cout << "|" << endl;
		cout << "|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
		for (clsUser& thisuser : vtusers)
		{
			_PrintUser(thisuser);
			cout << "|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
		}

	}



};


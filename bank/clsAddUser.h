#pragma once
#include "clsInputValidate.h"
#include "clsClient.h"
#include "clsUser.h"
#include "clsScreen.h"
class clsAddUser : protected clsScreen
{
	static clsUser readClient(clsUser& user) {
		cout << endl;
		user.firstname = clsInputValidate::readString("\n\t\t\t\t\t\tenter firstName          : ");
		cout << endl;
		user.lastname = clsInputValidate::readString("\t\t\t\t\t\tenter lastName           : ");
		cout << endl;
		user.phonenumber = clsInputValidate::readString("\t\t\t\t\t\tenter phoneNumber        : ");
		cout << endl;
		user.Email = clsInputValidate::readString("\t\t\t\t\t\tenter email              : ");
		cout << endl;
		user.password = clsInputValidate::readString("\t\t\t\t\t\tenter password            : ");
		cout << endl;
		char section;
		char fullaccess = clsInputValidate::readChar("\t\t\t\t\t\tdoes the user have full access of the system Y/N : ");
		if (toupper(fullaccess) == 'Y') {
			user.permisstion = -1;
		}
		else
		{
			string sections[7] = {
		"View clients list",
		"Add client",
		"Client info",
		"Delete client",
		"Update client info",
		"Transactions",
		"Manage users"
			};
			for (int i = 0; i < 7; i++) {
				cout << "give User access to " << sections[i] << " : ";
				cin >> section;
				if (toupper(section) == 'Y') {
					user.permisstion |= (1 << i);
				}
			}
		}
		return user;
	}

public:
	static void AddUser() {
		_DrowHeader("Add user screen");

		string username = clsInputValidate::readString("\t\t\t\t\t\t enter the user name : ");
		while (clsUser::isusetrexist(username)) {
		
			cout << "\t\t\t\t\t\tthe username : " << username << " is alredy exist enter another one\n";
			username = clsInputValidate::readString("\t\t\t\t\t\t enter the user name : ");

		}
		clsUser newUser = clsUser::GetAdduser(username);
		readClient(newUser);
		clsUser::ensave result =  newUser.save();
		switch (result)
		{
		case clsUser::svSuccessfully:
			cout << "\t\t\t\t\t\tdone Successfully.";
			break;
		case clsUser::svfieldEmpty:
			cout << "\t\t\t\t\t\tError: somthing wrong the object was Empty";

			break;
		case clsUser::svfieldAlredyExsit:
			cout << "\t\t\t\t\t\tError: somthing wrong the user is alredy exist.";

			break;
		
		}
	}
};


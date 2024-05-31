#pragma once
#include "clsInputValidate.h"
#include "clsClient.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "clsUtil.h"
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
		user.password = clsUtil::EncryptText(user.password, 10);
		cout << endl;
		char section;
		char fullaccess = clsInputValidate::readChar("\t\t\t\t\t\tdoes the user have full access of the system Y/N : ");
		if (toupper(fullaccess) == 'Y') {
			user.permisstion = -1;
		}
		else
		{
			string sections[8] = {
				"",
		"View clients list",
		"Add client",
		"Client info",
		"Delete client",
		"Update client info",
		"Manage users",
		"Transactions",
			};
			string transactions[19] = {
		"", "", "","", "", "","", "", "", "", "","", "", "", "", "Deposite", "Withdraw", "Totale_balance" , "Send_Money"
			};
			string managusers[17] = {
		 "", "",  "", "", "", "", "", "", "",  "userslist", "addnewuser", "userInfo",
		"Deleteuser", "updateuser", "loginregister"
			};
			for (int i = 0; i < 7; i++) {
				section = 'n';
				cout << "give User access to " << sections[i+1] << " : ";
				cin >> section;
				if (toupper(section) == 'Y') {
					user.permisstion |= (1 << i);
					

				}
				if (i == 6 && toupper(section) == 'Y') {
					for (int j = 13; j < 17; j++) {
						cout << "give User access to " << transactions[j+2] << " : ";
						cin >> section;
						if (toupper(section) == 'Y') {
							user.permisstion |= (1 << j);


						}
					}
				}
				if (i == 5 && toupper(section) == 'Y') {
					for (int j = 7; j < 13; j++) {
						cout << "give User access to " << managusers[j+2] << " : ";
						cin >> section;
						if (toupper(section) == 'Y') {
							user.permisstion |= (1 << j);


						}
					}
				}
				
			}
		}
		return user;
	}

public:
	static void AddUser() {
		if (!checkaccess(section::addnewuser)) {
			return;
		}
		
		_DrowHeader("Add user screen");

		string username = clsInputValidate::readString("\t\t\t\t\t\t enter the username : ");
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


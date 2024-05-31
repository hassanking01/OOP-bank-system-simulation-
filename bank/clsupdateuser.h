#pragma once
#include "clsInputValidate.h"

#include "clsClient.h"
#include "clsScreen.h"
#include "clsUser.h"
class clsupdateuser : protected clsScreen
{
	enum enupdate {firstname=1,lastname =2 , email = 3, phonenumber = 4 , premisstion = 5 , password = 6  };

	static void _readinput(clsUser & user) {
		
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|      username        : " << left << setw(50) << user.username << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[1]FirstName          : " << left << setw(50) << user.firstname << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[2]Lastname           : " << left << setw(50) << user.lastname << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[3]Email              : " << left << setw(50) << user.Email << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[4]Phone Number       : " << left << setw(50) << user.phonenumber << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[5]permisstion        : " << left << setw(50) << user.permisstion << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[6]password           : " << left << setw(50) << user.password << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		
		
		
		char areusure = clsInputValidate::readChar("\t\t\t\t\t\t are you sure you want to update : ");
		if (toupper(areusure) != 'Y')
			return;
		char fullaccess;

		enupdate section = (enupdate)clsInputValidate::readIntBetween(1, 6, "\t\t\t\t\t\tenter number from the list to select what you want to update : ", "\t\t\t\t\t\tinvalid number! try again");
		char isyas;
		switch (section)
		{
		case clsupdateuser::firstname:
			user.firstname = clsInputValidate::readString("\t\t\t\t\t\t enter the updated firstname : ");
			break;
		case clsupdateuser::lastname:
			user.lastname = clsInputValidate::readString("\t\t\t\t\t\t enter the updated lastname : ");

			break;
		case clsupdateuser::email:
			user.Email= clsInputValidate::readString("\t\t\t\t\t\t enter the updated email : ");

			break;
		case clsupdateuser::phonenumber:
			user.phonenumber = clsInputValidate::readString("\t\t\t\t\t\t enter the updated phone number : ");

			break;
		case clsupdateuser::premisstion:
			if (user.username == curentUser.username && curentUser.permisstion != -1) {
				cout << "\t\t\t\t\t\t|------------------------------------------------------------------|" << endl;
				cout << "\t\t\t\t\t\t|                                                                  |" << endl;
				cout << "\t\t\t\t\t\t|  " << left << setw(64) << "You Dont have Accsess to change permisstions  contact your admin";
				cout << "|" << endl;
				cout << "\t\t\t\t\t\t|                                                                  |" << endl;
				cout << "\t\t\t\t\t\t|------------------------------------------------------------------|" << endl;
				return;
			}
			fullaccess = clsInputValidate::readChar("\t\t\t\t\t\tdoes the user have full access of the system Y/N : ");
			if (toupper(fullaccess) == 'Y') {
				user.permisstion = -1;
			}
			else
			{
				string sections[8] = {
				"",
		
		"Add client",
		"View clients list",
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
					isyas = 'n';
					cout << "give User access to " << sections[i + 1] << " : ";
					cin >> isyas;
					if (toupper(isyas) == 'Y') {
						user.permisstion |= (1 << i);


					}
					if (i == 6 && toupper(isyas) == 'Y') {
						for (int j = 13; j < 17; j++) {
							cout << "give User access to " << transactions[j + 2] << " : ";
							cin >> isyas;
							if (toupper(isyas) == 'Y') {
								user.permisstion |= (1 << j);


							}
						}
					}
					if (i == 5 && toupper(isyas) == 'Y') {
						for (int j = 7; j < 13; j++) {
							cout << "give User access to " << managusers[j + 2] << " : ";
							cin >> isyas;
							if (toupper(isyas) == 'Y') {
								user.permisstion |= (1 << j);


							}
						}
					}

				}
			}
			break;
		case clsupdateuser::password:
			user.password = clsInputValidate::readString("\t\t\t\t\t\t enter the updated password : ");
			user.password = clsUtil::EncryptText(user.password, 10);
			break;
		default:
			break;
		}
		clsUser::ensave result = user.save();
		switch (result)
		{
		case clsUser::svSuccessfully:
			cout << "\t\t\t\t\t\t Error: field the object is empty";
			break;
		case clsUser::svfieldEmpty:
			cout << "\t\t\t\t\t\t done succsessfully.";

			break;
		case clsUser::svfieldAlredyExsit:
			break;
		default:
			break;
		}
		char anotherone = clsInputValidate::readChar("\t\t\t\t\t\tupdate somthing als : ");
		if (toupper(anotherone) == 'Y') {
			_readinput(user);
		}
	}
public:
	static void Updateuserinfo() {
		if (!checkaccess(section::updateuser)) {
			return;
		}
		
		_DrowHeader("Update user info screen" );

		string AccountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter username account you want to update : ");
		while (!clsUser::isusetrexist(AccountNumber))
		{
			cout << "\t\t\t\t\t\ username doesnt Exict try again \n";
			 AccountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter username : ");

		}
		clsUser user = clsUser::find(AccountNumber);
		cout << endl;

		_readinput( user);
	}
};


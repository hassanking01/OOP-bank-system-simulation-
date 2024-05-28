#pragma once
#include "clsInputValidate.h"
#include "clsClient.h"
#include "clsUser.h"
#include "clsScreen.h"
class clsDeleteuser : protected clsScreen
{


	
public:
	static void Deleteuser() {
		_DrowHeader("delet user screen");
		string username = clsInputValidate::readString("\t\t\t\t\t\t enter the user name you eant to delete for : ");
		cout << endl;
		vector <clsUser> vtusers = clsUser::Getuserdata();

		while (!clsUser::isusetrexist(username))
		{
			cout << "the username not found in the databes try again .";
			cout << endl;
			username = clsInputValidate::readString("\t\t\t\t\t\t enter the user name you eant to delete for : ");
		}
		clsUser user = clsUser::find(username);
		char sure = clsInputValidate::readChar("\t\t\t\t\t\t are you sure you want to delete Y/N : ");
		if (toupper(sure) == 'Y')
			user._delete();
	}
};


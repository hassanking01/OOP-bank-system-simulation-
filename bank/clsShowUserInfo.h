#pragma once
#include "clsInputValidate.h"

#include "clsUser.h"
#include "clsScreen.h"
class clsShowUserInfo : protected clsScreen
{


public:
	static void ShowUserInfo() {
		if (!checkaccess(section::userInfo)) {
			return;
		}
		
		_DrowHeader("user info screen");
		string username = clsInputValidate::readString("\t\t\t\t\t\t enter the user name you eant to search for : ");
		cout << endl;
		vector <clsUser> vtusers = clsUser::Getuserdata();
		
		while (!clsUser::isusetrexist(username))
		{
			cout << "the username not found in the databes try again .";
			cout << endl;
			username = clsInputValidate::readString("\t\t\t\t\t\t enter the user name you eant to search for : ");
		}
		clsUser user = clsUser::find(username);
		user.printInfo();

		
		
		
	}
};


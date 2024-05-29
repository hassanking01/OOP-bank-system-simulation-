#pragma once
#include "clsInputValidate.h"
#include "clsLoginRegisterScreen.h"
#include "clsClient.h"
#include "clsScreen.h"
#include "clsUserList.h"
#include "clsAddUser.h"
#include "clsShowUserInfo.h"
#include "clsDeleteuser.h"
#include "clsupdateuser.h";
class clsManageUsers : protected clsScreen
{
	enum enSections {
		userslist = 1, addnewuser =2 ,userInfo = 3 , Deleteuser=4 , updateuser= 5 , loginregister = 6 , mainmenu = 7
	};
	
	//done
	static void _userlist(){
		//cout << "user list will here soon";
		clsUserList::UserList();
	}
	
	//done
	static void _AddUser() {
		//cout << "Add User will here soon";
		clsAddUser::AddUser();
	}
	
	//done
	static void _UserInfo() {
		//cout << "User Info will here soon";
		clsShowUserInfo::ShowUserInfo();
	}
	
	//done
	static void _Deleteuser() {
		//cout << "Delete user will here soon";
		clsDeleteuser::Deleteuser();
	}
	
	//done
	static void _Updateuser() {
		//cout << "Update user will here soon";
		clsupdateuser::Updateuserinfo();
	}


	static void _LoginRegister() {
		//cout << "\t\t\t\t\t\t Login Register will be here soon.";
		clsLoginRegisterScreen::showLoginrefister();
	}
	
	static void _GoBackToManageUserMenu() {
		cout << "\t\t\t\t\t\t press any key to go back to Manage user.";
		system("pause>0");
		ManageUsers();
	}
	
	static void _ReaduserInput() {
		
		enSections section = (enSections)clsInputValidate::readIntBetween(1, 7, "\t\t\t\t\t\t Enter a number from the list : ", "Invalid Number! pleas try again");
		system("cls");
		switch (section)
		{
		case clsManageUsers::userslist:
			_userlist();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::addnewuser:
			_AddUser();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::userInfo:
			_UserInfo();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::Deleteuser:
			_Deleteuser();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::updateuser:
			_Updateuser();
			_GoBackToManageUserMenu();
			break;
		
		case clsManageUsers::loginregister:
			_LoginRegister();
			_GoBackToManageUserMenu();
			break;
		case clsManageUsers::mainmenu:
			;
		}
		
	
	}
public:
	static void ManageUsers() {
		system("cls");
		_DrowHeader("Mange user menu");

		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|              View Users list   [1]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                Add New User    [2]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                  User info     [3]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                 Delete User    [4]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                 Update User    [5]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                Login Register  [6]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|                  Main Menu     [7]             |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
		_ReaduserInput();
	}
};


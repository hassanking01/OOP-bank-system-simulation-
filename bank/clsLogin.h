#pragma once
#include "clsInputValidate.h"
#include "clsLoginRegister.h"
#include "clsClient.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "glogal.h"
#include<windows.h> 
#include "clsShowMainMenu.h"
class clsLogin : protected clsScreen
{

protected:

public:
	static void Login() {
		_DrowHeader("logn screen");
		string username, password;

		
			cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|      usename      : ";

			cin >> username;
			system("cls");
			_DrowHeader("logn screen");
			cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|      usename      : " << left << setw(23) << username << "    |" << endl;;
			cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|      password     : ";
			cin >> password;
			cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;

			clsUser login = clsUser::find(username, password);
			int counter = 0;
			while (login.isEmpty() && logfield)
			{
				counter++;
				if (counter >= 3)
				{
					logfield = false;
				}
				
				system("cls");
				_DrowHeader("logn screen");
				cout << "\t\t\t\t\t\t username/passeord are incorect! you field ("<<counter <<") times if you field 3 times the system will crash pleas try again\n";
				cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
				cout << "\t\t\t\t\t\t|      usename      : ";

				cin >> username;
				system("cls");
				_DrowHeader("logn screen");
				cout << "\t\t\t\t\t\t username/passeord are incorect! pleas try again\n";

				cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
				cout << "\t\t\t\t\t\t|      usename      : " << left << setw(23) << username << "    |" << endl;;
				cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
				cout << "\t\t\t\t\t\t|      password     : ";
				cin >> password;
				cout << "\t\t\t\t\t\t|------------------------------------------------|" << endl;
				login = clsUser::find(username, password);
			}
		
			if (!logfield)
				cout << "you field to log in three times system out";
			else
			{
				
				counter = 0;
				curentUser = login;
				Sleep(200);
				curentUser.saveLoginRegist();
				clsShowMainMenu::ShowMenuScreen();
			
				
			}
	}
	
	
};


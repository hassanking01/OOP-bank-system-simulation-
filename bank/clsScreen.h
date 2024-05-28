#pragma once
#include <iostream>
#include "glogal.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{
protected:
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


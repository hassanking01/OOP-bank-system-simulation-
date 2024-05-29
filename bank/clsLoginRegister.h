#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "glogal.h"
#include "clsDate.h"
#include <fstream>
#include <vector>
#include <ctime>
class clsLoginRegister
{
	string _date;
	string _username;
	string _password;
	string _permisstion;
	
	static clsLoginRegister _converlinetorecord(string line , string delim = "#//#") {
		vector <string> vtrecord = clsString::Split(line , delim);
		return clsLoginRegister(vtrecord[0], vtrecord[1], vtrecord[2], vtrecord[3]);

	}
	static vector <clsLoginRegister> _loderecodsfromfile() {
		vector <clsLoginRegister> vtlogrecord;
		fstream logfile;
		logfile.open("LoginRegister.txt", ios::in);
		if (logfile.is_open()) {
			clsLoginRegister record("" , "" , "" , "");
			string line;
			while (getline(logfile , line))
			{
				record = _converlinetorecord(line);
				vtlogrecord.push_back(record);
			}
			logfile.close();
		}
		return vtlogrecord;
	}


public:

	clsLoginRegister(string date, string username, string password, string permisstion) {
		_date = date;
		_username = username;
		_password = password;
		_permisstion = permisstion;
	}

	static vector <clsLoginRegister> GetLoginRegist() {
		return _loderecodsfromfile();
	}

	string getDate() {
		return _date;
	}
	string getusername() {
		return _username;
	}
	string getpassword() {
		return _password;
	}
	string getpermisstion() {
		return _permisstion;
	}

	__declspec(property(get = getDate))string date;
	__declspec(property(get = getusername))string username;
	__declspec(property(get = getpassword))string password;
	__declspec(property(get = getpermisstion))string permisstion;

};


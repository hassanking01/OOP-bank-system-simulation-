#pragma once
#include <iostream>
#include "clsDate.h"
#include <string>
class clsInputValidate
{

public:
	static bool isNumberBetwee(int number, int from, int to) {
		return number >= from && number <= to;
	}
	static bool isDateBetween(clsDate date, clsDate date1, clsDate date2) {
		return clsDate::IsDate1AfterDate2(date, date1) && clsDate::IsDate1BeforeDate2(date, date2);

	}
	static bool isNumber(string &num) {
		int dotCounter = 0;
		for (int i = 0; i < num.length(); ++i) {
			
			if (!isdigit(num[i])) {
				
				if (num[i] == '.') {
					dotCounter++;
					if (dotCounter > 1) {
						return false;
					}
				}
				
				else {
					return false;
				}
			}
		}
		
		return true;
	}
	static int ReadIntNumber(string masseg ,string error) {
		string num;
		cout << masseg ;
		cin >> num;
		while (isNumber(num) == false)
		{
			cout << error << endl;
			cout << masseg;
			cin >> num;
		}
		int intnum = stoi(num);
		return intnum;
	}
	static int readIntBetween( int from, int to, string masseg, string error) {
		int num = ReadIntNumber(masseg, error);
		while (num < from || num > to)
		{
			cout << error << endl;
			cout << masseg;
			cin >> num;

		}
		return num;
	}
	static double readDouble(string masseg, string error) {
		string num; 
		cout << masseg;
		cin >> num;
		while (!isNumber(num))
		{ 
			cout << error;
			cout << masseg;
			cin >> num;
		}
		double realnum = stod(num);
		return realnum;
	}
	
	static double readDoubleBetweem(double from, double to, string masseg, string error) {
		double num = readDouble(masseg, error);
		while (num < from || num > to)
		{
			cout << error << endl;

		}
		return num;
	}
	static bool isValidDate(clsDate date) {
		return date.IsValid();
	}
	static string readString(string masseg) {
		string str;
		cout << masseg;
		getline(cin >> ws, str);
		return str;
	}
	static char readChar(string masseg) {
		char str;
		cout << masseg;
		cin>> str;
		return str;
	}
};


#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsClient.h"
#include "clsScreen.h"
class clsShowClientsList : protected clsScreen
{
	static void _Printclientinto(clsClient temp) {

		cout << left << setw(27) << "|  " + temp.AccountNumber;
		cout << left << setw(17) << "|  " + temp.firstname;
		cout << left << setw(17) << "|  " + temp.lastname;
		cout << left << setw(27) << "|  " + temp.phonenumber;
		cout << left << setw(35) << "|  " + temp.Email;
		cout << left << setw(13) << "|    " + temp.Pincode;
		cout << left << setw(33) << "|     " + to_string(temp.Account_Balance) << "|" << endl;
	}
public:
	static void ShowClientsList() {
		vector <clsClient> vtClients = clsClient::GetClientList();
		string titel = "Clients list";
		string subTitel = "(" + to_string(vtClients.size())+ ") Clients";
		_DrowHeader(titel, subTitel);
		cout << "|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
		cout << left << setw(27) << "|  Account Number   ";
		cout << left << setw(17) << "|   FirstName   ";
		cout << left << setw(17) << "|   LastName   ";
		cout << left << setw(27) << "|     Phone Number   ";
		cout << left << setw(35) << "|              Email   ";
		cout << left << setw(13) << "|   Pincode  ";
		cout << left << setw(33) << "|        Account Balance         |" << endl;
		cout << "|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
		for (clsClient& thisclinet : vtClients)
		{
			_Printclientinto(thisclinet);
			cout << "|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n";
		}
	}
};


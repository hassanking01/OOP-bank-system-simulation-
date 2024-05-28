#pragma once
#include "clsInputValidate.h"

#include "clsClient.h"
#include "clsScreen.h"
class clsWithdraw : protected clsScreen
{
	

public:
	static void Withdraw() {
		_DrowHeader("Withdraw screen");

		vector <clsClient> vtClients = clsClient::GetClientList();
		cout << "\t\t\t\t\t\t" << "|-----------------------------------------------------|\n";

		cout << "\t\t\t\t\t\t" << left << setw(27) << "|  account number   ";
		cout << left << setw(27) << "|  fullname   ";
		cout << "|" << endl;
		cout << "\t\t\t\t\t\t" << "|-----------------------------------------------------|\n";


		for (clsClient& client : vtClients) {
			cout << "\t\t\t\t\t\t" << left << setw(27) << "|  " + client.AccountNumber;
			cout << left << setw(27) << "|  " + client.getFullName();
			cout << "|" << endl;
			cout << "\t\t\t\t\t\t" << "|-----------------------------------------------------|\n";
		}
		string AccountNumber = clsInputValidate::readString("\t\t\t\t\t\t Enter the Account Number you Want To Deposite To : ");
		clsClient client = clsClient::find(AccountNumber);
		while (!client.isAccExist(AccountNumber))
		{
			cout << "\t\t\t\t\t\t Account Not Found! Pleas Try Again \n";
			string AccountNumber = clsInputValidate::readString("\t\t\t\t\t\t Enter the Account Number you Want To withraw To : ");
		}
		client = clsClient::find(AccountNumber);
		client.printInfo();
		float Amount = clsInputValidate::readDouble("\t\t\t\t\t\t enter the withraw amount : \n\t\t\t\t\t\t", "Invalid Number! Pleas try again. ");
		client.withraw(Amount);
		clsClient::enSave result;
		result = client.Save();
		switch (result)
		{
		case clsClient::svFieldEmptyObject:
			cout << "\t\t\t\t\t\t Error Filed To withraw The Acout Is Empty Object .";
			break;
		case clsClient::svSavesuccessfully:
			cout << "\t\t\t\t\t\t Done Succsessfully. New Account Balance Now is " << client.Account_Balance;
			break;
		default:
			cout << "\t\t\t\t\t\t Error somthing wrong.";
			break;
		}
	}
};


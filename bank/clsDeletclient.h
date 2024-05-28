#pragma once
#include "clsInputValidate.h"
#include "clsClient.h"
#include "clsScreen.h"
#include "clsUser.h"
class clsDeletclient : protected clsScreen
{

public:
	static void Deleteclient() {

		_DrowHeader("Delete client");

		string AccountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter client account number you want to delelt : ");
		while (!clsClient::isAccExist(AccountNumber))
		{
			cout << "\t\t\t\t\t\tAccout doesnt Exict try again \n";
			string AccountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter Acount number");

		}
		clsClient client = clsClient::find(AccountNumber);
		cout << endl;
		client.printInfo();
		char sur = clsInputValidate::readChar("\t\t\t\t\t\t are you sure you want to delete this client Y/N : ");
		if(toupper(sur) == 'Y'){ // if(sur == 'y' || sur == 'Y')
		if (client.isdelet(AccountNumber)) {
			cout << "\t\t\t\t\t\tdont seccesfully .";
		}
		}
	}
};


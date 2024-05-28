#pragma once
#include "clsInputValidate.h"

#include "clsClient.h"
#include "clsScreen.h"
class clsShowClientInfo : protected clsScreen
{

public:
	static void ShowClientInfo() {
		_DrowHeader("Search Client Info");
		vector <clsClient> vtClients = clsClient::GetClientList();
		string clientAcountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter the Client Acount Number : ");
		clsClient client = clsClient::find(clientAcountNumber);
		while (!client.isAccExist(clientAcountNumber))
		{
			cout << "\t\t\t\t\t\t Account not found! try again\n";
			clientAcountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter the Client Acount Number : ");
		}
		client = clsClient::find(clientAcountNumber);
		client.printInfo();
	}
};


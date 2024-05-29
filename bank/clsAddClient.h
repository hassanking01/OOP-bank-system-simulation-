#pragma once
#include "clsInputValidate.h"
#include "clsClient.h"
#include "clsScreen.h"
class clsAddClient : protected clsScreen
{
	static clsClient readClient(clsClient& client) {
		cout << endl;
		client.firstname =       clsInputValidate::readString("\n\t\t\t\t\t\tenter firstName          : ");
		cout << endl;
		client.lastname =        clsInputValidate::readString("\t\t\t\t\t\tenter lastName           : ");
		cout << endl;
		client.phonenumber =     clsInputValidate::readString("\t\t\t\t\t\tenter phoneNumber        : ");
		cout << endl;
		client.Email =           clsInputValidate::readString("\t\t\t\t\t\tenter email              : ");
		cout << endl;
		client.Pincode =         clsInputValidate::readString("\t\t\t\t\t\tenter pincode            : ");
		cout << endl;
		client.Account_Balance = clsInputValidate::readDouble("\t\t\t\t\t\tenter the client Balance : ", "\t\t\t\t\t\tInvalid Number! Try again ");
		return client;
	}
public:
	static void Addclient() {
		
		if (!checkaccess(section::addClient)) {
			return;
		}
		_DrowHeader("Add client");
		string AccountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter Acount number");
		while (clsClient::isAccExist(AccountNumber))
		{
			cout << "\n\t\t\t\t\t\tAccout Alredy Exict try again \n";
			 AccountNumber = clsInputValidate::readString("\n\t\t\t\t\t\tenter Acount number");

		}
		clsClient client = clsClient::getAddNewClientObject(AccountNumber);
		readClient(client);
		clsClient::enSave result = client.Save();
		switch (result)
		{
		case clsClient::svFieldEmptyObject:
			cout << "\t\t\t\t\t\tError : object is empty. Please provide a valid input.";
			break;
		case clsClient::svSavesuccessfully:
			cout << "\t\t\t\t\t\tClient Added Successfully.";
			break;
		case clsClient::svfieldAccountAlredyExist:
			cout << "\t\t\t\t\t\tError : object is already Exists.";
			break;
		}
	}
};


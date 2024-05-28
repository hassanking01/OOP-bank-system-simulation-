#pragma once
#include "clsInputValidate.h"

#include "clsClient.h"
#include "clsScreen.h"
class clsSendMoney : protected clsScreen
{


public:
	static void SendMoney() {

		_DrowHeader("send Money scren");

		vector <clsClient> vtClients = clsClient::GetClientList();
		string senderAcountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter the sender Acount Number : ");
		clsClient sender = clsClient::find(senderAcountNumber);
		while (!sender.isAccExist(senderAcountNumber))
		{
			cout << "\t\t\t\t\t\t Account not found! try again\n";
			senderAcountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter the sender Acount Number : ");
		}
		sender = clsClient::find(senderAcountNumber);
		string resiverAccountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter reciver Account Number : ");
		string resiverFullName = clsInputValidate::readString("\t\t\t\t\t\tEnter reciver FullName : ");
		clsClient reciver = clsClient::findTosendOrRequat(resiverAccountNumber, resiverFullName);
		while (!reciver.isAccExist(resiverAccountNumber))
		{
			cout << "\t\t\t\t\t\t Account not found! try again\n";
			resiverAccountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter reciver Account Number : ");
			resiverFullName = clsInputValidate::readString("\n\t\t\t\t\t\tEnter reciver FullName : ");
		}
		reciver = clsClient::findTosendOrRequat(resiverAccountNumber, resiverFullName);
		float Amount = clsInputValidate::readDouble("\n\t\t\t\t\t\tenter the Amount to send", "invalid Number! try again");
		char sur = clsInputValidate::readChar("\t\t\t\t\t\tare you sure you want to do this transaction Y/N : ");
		if(toupper(sur) == 'Y'){
			sender.sendMony(reciver, Amount);
			sender.Save();
			reciver.Save();
			cout << "\t\t\t\t\t\tdone successfully. you Balance now is " << sender.Account_Balance << endl;
		}
	}
};


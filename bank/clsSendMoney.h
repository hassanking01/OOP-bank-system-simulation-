#pragma once
#include "clsInputValidate.h"

#include "clsClient.h"
#include "clsScreen.h"
class clsSendMoney : protected clsScreen
{


public:
	static void SendMoney() {

		if (!checkaccess(section::Send_Money)) {
			return;
		}
		
		_DrowHeader("send Money scren");

		vector <clsClient> vtClients = clsClient::GetClientList();
		string senderAcountNumber = clsInputValidate::readString("\n\t\t\t\t\t\tenter the sender Acount Number : ");
		clsClient sender = clsClient::find(senderAcountNumber);
		while (!sender.isAccExist(senderAcountNumber))
		{
			cout << "\t\t\t\t\t\t Account not found! try again\n";
			senderAcountNumber = clsInputValidate::readString("\t\t\t\t\t\tenter the sender Acount Number : ");
		}
		sender = clsClient::find(senderAcountNumber);
		string resiverAccountNumber = clsInputValidate::readString("\n\t\t\t\t\t\tenter reciver Account Number : ");
		clsClient reciver = clsClient::find(resiverAccountNumber);
		while (!reciver.isAccExist(resiverAccountNumber))
		{
			cout << "\t\t\t\t\t\t Account not found! try again\n";
			resiverAccountNumber = clsInputValidate::readString("\n\t\t\t\t\t\tenter reciver Account Number : ");
		}
		reciver = clsClient::find(resiverAccountNumber);
		float Amount = clsInputValidate::readDouble("\n\t\t\t\t\t\tenter the Amount to send", "invalid Number! try again");
		char sur = clsInputValidate::readChar("\n\t\t\t\t\t\tare you sure you want to do this transaction Y/N : ");
		if(toupper(sur) == 'Y'){
			curentUser.transfir(sender, reciver, Amount);
			sender.Save();
			reciver.Save();
			cout << "\t\t\t\t\t\tdone successfully. you Balance now is " << sender.Account_Balance << endl;
		}
	}
};


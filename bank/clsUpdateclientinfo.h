#pragma once
#include "clsInputValidate.h"

#include "clsClient.h"
#include "clsScreen.h"
class clsUpdateclientinfo : protected clsScreen
{
	enum enUpdate {
		firsname = 1,
		lastname = 2,
		email = 3,
		phonenumber = 4,
		pinecode = 5,
		Acc_Balance =6
	};

	static void _Update(clsClient & client) {
		enUpdate update = (enUpdate)clsInputValidate::readIntBetween(1, 6, "\t\t\t\t\t\tenter a number from the list : ", "\t\t\t\t\t\tInvalid number! try again.");
		switch (update)
		{
		case clsUpdateclientinfo::firsname:
			client.firstname = clsInputValidate::readString("\t\t\t\t\t\tenter the updated firstname : ");
			break;
		case clsUpdateclientinfo::lastname:
			client.lastname = clsInputValidate::readString("\t\t\t\t\t\tenter the updated lastName : ");
			break;
		case clsUpdateclientinfo::email:
			client.Email = clsInputValidate::readString("\t\t\t\t\t\tenter the updated Email : ");
			break;
		case clsUpdateclientinfo::phonenumber:
			client.phonenumber = clsInputValidate::readString("\t\t\t\t\t\tenter the updated PhoneNumber : ");
			break;
		case clsUpdateclientinfo::pinecode:
			client.Pincode = clsInputValidate::readString("\t\t\t\t\t\tenter the updated Pinecode : ");
			break;
		case clsUpdateclientinfo::Acc_Balance:
			client.Account_Balance = clsInputValidate::readDouble("\t\t\t\t\t\t enter the updated Balance : ", "Invalid Number! try again");
			break;
		default:
			break;
		}
	}

public:
	static void Updateclientinfo() {
		
			if (!checkaccess(section::updateClientInfo)) {
				return;
			}
		_DrowHeader("Update client info screen" );

		string AccountNumber = clsInputValidate::readString("enter the Acount Number You Want to Change : ");
		while (!clsClient::isAccExist(AccountNumber))
		{
			cout << "Accout doesnt Exict try again \n";
			string AccountNumber = clsInputValidate::readString("enter Acount number");

		}
		clsClient client = clsClient::find(AccountNumber);

		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[]Account number      : " << left << setw(50) << client.AccountNumber << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[1]FirstName          : " << left << setw(50) << client.firstname << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[2]Lastname           : " << left << setw(50) << client.lastname << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[3]Email              : " << left << setw(50) << client.Email << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[4]Phone Number       : " << left << setw(50) << client.phonenumber << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[5]Pine Code          : " << left << setw(50) << client.Pincode << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
		cout << "\t\t\t\t\t\t|[6]Account Balance    : " << left << setw(50) << client.Account_Balance << "    |" << endl;
		cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;


	}
};


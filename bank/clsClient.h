#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsPerson.h"

using namespace std;

class clsClient : public clsPerson
{
private:
	enum enMode {
		EmptyMode = 1,
		UpdateMode = 2,
		AddNewMode = 3

	};
	bool _MarkForDelete = false;
	string _ID;
	string _Pincode;
	float _Balance;
	enMode _Mode;
	static clsClient _ConvertLineToClientObject(string line, string delim = "#//#") {
		vector <string> recode = clsString::Split(line, delim);

		return clsClient(enMode::UpdateMode, recode[0], recode[1], recode[2], recode[3], recode[4], recode[5], stof(recode[6]));
	 
	}
	 
	static string _ConvertClientObjectToLine(clsClient client, string delim = "#//#") {
		string line;
		line += client.getfirstName() + delim;
		line += client.getLasname() + delim;
		line += client.getEmail() + delim;
		line += client.getphoneNumber() + delim;
		line += client._ID + delim;
		line += client._Pincode + delim;
		line += to_string(client._Balance);
		return line;
	}
	static clsClient _GetEmptyClientObject() {
		return clsClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
static	vector <clsClient> _LoadClientsFromfile() {
		vector <clsClient> vtClients;
		fstream Clients;
		Clients.open("clients.txt", ios::in);
		string line;
		clsClient temp = _GetEmptyClientObject();
		if(Clients.is_open())
		{
			while (getline(Clients, line))
			{
				temp = _ConvertLineToClientObject(line);
				vtClients.push_back(temp);
			}
		}
		Clients.close();
		return vtClients;

	}
	void _Saverecordstofile(vector <clsClient> vtClient){
		fstream Clients;
		Clients.open("clients.txt", ios::out);
		if (Clients.is_open()) {
			string line;
			for (clsClient& client : vtClient) {
				if(client._MarkForDelete == false){
					line = _ConvertClientObjectToLine(client);
					Clients << line << endl;
				}
				
			}
		}
		Clients.close();
	}
	void _Update() {
		vector <clsClient> Clients = _LoadClientsFromfile();
		for (clsClient& c : Clients) {
			if (c.getAccountNumber() == AccountNumber) {
				c = *this;
				break;
			}
		}
		_Saverecordstofile(Clients);
	}
	
	void _Addnewrecodtofile(string line) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << line << endl;

			MyFile.close();
		}
	}
	void _AddNew() {
		_Addnewrecodtofile(_ConvertClientObjectToLine(*this));
	}
	
public:
	clsClient(enMode Mode ,string firsname, string lastname, string email, string phonenumber, string ID, string Pincode, float Balance) :
		clsPerson(firsname, lastname, email, phonenumber) {
		_ID = ID;
		_Pincode = Pincode;
		_Balance = Balance;
		_Mode = Mode;
	}
	bool isEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	bool isdelet(string AccountNumber) {
		vector <clsClient> Clients = _LoadClientsFromfile();
		for (clsClient  &c : Clients) {
			if (c.AccountNumber == AccountNumber) {
				c._MarkForDelete = true;

				break;
			}
		}
		_Saverecordstofile(Clients);
		*this = _GetEmptyClientObject();
		return true;
	}
	void setAccountNumber(string AccountNumber) {
		_ID = AccountNumber;
	}
	string getAccountNumber() {
		return _ID;
	}
	void setPincode(string Pincode) {
		_Pincode = Pincode;
	}
	string getPincode() {
		return _Pincode;
	}
	
	void setAcc_Balane(float Balance) {
		_Balance = Balance;
	}
	float getAcc_Balance() {
		return _Balance;
	}
	__declspec(property(get = getAccountNumber, put = setAccountNumber)) string AccountNumber;
	__declspec(property(get = getPincode, put = setPincode)) string Pincode;
	__declspec(property(get = getAcc_Balance, put = setAcc_Balane)) float Account_Balance;

	static clsClient find(string AccountNumber) {
		vector <clsClient> vtClients;
		string line;
		fstream Clients;
		
		Clients.open("clients.txt", ios::in);
		if (Clients.is_open()) {
			while (getline(Clients, line)) {
				clsClient client = _ConvertLineToClientObject(line);
				if (client._ID == AccountNumber) {
					return client;
				}
				vtClients.push_back(client);
			}
			Clients.close();
	
		}
         return _GetEmptyClientObject();

	}


	static clsClient find(string AccountNumber, string Pincode) {
		vector <clsClient> vtClients;
		string line;
		fstream Clients;

		Clients.open("clients.txt", ios::in);
		if (Clients.is_open()) {
			while (getline(Clients, line)) {
				clsClient client = _ConvertLineToClientObject(line);
				if (client._ID == AccountNumber && client._Pincode == Pincode) {
					return client;
				}
				vtClients.push_back(client);
			}
			Clients.close();

		}
		return _GetEmptyClientObject();
	}
	static clsClient findTosendOrRequat(string AccountNumber , string firstname) {
		
		
		vector <clsClient> vtClients;
		string line;
		fstream Clients;

		Clients.open("clients.txt", ios::in);
		if (Clients.is_open()) {
			while (getline(Clients, line)) {
				clsClient client = _ConvertLineToClientObject(line);
				if (client._ID == AccountNumber && client.getFullName() == firstname) {
					return client;
				}
				vtClients.push_back(client);
			}
			Clients.close();

		}
		return _GetEmptyClientObject();
	}
	void printInfo() {
		if (!isEmpty()) {
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   Account number     : " << left << setw(50) << AccountNumber << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   FirstName          : " << left << setw(50) << firstname << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   Lastname           : " << left << setw(50) << lastname << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   FullNam            : " << left << setw(50) << getFullName() << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   Email              : " << left << setw(50) << Email << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   Phone Number       : " << left << setw(50) << phonenumber << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   Pine Code          : " << left << setw(50) << Pincode << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   Account Balance    : " << left << setw(50) << Account_Balance << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;

		}
		else
		{
			cout << "\n\t\t\t\t\t____________________________________________________\n";
			cout << "\t\t\t\t\t| Acc.Number  | " << left << setw(33) << "-" << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------";
			cout << "\n\t\t\t\t\t| FirstName   | " << left << setw(33) << "-" << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------";
			cout << "\n\t\t\t\t\t| lastName    | " << left << setw(33) << "-" << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------";
			cout << "\n\t\t\t\t\t| FullName    | " << left << setw(33) << "-" << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------";
			cout << "\n\t\t\t\t\t| Email       | " << left << setw(33) << "-" << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------";
			cout << "\n\t\t\t\t\t| PhoneNumber | " << left << setw(33) << "-" << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------";
			cout << "\n\t\t\t\t\t| Pincode     | " << left << setw(33) << "-" << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------";
			cout << "\n\t\t\t\t\t| Acc.balance | " << left << setw(33) << 0 << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------\n";
		}
	}
	enum enSave {
		svFieldEmptyObject = 0,
		svSavesuccessfully = 1,
		svfieldAccountAlredyExist = 2
	};
static	bool isAccExist(string accountNumber) {
		vector <clsClient> vtClients = _LoadClientsFromfile();
		for (clsClient c : vtClients) {
			if (c.AccountNumber == accountNumber) {
				return true;
			}
		}
		return false;
	}
    static clsClient getAddNewClientObject(string AccountNumber) {
		return clsClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	enSave Save(){

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			{
				if (isEmpty())
				{

					return enSave::svFieldEmptyObject;

				}
			}

		}

		case enMode::UpdateMode:
		{


			{
				_Update();

				return enSave::svSavesuccessfully;

				break;
			}
		}

		case enMode::AddNewMode:
		{
			{
				if (clsClient::isAccExist(_ID))
				{
					return enSave::svfieldAccountAlredyExist;
				}
				else
				{
					_AddNew();

					_Mode = enMode::UpdateMode;
					return enSave::svSavesuccessfully;
				}

				break;
			}
		}
		}

	}
	static vector <clsClient> GetClientList() {
		return _LoadClientsFromfile();
	}
	void Deposite(float Amount) {
		_Balance += Amount;
	}
	void withraw(float Amount) {
		_Balance -= Amount;
	}
	static float TotalBalanc() {
		vector <clsClient> vtClients = GetClientList();
		float TotalBalans = 0;
		for (clsClient client : vtClients) {
			TotalBalans += client.Account_Balance;
		}
		return TotalBalans;
	}

	void sendMony(clsClient &client , float Amount) {
		this->withraw(Amount);
		client.Deposite(Amount);
	}
};



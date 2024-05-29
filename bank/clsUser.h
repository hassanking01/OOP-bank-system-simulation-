#pragma once
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsClient.h"
#include "vector"
#include "fstream"
#include "clsDate.h"
#include "clsPerson.h"
#include "glogal.h"
class clsUser : public clsPerson
{
private:
	struct transfirLog
	{
		string _date = clsDate::DateToString(clsDate());
		string _senderAmountBefor;
		string _senderAmountAfter;
		string _reciverAmountBefor;
		string _reciverAmountAfter;
		string _operator;
		transfirLog( string sendB, string sendA, string recivB, string recivA, string OP) {
			
			_senderAmountBefor = sendB;
			_senderAmountAfter = sendA;
			_reciverAmountBefor = recivB;
			_reciverAmountAfter = recivA;
			_operator = OP;
		}
		transfirLog empty() {
			return transfirLog("", "", "", "", "");
		}

	};
	enum enMode { UpdateMode = 1, Empty = 2, AddnewMode = 3 };
	static clsUser _converuserlinetoobject(string line) {
		vector <string> record = clsString::Split(line, "#//#");
		clsUser user(enMode::UpdateMode , stoi(record[0]), record[1], record[2], record[3], record[4], record[5], record[6]);
		return user;
	}
	int _Premisstion;
	string _Username;
	string _Password;
	enMode _Mode;
	bool Markfordeletion = false;
	transfirLog _transfirLog = _transfirLog.empty();
	static clsUser _GetEmptyObject() {
		return clsUser(enMode::Empty, 0, "", "", "", "", "", "" );
	}
	static vector <clsUser> _Loadrecodesfromfile() {
		vector <clsUser> vtusers;
		fstream usersfile;
		usersfile.open("users.txt", ios::in);
		if (usersfile.is_open()) {
			string line;
			while (getline(usersfile, line)) {
				clsUser user = _converuserlinetoobject(line);
				vtusers.push_back(user);
			}
			usersfile.close();
		}
		return vtusers;
	}
	static string _ConvertuserObjectToLine(clsUser user, string delim = "#//#") {
		string line;
		line += to_string(user.permisstion) + delim;
		line += user.username + delim;
		line += user.password + delim;
		line += user.getfirstName() + delim;
		line += user.getLasname() + delim;
		line += user.getEmail() + delim;
		line += user.getphoneNumber() ;
		
		return line;
	}
	void _saveTofile(vector <clsUser> vtusers) {
		fstream usersfile;
		usersfile.open("users.txt", ios::out);
		if (usersfile.is_open()) {
			string line;

			for (clsUser& user : vtusers) {
				if(user.Markfordeletion == false){
				line = _ConvertuserObjectToLine(user);
				usersfile << line << endl;
				}
			}
			usersfile.close();
		}
	}
	 void _Update() {
		vector <clsUser> vtusers = _Loadrecodesfromfile();
		for (clsUser& user : vtusers) {
			if (user.getusername() == _Username) {

				user = *this;

			}
		}
		_saveTofile(vtusers);
	 }
	 void _Addnewuser() {
		 fstream usersfile;
		 usersfile.open("users.txt", ios::out | ios::app);
		 if (usersfile.is_open()) {
			 string line;
			 usersfile << _ConvertuserObjectToLine(*this) << endl;
			 usersfile.close();
		 }
	 }
	  string _getrecord(string delim = "#//#") {
		  clsDate Date;
		  string line;
		 line += Date.DateToString()  + delim;
		 line += _Username + delim;
		 line += password + delim;
		 line += to_string(permisstion);
		 return line;
	  
	  }
	  
	  
	  static string _ConverttransfirLog(transfirLog log, string delim = "#//#") {
		  string line;
		  line += log._date + delim;
		  line += log._senderAmountBefor + delim;
		  line += log._reciverAmountBefor + delim;
		  line += log._operator + delim;
		  line += log._senderAmountAfter + delim;
		  line += log._reciverAmountAfter;
		  return line;
		  
	  }
	  static void _addtransfirLogtoFile( transfirLog log) {
		  fstream transirfile;
		  transirfile.open("transfirLog.txt", ios::out | ios::app);
		  string line;
		  if (transirfile.is_open()) {
			  line = _ConverttransfirLog(log);
			  transirfile << line << endl;
			  transirfile.close();
		  }
	  }
	
protected:
   
	


public:

	clsUser(enMode mode, int premisstion, string username, string password, string firsname, string lastname, string email, string phonenumber)
		:clsPerson(firsname, lastname, email, phonenumber) {
		_Mode = mode;
		_Premisstion = premisstion;
		_Username = username;
		_Password = password;

	}
	bool isEmpty() {
		return (_Mode == enMode::Empty);
	}
	void setUserName(string username) {
		_Username = username;
	}
	string getusername() {
		return _Username;
	}
	void setPremisstion(int premisstion) {
		_Premisstion = premisstion;
	}
	int getpremisstion() {
		return _Premisstion;
	}
	void setpassword(string password) {
		_Password = password;
	}
	string getpassword() {
		return _Password;
	}
	__declspec(property(get = getusername, put = setUserName)) string username;
	__declspec(property(get = getpremisstion, put = setPremisstion)) int permisstion;
	__declspec(property(get = getpassword, put = setpassword)) string password;

	void printInfo() {
		if (1) {
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   username           : " << left << setw(50) << username << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			cout << "\t\t\t\t\t\t|   password           : " << left << setw(50) << password << "    |" << endl;
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
			cout << "\t\t\t\t\t\t|   permisstion        : " << left << setw(50) << permisstion << "    |" << endl;
			cout << "\t\t\t\t\t\t|------------------------------------------------------------------------------|" << endl;
			

		}
		else
		{
			cout << "\n\t\t\t\t\t____________________________________________________\n";
			cout << "\t\t\t\t\t| username     | " << left << setw(33) << "-" << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------";
			cout << "\n\t\t\t\t\t| password    | " << left << setw(33) << "-" << "  |";
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
			cout << "\n\t\t\t\t\t| permisstion | " << left << setw(33) << 0 << "  |";
			cout << "\n\t\t\t\t\t----------------------------------------------------\n";
		}
	}
	static clsUser find(string username) {
		vector <clsUser> vtusers;
		fstream usersfile;
		usersfile.open("users.txt", ios::in);
		if (usersfile.is_open()) {
			string line;
			
			while (getline(usersfile, line)) {
				clsUser user = _converuserlinetoobject(line);
				if (user.username == username)
					return user;
				else
				{
					vtusers.push_back(user);
				}
			}
		}
		return _GetEmptyObject();
	}
	static clsUser find(string username , string password) {
		vector <clsUser> vtusers;
		fstream usersfile;
		usersfile.open("users.txt", ios::in);
		if (usersfile.is_open()) {
			string line;

			while (getline(usersfile, line)) {
				clsUser user = _converuserlinetoobject(line);
				if (user.username == username && user.password == password)
					return user;
				else
				{
					vtusers.push_back(user);
				}
			}
		}
		return _GetEmptyObject();
	}
	static bool isusetrexist(string username) {
		vector <clsUser> vtusers = _Loadrecodesfromfile();
		for (clsUser user : vtusers) {
			if (user.username == username) {
				return true;
			}
		}
		return false;
	}
	enum ensave {svSuccessfully , svfieldEmpty , svfieldAlredyExsit};
	void transfir(clsClient&send, clsClient&reciver, float amount) {
		_transfirLog._reciverAmountBefor = to_string(reciver.Account_Balance);
		_transfirLog._senderAmountBefor =  to_string(send.Account_Balance);
		_transfirLog._operator = this->username;
		send.Account_Balance -= amount;
		reciver.Account_Balance += amount;
		_transfirLog._reciverAmountAfter = to_string(reciver.Account_Balance);
		_transfirLog._senderAmountAfter = to_string(send.Account_Balance);
		_addtransfirLogtoFile(_transfirLog);
		_transfirLog.empty();
	}
	ensave save() {
		switch (_Mode)
		{
		case clsUser::UpdateMode:
			_Update();
			return ensave::svSuccessfully;
			break;
		case clsUser::Empty:
			if(isEmpty())
			return ensave::svfieldEmpty;
			break;
		case clsUser::AddnewMode:
			if (isusetrexist(_Username)) {
				return ensave::svfieldAlredyExsit;
			}
			else
			{
				_Addnewuser();
				_Mode = enMode::UpdateMode;
				return ensave::svSuccessfully;
			}
			break;
		default:
			break;
		}
	}
	bool have_access(int section) {
		if (_Premisstion == -1)
			return true;

		return (_Premisstion & (1 << (section - 1)));
	}
	static vector <clsUser> Getuserdata() {
		return _Loadrecodesfromfile();
	}
	static clsUser GetAdduser(string username) {
		return clsUser(enMode::AddnewMode, 0,username, "", "", "", "","");
	}
	void _delete() {
		Markfordeletion = true;
		vector <clsUser> vtUsers = _Loadrecodesfromfile();
		for (clsUser& user : vtUsers) {
			if (user.username == username) {
				
				user = *this;
			}
		}
		_saveTofile(vtUsers);
	}

	 void saveLoginRegist() {
		fstream LoginRegister;
		LoginRegister.open("LoginRegister.txt", ios::out | ios::app);
		string line;
		if (LoginRegister.is_open()) {
			line = _getrecord();
			LoginRegister << line << endl;
			LoginRegister.close();
		}

	}
};


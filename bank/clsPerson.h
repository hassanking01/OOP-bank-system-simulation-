#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
private:

	string _firstName;
	string _lastName;
	string _Email;
	string _PhoneNumber;
	
protected:

public:
	
	clsPerson( string firsname, string lastname, string email, string phonenumber) {
		
		_firstName = firsname;
		_lastName = lastname;
		_Email = email;
		_PhoneNumber = phonenumber;

	}
	
	
	//set firstName
	void setFirstName(string firstName) {
		_firstName = firstName;
	}
	// set lastName
	void setLastName(string lastName) {
		_lastName = lastName;
	}
	//set email
	void setEmail(string email) {
		_Email = email;
	}
	//set phoneNumber
	void setPhoneNumber(string phoneNumber) {
		_PhoneNumber = phoneNumber;
	}


	
	//get firstName
	string getfirstName() {
		return _firstName;
	}
	//get lastName
	string getLasname() {
		return _lastName;
	}
	//get fullname
	string getFullName() {
		return _firstName + " " + _lastName;
	}
	//get phoneNumber
	string getphoneNumber() {
		return _PhoneNumber;
	}
	//get email
	string getEmail() {
		return _Email;
	}
	void sendEmail(string subject, string body) {
		cout << "the following message successfully sent to this Email  : " << _Email << endl;
		cout << "subject  : " << subject << endl;
		cout << "body     : " << body << endl;
	}
	void sendTextMasseg(string TextMessage) {
		cout << "the following text successfully sent to this phoneNumber : " << _PhoneNumber << endl;
		cout << TextMessage << endl;
	}
	void printInfo() {
		cout << "\n______________________________________\n";
		cout << "firstname   : " << _firstName << endl;
		cout << "lastname    : " << _lastName << endl;
		cout << "fullname    : " << getFullName() << endl;
		cout << "phoneNumber : " << _PhoneNumber << endl;
		cout << "email       : " << _Email;
		cout << "\n______________________________________\n";
		
	}
	__declspec(property(get = getfirstName, put = setFirstName))string firstname;
	__declspec(property(get = getphoneNumber, put = setPhoneNumber))string phonenumber;
	__declspec(property(get = getLasname, put = setLastName))string lastname;
	__declspec(property(get = getEmail, put = setEmail))string Email;

};


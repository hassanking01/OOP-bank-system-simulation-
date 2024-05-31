#pragma once
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clscurrency
	
{
	enum enMode { empty, update };
	string _country;
	string _currency_code;
    string _currency_name;
	float _Rate;
	 enMode _Mode;
	static clscurrency _convertlinetocurrency(string line , string delim = "#//#") {
		vector <string> vtstringcurrency = clsString::Split(line, delim);
		return clscurrency( vtstringcurrency[0], vtstringcurrency[1], vtstringcurrency[2], stof(vtstringcurrency[3]) , enMode::update);
	}
  static vector < clscurrency> _loaddatafromfile() {
		vector <clscurrency> vtCurrency;
		fstream currencyfile;
		currencyfile.open("Currencies.txt", ios::in);
		string line;
		if (currencyfile.is_open())
		{
			while (getline(currencyfile, line)) {
				clscurrency currency = _convertlinetocurrency(line);
				vtCurrency.push_back(currency);
			}
			currencyfile.close();
		}
		return vtCurrency;
  }
  string _cobverObjecttoline(clscurrency currency, string delim = "#//#") {
	  string line; 
	  line += currency._country + delim;
	  line += currency._currency_code + delim;
	  line += currency._currency_name + delim;
	  line += to_string(currency._Rate);
	  return line;
  }

	static clscurrency _GetemptyObject() {
		return clscurrency("", "", "", 0, empty);
	}
	void _savedate(vector <clscurrency> vtcurrencyes) {
		string line;
		fstream currencyfile;
		currencyfile.open("Currencies.txt", ios::out);
		if (currencyfile.is_open()) {
			for (clscurrency& currency : vtcurrencyes) {
				line = _cobverObjecttoline(currency);
				currencyfile << line << endl;
			}
		}

	}
	 void _update() {
		vector <clscurrency> vtcurrencyes = _loaddatafromfile();
		for (clscurrency & currency : vtcurrencyes) {
			if (currency._country == _country) {
				currency = *this;
			}
		}
		_savedate(vtcurrencyes);
	 }
public :
	clscurrency( string country, string currencyCode, string currencyName, float Rate , enMode Mode) {
		_country = country;
		_currency_code = currencyCode;
		_currency_name = currencyName;
		_Rate = Rate;
		_Mode = Mode;
	}
	void setcountery(string countery) {
		_country = countery;
	}
	void setcurrencycode(string code) {
		_currency_code = code;
	}
	void setcurrencyname(string name) {
		_currency_name = name;
	}
	void setcurrencyRate(float rate) {
		_Rate = rate;
	}
	string getcountery() {
		return _country;
	}
	string getcurrencycode() {
		return _currency_code;
	}
	string getcurrencyname() {
		return _currency_name;
	}
	float getcurrencyrate() {
		return _Rate;
	}

	__declspec(property(get = getcountery, put = setcountery)) string countery;
	__declspec(property(get = getcurrencycode, put = setcurrencycode)) string currencycode;
	__declspec(property(get =getcurrencyname, put = setcurrencyname)) string currencyname;
	__declspec(property(get = getcurrencyrate, put = setcurrencyRate)) float currencyrate;


 //static	bool isEmpry(string currencyName) {
	//	return _Mode == empty;
 //}
 	bool isEmpry() {
	 return _Mode == empty;
    }

	static clscurrency find(string country) {
		vector <clscurrency> vtcurrencyes = _loaddatafromfile();
		for (clscurrency& currency : vtcurrencyes) {
			if (clsString::LowerAllString(currency._country) == clsString::LowerAllString(country)) {
				return currency;
			}
		}
		return _GetemptyObject();
	}
	static vector <clscurrency> findcode(string code) {
		vector <clscurrency> vtcurrencyes = _loaddatafromfile();
		vector <clscurrency> vtcode; 
		for (clscurrency& currency : vtcurrencyes) {
			if (clsString::LowerAllString(currency._currency_code) == clsString::LowerAllString(code)) {
				vtcode.push_back(currency);
			}
		}
		return vtcode ;
	}
	static vector <clscurrency> GetcurrencyesData() {
		return _loaddatafromfile();
	}
	enum enSave{ svSuccessfully , svEmptyObject };
	 enSave save() {
		switch (_Mode)
		{
		case clscurrency::empty:
			if (isEmpry())
				return svEmptyObject;
			break;
		case clscurrency::update:
			_update();
			return svSuccessfully;
			break;
		default:
			break;
		}
	}
};


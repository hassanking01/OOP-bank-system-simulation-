#pragma once
#include "clsInputValidate.h"
#include "clsClient.h"
#include "clsScreen.h"
#include "glogal.h"

class clsShowtransactionhistory 
{

	static void _printreacord(transfirLog t) {
		cout << "\n";
		cout << left << setw(40) << "|    "+ t._date;
		cout << left << setw(27) << "|     " + to_string(t._senderAmountBefor);
		cout << left << setw(27) << "|       "  + to_string(t._reciverAmountBefor);
		cout << left << setw(27) << "|       " + to_string( t._reciverAmountAfter - t._reciverAmountBefor);

		cout << left << setw(27) << "|     " + curentUser.username;
		cout << left << setw(27) << "| " + to_string(t._senderAmountAfter);
		cout << left << setw(27) << "| " + to_string(t._reciverAmountAfter) << "|";

		cout << "\n|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|";
	}
	

public:
	static void gettransfirhistory() {
		 vector <transfirLog>  vttransactionhistory = curentUser.Gettransactionlog();
		cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|";
		cout << "\n";
		cout << left << setw(40) << "|                 date";
		cout << left << setw(27) << "| send balance befor";
		cout << left << setw(27) << "| reciver balance befor";
		cout << left << setw(27) << "|     amount" ;
		cout << left << setw(27) << "|     operetor user";
		cout << left << setw(27) << "| send balance after";
		cout << left << setw(27) << "| reciver balance after" << "|";

		cout << "\n|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|";
		for (transfirLog& log : vttransactionhistory) {
			_printreacord(log);
	    }
	
	}
};


#pragma once
#include "clsUser.h"
#include "vector"


clsUser curentUser = clsUser::find("", "");

string sectons[18] = {

	"addClient",
	"clientsList",
	"clientInfo",
	"deleteClient",
	"updateClientInfo",
	"transactionsMenu",
	"manageUsersMenu",
	"userslist",
	"addnewuser",
	"userInfo",
	"Deleteuser",
	"updateuser",
	"loginregister",
	"Deposite",
	"Withdraw",
	"Totale_balance",
	"Send_Money"
};
bool logfield = true;
clsDate Date;


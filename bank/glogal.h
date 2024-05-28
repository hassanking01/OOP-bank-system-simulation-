#pragma once
#include "clsUser.h"
clsUser curentUser = clsUser::find("", "");
string sections[7] = {
	   "View clients list",
	   "Add client",
	   "Client info",
	   "Delete client",
	   "Update client info",
	   "Transactions",
	   "Manage users"
};
bool logfield = true;
clsDate Date;

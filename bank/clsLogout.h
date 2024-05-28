#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "glogal.h"
class clsLogout
{
public:
	static void Logout() {
		curentUser = clsUser::find("", "");
	}
};


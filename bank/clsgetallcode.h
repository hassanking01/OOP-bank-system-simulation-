#pragma once
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clscurrency.h"
#include <set>
class clsgetallcode
{




public:
    static void printallcodes() {
        vector<clscurrency> vtcode = clscurrency::GetcurrencyesData();
        set<string> uniqueCodes;

        for (clscurrency currnceycode : vtcode) {
            uniqueCodes.insert(currnceycode.currencycode);
        }

        for (const string& code : uniqueCodes) {
            cout << code << endl;
        }
    }
};


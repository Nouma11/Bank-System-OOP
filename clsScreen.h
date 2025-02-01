#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsGlobal.h"
#include"clsDate.h"

using namespace std;

class clsScreen
{
private:
    static void _ShowDateandUser() {
        cout << "\t\t\t\t\tUser: " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << endl;
        cout << endl;
    }
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        _ShowDateandUser();
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            
            
            _ShowDateandUser();
            
            return false;
        }
        else
        {
            return true;
        }

    }

};

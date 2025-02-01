#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include"clsInputValidation.h"
#include <iomanip>
class clsFindUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions     : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:
    static void FindUser() {
        _DrawScreenHeader("\t  Find User Screen");

        cout << "Please enter Account Number : ";
        string UserName = clsInputValidation::ReadString();
        while (!clsUser::IsUserExist(UserName)) {
            cout << " Account Number Not Found : ";
            UserName = clsInputValidation::ReadString();
        }
        clsUser User = clsUser::Find(UserName);
        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }
        _PrintUser(User);
    }
    
};


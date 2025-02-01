#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include"clsInputValidation.h"
#include <iomanip>
class clsDeleteUserScreen:protected clsScreen
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
    static void DeleteUser() {
        _DrawScreenHeader("\t Delete User Screen");
        cout << "Please enter UserName : ";
        string UserName = clsInputValidation::ReadString();
        while (!clsUser::IsUserExist(UserName)) {
            cout << "UserName Not Found : ";
            UserName = clsInputValidation::ReadString();
        }
        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);
        char Answer = 'n';
        cout << "\n Do You Want to Delete this User ? [y/n] ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            if (User.Delete()) {
                cout << "\nUser Deleted Succefully .";
                _PrintUser(User);
            }
            else {
                cout << "\nError User Was not Deleted";
            }
        }
    }
};


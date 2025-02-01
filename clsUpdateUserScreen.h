#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidation.h"
#include <iomanip>
class clsUpdateUserScreen:clsScreen
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
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }


        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }

        return Permissions;

    }
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidation::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidation::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidation::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidation::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidation::ReadString();

        User.Permissions = _ReadPermissionsToSet();

    }
    public:
        static void UpdateUser() {
            _DrawScreenHeader("\t  Update User Screen");

            cout << "Please enter UserName : ";
            string UserName = clsInputValidation::ReadString();
            while (!clsUser::IsUserExist(UserName)) {
                cout << " UserName Not Found : ";
                UserName = clsInputValidation::ReadString();
            }
            clsUser User = clsUser::Find(UserName);
            _PrintUser(User);


            char Answer = 'n';
            cout << "\n Do You Want to Update this User ? [y/n] ";
            cin >> Answer;
            if (toupper(Answer) == 'Y')
            {
                cout << "\n\n Update User Info " << endl;
                cout << "__________________________\n";
                _ReadUserInfo(User);
                clsUser::enSaveResults SaveResult;
                SaveResult = User.Save();
                switch (SaveResult)
                {
                case  clsUser::enSaveResults::svSucceeded:
                {
                    cout << "\nUser Addeded Successfully :-)\n";
                    _PrintUser(User);
                    break;
                }
                case clsUser::enSaveResults::svFaildEmptyObject:
                {
                    cout << "\nError User was not saved because it's Empty";
                    break;

                }
                case clsUser::enSaveResults::svFaildUserExists:
                {
                    cout << "\nError User was not saved because UserName is used!\n";
                    break;

                }

                }
            }
        }

};


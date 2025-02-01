#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include"clsBankClient.h"
#include"clsInputValidation.h"
#include"clsUserListScreen.h"
#include"clsAddUSerScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
class clsUserScreen:protected clsScreen
{
private:
    enum _enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };
    static void _ShowListUsersScreen() {
        clsUserListScreen::ShowUsersList();
    }
    static void _ShowAddNewUserScreen() {
        clsAddUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUserScreen() {
        clsDeleteUserScreen::DeleteUser();
    }
    static void _ShowUpdateUserScreen() {
        clsUpdateUserScreen::UpdateUser();
    }
    static void _ShowFindUserScreen() {
        clsFindUserScreen::FindUser();
    }
    static void _PerfromManageUsersMenueOption(_enManageUsersMenueOptions ManageUsersMenueOption)
    {
        switch (ManageUsersMenueOption)
        {
        case _enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eFindUser:
        {
            system("cls");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case _enManageUsersMenueOptions::eMainMenue:
        {
            
        }
        }

    }

    static short _ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidation::ReadNumberBetwen(1,6,"Try Again [1 to 6]");
        return Choice;
    }
   static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage User Menue...";
        system("pause>0");
        ShowManageUsersMenue();

    }
public:
   static void ShowManageUsersMenue()
    {



        system("cls");
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tManage User Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerfromManageUsersMenueOption((_enManageUsersMenueOptions)_ReadManageUsersMenueOption());
    }
};


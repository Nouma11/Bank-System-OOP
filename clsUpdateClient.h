#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidation.h"
#include <iomanip>
class clsUpdateClient:protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidation::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidation::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidation::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidation::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidation::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidation::ReadDBNumber("Try Again");
    }
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
    static void UpdateCleint() {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t  Update Client Screen");

        cout << "Please enter Account Number : ";
        string AccountNumber = clsInputValidation::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << " Account Number Not Found : ";
             AccountNumber = clsInputValidation::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);


        char Answer = 'n';
        cout << "\n Do You Want to Update this Client ? [y/n] ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            cout << "\n\n Update Client Info " << endl;
            cout << "__________________________\n";
            _ReadClientInfo(Client);
            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client.Save();
            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Addeded Successfully :-)\n";
                _PrintClient(Client);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }
            case clsBankClient::enSaveResults::svFaildAccountNumberExists:
            {
                cout << "\nError account was not saved because account number is used!\n";
                break;

            }

            }
        }
    }
};


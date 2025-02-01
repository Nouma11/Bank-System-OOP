#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidation.h"
#include <iomanip>
class clsWithdrawScreen :protected clsScreen
{
private:
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
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t\Withdraw Screen");

        cout << "Please enter Account Number : ";
        string AccountNumber = clsInputValidation::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            cout << "Please enter Account Number : ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter withdraw amount? ";
        Amount = clsInputValidation::ReadDBNumber("Try Again");

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if(Client1.Withdraw(Amount))
            
            {
                cout << "\nAmount Withdraw Successfully.\n";
                cout << "\nNew Balance Is: " << Client1.AccountBalance;
            }
            else {
        
            cout << "\nCannot withdraw, Insuffecient Balance!\n";
            cout << "\nAmout to withdraw is: " << Amount;
            cout << "\nYour Balance is: " << Client1.AccountBalance;
            }

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};
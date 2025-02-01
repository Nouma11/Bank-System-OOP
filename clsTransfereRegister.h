#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidation.h"
#include <iomanip>
#include"clsUser.h"
class clsTransfereRegister:protected clsScreen
{
private:

    static void PrintLoginRegisterRecordLine(clsBankClient::stTransferRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << LoginRegisterRecord.DateTime;
        
        cout << "| " << setw(10) << left << LoginRegisterRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << LoginRegisterRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Amount;
        cout << "| " << setw(12) << left << LoginRegisterRecord.SourceAccountBalance;
        cout << "| " << setw(12) << left << LoginRegisterRecord.DestinationAccountBalance;
        cout << "| " << setw(10) << left << LoginRegisterRecord.UserName;
    }

public:

    static void ShowTransfereRegister()
    {
       
        vector <clsBankClient::stTransferRegisterRecord> vTransferRegisterRecord = clsBankClient::GetTransferRegisterList();

        string Title = "\Transfer Register List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Account";
        cout << "| " << left << setw(10) << "D.Account";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(12) << "S.Balance";
        cout << "| " << left << setw(12) << "d.Balance";
        cout << "| " << left << setw(10) << "UserName";
        
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferRegisterRecord Record : vTransferRegisterRecord)
            {

                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};


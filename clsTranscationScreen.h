#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include"clsInputValidation.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransfereScreen.h"
#include"clsTransfereRegister.h"
#include <iomanip>

class clsTranscationScreen:protected clsScreen
{
private:
    enum _enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3,eShowTransfere=4,
       eShowTransfereRegister=5, eShowMainMenue = 6 };
   static short _ReadTransactionsMenueOption()
    {
       cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        
        short Choice = clsInputValidation::ReadNumberBetwen(1, 6,"try Again [1 to 6 :");
        return Choice;
    }

   static void _ShowDepositScreen() {
       clsDepositScreen::ShowDepositScreen();
   }
   static void _ShowWithDrawScreen() {
       clsWithdrawScreen::ShowWithdrawScreen();
   }
   static void _ShowTotalBalancesScreen() {
       clsTotalBalanceScreen::ShowTotalBalances();
   }
   static void _ShowtransfereScreen() {
       clsTransfereScreen::ShowTransferScreen();
   }
   static void _ShowTransfereRegister() {
       clsTransfereRegister::ShowTransfereRegister();
   }
   static void _PerfromTranactionsMenueOption(_enTransactionsMenueOptions TransactionMenueOption)
    {
        switch (TransactionMenueOption)
        {
        case _enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case _enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case _enTransactionsMenueOptions::eShowTransfere:
        {
            system("cls");
            _ShowtransfereScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case _enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case _enTransactionsMenueOptions::eShowTransfereRegister:
        {
            system("cls");
            _ShowTransfereRegister();
            _GoBackToTransactionsMenue();
            break;
        }

        case _enTransactionsMenueOptions::eShowMainMenue:
        { 
            
        }
        }

    }
  static void _GoBackToTransactionsMenue()
   {
       cout << "\n\nPress any key to go back to Transactions Menue...";
       system("pause>0");
       ShowTransactionsMenue();

   }
public:
    
    static void ShowTransactionsMenue()
    {
        system("cls");
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t\tTranscation screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Tranfere.\n";
        cout << setw(37) << left << "" << "\t[5] Show Tranfere Register .\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromTranactionsMenueOption((_enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }
   

 
};


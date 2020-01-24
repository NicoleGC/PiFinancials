#include "AccountTransactionManager.h"
#include "BankAccount.h"
#include "BankAccountProfile.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

AccountTransactionManager::AccountTransactionManager(){};

AccountTransactionManager::~AccountTransactionManager(){};

void AccountTransactionManager::depositMoney(BankAccount account, int amount)
{
    account.deposit(amount);
};

void AccountTransactionManager::withdrawMoney(BankAccount account, int amount)
{
    account.withdraw(amount);
};

string AccountTransactionManager::checkBalance(BankAccount account)
{
    ostringstream ss;
    ss << account.getBalance();
    return ss.str();
};

void AccountTransactionManager::transferMoney(BankAccount FromAccount, BankAccount ToAccount, int amount)
{
    if (FromAccount.getBalance() >= amount)
    {
        FromAccount.withdraw(amount);
        ToAccount.deposit(amount);
        cout << "$" << amount << " have been transferred from " << FromAccount.getAccountNumber() << " to " << ToAccount.getAccountNumber() << "." << endl;
    }
    else
    {
        cout << "Error! Not enough funds" << endl;
    }
}

// class AccountManagerTransaction
// {
//   public:
//     AccountManagerTransaction();
//     ~AccountManagerTransaction();

//     void depositMoney(int amount)
//     {
//         (this->bankacc).deposit(amount);
//     }

//     void withdrawMoney(int amount)
//     {
//         if (this->bankacc).getBalance() > amount) {
//             (this->bankacc).withdraw(amount);
//             cout << "$" << amount << " have been deposited to " << (this->bankacc).getAccountNumber() << endl;
//         } else {
//             cout << "Sorry yaar deposit nahi kar sakta, paisay nahi hain" << endl;
//         }
//     }

//     string checkBalanace()
//     {
//         return (this->bankacc).getBalance();
//     }

//     void transferMoney(BankAccount ToAccount, int amount)
//     {
//         if ((this->bankacc).getBalance() >= amount)
//         {
//             (this->bankacc).withdraw(amount);
//             ToAccount.deposit(amount);
//             cout << "$" << amount <<  " have been transferred from " << (this->bankacc).getAccountNumber() << " to " << ToAccount.getAccountNumber() << "." << endl;
//         }
//         else
//         {
//             cout << "Sorry yaar transfer nahi kar sakta, paisay nahi hain" << endl;
//         }
//     }
// }

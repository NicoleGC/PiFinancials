// ACCOUNT_TRANSACTION_MANAGER_H

#pragma once

#ifndef ACCOUNT_TRANSACTION_MANAGER_H
#define ACCOUNT_TRANSACTION_MANAGER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "BankAccount.h"
#include "BankAccountProfile.h"

class AccountTransactionManager 
{
    public:
        AccountTransactionManager();
        ~AccountTransactionManager();
        void depositMoney(BankAccount account, int amount);
        void withdrawMoney(BankAccount account, int amount);
        std::string checkBalance(BankAccount account);
        void transferMoney(BankAccount FromAccount, BankAccount ToAccount, int  amount);
   

};



#endif // !AccountTransactionManager
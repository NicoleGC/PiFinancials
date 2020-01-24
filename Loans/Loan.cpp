#include <iostream>
#include <string>
#include <vector>
// #include "operations.cpp"
#include "Loan.h"
#include "../BankAccount/BankAccount.h"

using namespace std;

Loan::Loan(std::string inputtedAccountNumber, int amount)
{
	this->amount = amount;
	this->accountNumber = inputtedAccountNumber;
    this->status = "pending";
};


int Loan::getAmount()
{
	return this->amount;
};

std::string Loan::getStatus()
{
	return this->status;
};

std::string Loan::getAccountNumber()
{
	return this->accountNumber;
};

bool Loan::approve(){
    this->status = "approved";
    BankAccount acct = BankAccount(accountNumber);
    acct.deposit(amount);
    return true;
}

bool Loan::deny(){
    this->status = "denied";
    return true;
}

bool Loan::operator==(Loan otherLoan) const {
    if (otherLoan.getAccountNumber() == accountNumber && otherLoan.getAmount() == amount){
        return true;
    } 
    return false;
}
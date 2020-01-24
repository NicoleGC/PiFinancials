#pragma once

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H 

#include <iostream>
#include <string>
#include <vector>
// #include "operations.cpp"

class BankAccount
{
public:
	BankAccount(std::string inputtedAccountNumber);
	~BankAccount();
	BankAccount();

	std::string getAccountNumber();
	void withdraw(int amount);
	void deposit(int amount);
	int getBalance();
	bool updateBalance();
	void setAccountNumber(std::string accNo);

private:

	std::string accountNumber;
	int balance;
	// operation operations;

};

// BankAccount::BankAccount()
// {
// }

// BankAccount::~BankAccount()
// {
// }

#endif // !BankAccount


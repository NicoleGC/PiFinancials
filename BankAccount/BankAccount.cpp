#include <iostream>
#include <string>
#include <vector>
// #include "operations.cpp"
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount(string inputtedAccountNumber)
{
	this->balance = 0;
	this->accountNumber = inputtedAccountNumber;
}

BankAccount::~BankAccount() 
{

}
BankAccount::BankAccount(){}
string BankAccount::getAccountNumber()
{
	return this->accountNumber;
}


void BankAccount::withdraw(int amount)
{
	if (amount > balance)
	{
		this->balance = (this->balance) - amount;
		updateBalance();
		cout << "$" << amount << " withdrawn from " << this->accountNumber << endl;
	}
	else
	{
		cout << "Error! not enough funds" << endl;
	}
}
void BankAccount::setAccountNumber(string no){
	this->accountNumber=no;
}
void BankAccount::deposit(int amount)
{
	this->balance = (this->balance) + amount;
	updateBalance();
	cout << "$" << amount << " deposited into " << this->accountNumber << endl;
}

int BankAccount::getBalance() 
{
	return this->balance;
}

bool BankAccount::updateBalance()
{
	// Change some variables in database
	return true;
}

// class BankAccount
// {
//   public:
// 	BankAccount();
// 	~BankAccount();

// 	void withdraw(int amount)
// 	{
// 		this->balance = (this->balance) - amount;
// 		updateBalance();
// 	}

// 	void deposit(int amount)
// 	{
// 		this->balance = (this->balance) + amount;
// 		updateBalance();
// 	}

// 	int getBalance()
// 	{
// 		return this->balance;
// 	}

// 	bool updateBalance()
// 	{
// 		// Change balance in database
// 	}
// };
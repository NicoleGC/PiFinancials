#ifndef LOAN_H
#define LOAN_H 

#include <iostream>
#include <string>
#include <vector>


class Loan
{
public:
	Loan(std::string inputtedAccountNumber, int amount);
	int getAmount();
	std::string getStatus();
    std::string getAccountNumber();
	bool approve();
    bool deny();    
    bool operator ==(Loan) const;

private:
	std::string accountNumber;
    std::string status;
	int amount;
};

#endif


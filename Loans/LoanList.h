#ifndef LOANLIST_H
#define LOANLIST_H 

#include <iostream>
#include <string>
#include <vector>
#include "Loan.h"


class LoanList
{
public:
	LoanList();
	void addLoanToList(Loan);
    std::vector<Loan> getLoans();
    void approveLoan(Loan);
    void denyLoan(Loan);

private:
    std::vector<Loan> loans;
};

#endif


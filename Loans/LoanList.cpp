#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include "operations.cpp"
#include "Loan.h"
#include "LoanList.h"
#include "../BankAccount/BankAccount.h"


LoanList::LoanList()
{
	//todo - pull loans list from db
};

void LoanList::addLoanToList(Loan newLoan) {
    loans.push_back(newLoan);
    //todo - save loans list to db
}

std::vector<Loan> LoanList::getLoans() {
    return loans;
}

void LoanList::approveLoan(Loan loan) {
    loan.approve();
}

void LoanList::denyLoan(Loan loan) {
    loan.deny();
    loans.erase(std::remove(loans.begin(), loans.end(), loan), loans.end());
    //todo - save loans list to db
}

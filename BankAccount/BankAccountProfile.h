#pragma once

#ifndef BANK_ACCOUNT_PROFILE_H 
#define BANK_ACCOUNT_PROFILE_H

#include <iostream>
#include <string>
#include <vector>
#include "BankAccount.h"
#include "../login/AuthenticationToken.h"

class BankAccountProfile
{
public:
	BankAccountProfile();
	BankAccountProfile(std::string profileID, std::string firstName, std::string lastName);
	~BankAccountProfile();

	std::string getAccountNumber();
	std::string getFirstName();
	std::string getLastName();
	std::string getBirthDate();
	std::string getHomePhoneNumber();
	std::string getCellPhoneNumber();
	std::string getEmailAddress();
	std::string getHomeAddress1();
	std::string getHomeAddress2();
	std::string getPostalCode();
	std::string getSIN();
	std::string getStatusInCountry();
	BankAccount getListOfAccounts();
	AuthenticationToken* getAuthToken();
	void  setAccountNumber(std::string AccountNumber);
	void  setFirstName(std::string firstName);
	void  setLastName(std::string lastName);
	void  setBirthDate(std::string birthDate);
	void  setHomePhoneNumber(std::string homePhoneNumber);
	void  setCellPhoneNumber(std::string cellPhoneNumber);
	void  setEmailAddress(std::string emailAddress);
	void  setHomeAddress1(std::string homeAddress1);
	void  setHomeAddress2(std::string homeAddress2);
	void  setPostalCode(std::string postalCode);
	void  setSIN(std::string SIN);
	void  setStatusInCountry(std::string statusInCountry);
	void  setListOfAccounts(BankAccount acc);
	void  setAuthToken(AuthenticationToken* authToken);
		
protected:

	std::string profileID;
	std::string firstName;
	std::string lastName;
	std::string birthDate;
	std::string homePhoneNumber;
	std::string cellPhoneNumber;
	std::string emailAddress;
	std::string homeAddress1;
	std::string homeAddress2;
	std::string postalCode;
	std::string SIN;
	std::string statusInCountry;
	BankAccount listOfAccount;
	AuthenticationToken* authToken;
	
};

// BankAccountProfile::BankAccountProfile()
// {
// }

// BankAccountProfile::~BankAccountProfile()
// {
// }


#endif // !BankAccountProfile

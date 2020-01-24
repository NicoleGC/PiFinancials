#include <iostream>
#include <string>
#include <vector>
// #include "BankAccount.cpp"
#include "BankAccount.h"
#include "../login/AuthenticationToken.h"
#include "BankAccountProfile.h"

using namespace std;

BankAccountProfile::BankAccountProfile() 
{
	this->profileID = "";
	this->firstName = "";
	this->lastName = "";
	this->birthDate = "";
	this->homePhoneNumber = "";
	this->cellPhoneNumber = "";
	this->emailAddress = "";
	this->homeAddress1 = "";
	this->homeAddress2 = "";
	this->postalCode = "";
	this->SIN = "";
	this->statusInCountry = "";
	this->listOfAccount = { };
	authToken = NULL;
}

BankAccountProfile::BankAccountProfile(string profileID, string firstName, string lastName) {
	this->profileID = profileID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->birthDate = "";
	this->homePhoneNumber = "";
	this->cellPhoneNumber = "";
	this->emailAddress = "";
	this->homeAddress1 = "";
	this->homeAddress2 = "";
	this->postalCode = "";
	this->SIN = "";
	this->statusInCountry = "";
	this->listOfAccount = {"0" };
	authToken = NULL;
	

}

BankAccountProfile::~BankAccountProfile() {};

string BankAccountProfile::getAccountNumber() 
{
	return this->profileID;
};

string BankAccountProfile::getFirstName() 
{
	return this->firstName;
};

string BankAccountProfile::getLastName() 
{
	return this->lastName;
};

string BankAccountProfile::getBirthDate()
{
	return this->birthDate;
};

string BankAccountProfile::getHomePhoneNumber()
{
	return this->homePhoneNumber;
};

string BankAccountProfile::getCellPhoneNumber()
{
	return this->cellPhoneNumber;
};

string BankAccountProfile::getEmailAddress()
{
	return this->emailAddress;
};

string BankAccountProfile::getHomeAddress1()
{
	return this->homeAddress1;
};

string BankAccountProfile::getHomeAddress2()
{	
	return this->homeAddress2;
};

string BankAccountProfile::getPostalCode()
{
	return this->postalCode;
};

string BankAccountProfile::getSIN()
{
	return this->SIN;
};

string BankAccountProfile::getStatusInCountry()
{
	return this->statusInCountry;
};
BankAccount BankAccountProfile::getListOfAccounts()
{
	return this->listOfAccount;
}

AuthenticationToken* BankAccountProfile::getAuthToken()
{
	return this->authToken;
}

void BankAccountProfile::setAccountNumber(string profileID)
{
	this->profileID = profileID;
};

void BankAccountProfile::setFirstName(string firstName)
{
	this->firstName = firstName;
};

void BankAccountProfile::setLastName(string lastName)
{
	this->lastName = lastName;
};

void BankAccountProfile::setBirthDate(string birthDate)
{
	this->birthDate = birthDate;
};

void BankAccountProfile::setHomePhoneNumber(string homePhoneNumber)
{
	this->homePhoneNumber = homePhoneNumber;
};

void BankAccountProfile::setCellPhoneNumber(string cellPhoneNumber)
{
	this->cellPhoneNumber = cellPhoneNumber;
};

void BankAccountProfile::setEmailAddress(string emailAddress) 
{
	this->emailAddress = emailAddress;
};

void BankAccountProfile::setHomeAddress1(string homeAddress1)
{
	this->homeAddress1 = homeAddress1;
};

void BankAccountProfile::setHomeAddress2(string homeAddress2)
{
	this->homeAddress2 = homeAddress2;
};

void BankAccountProfile::setPostalCode(string postalCode)
{
	this->postalCode = postalCode;
};

void BankAccountProfile::setSIN(string SIN)
{
	this->SIN = SIN;
};

void BankAccountProfile::setStatusInCountry(string statusInCountry)
{
	this->statusInCountry = statusInCountry;
};

void BankAccountProfile::setListOfAccounts(BankAccount listOfAccount)
{
	this->listOfAccount = listOfAccount;
};

void BankAccountProfile::setAuthToken(AuthenticationToken* inputAuthToken)
{
	authToken = inputAuthToken;
};


#pragma once

#ifndef REGISTER_MANAGER_H
#define REGISTER_MANAGER_H

#include <string>
#include <vector>
#include "../BankAccount/BankAccountProfile.h"




class RegisterManager {
public:
	RegisterManager();
	~RegisterManager();
    std::vector<std::string> displayListOfEmployees();
    std::vector<std::string> displayListOfCustomers();
	std::vector<std::string> getUserInfo();
	BankAccountProfile* createBankProfile(std::string ID, std::string name, std::string lastName, std::string bday, std::string hp, std::string cp, std::string em, std::string ha1, std::string ha2, std::string pc, std::string s, std::string ctz);
	std::string generateID(); 
	std::string generateAccountNumber();
    void RemoveEmployee(std::string id);
    void RemoveCustomer(std::string id);
	void updateInformation(std::string name, std::string lastName, std::string bday, std::string hp, std::string cp, std::string em, std::string ha1, std::string ha2, std::string pc, std::string s, std::string ctz);

};
#endif

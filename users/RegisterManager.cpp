
#include <iostream>
#include "RegisterManager.h"
#include "systemUser.h"
#include "employeeUser.h"
#include "customerUser.h"
#include "Registrar.h"
#include "../BankAccount/BankAccountProfile.h"
#include "RegisterManager.h"
#include <vector>


using namespace std;


	RegisterManager::RegisterManager (){}
	RegisterManager::~RegisterManager() {}
	vector<string> RegisterManager::displayListOfEmployees(){
		//call a function in one of our classes that returns a vector or some kind of list of employee users (id, name)

	}
	vector<string> RegisterManager::displayListOfCustomers(){
		//call a function in one of our classes that returns a vector or some kind of list of customer users (id, name)

	}

	void RegisterManager::RemoveEmployee(string id) {
		//call a function in one of our classes that searches the db and removes user with this id.

	}


	void RegisterManager::RemoveCustomer(string id) {
		//call a function in one of our classes that searches the db and removes user and bank account with this id.

	}
		
	BankAccountProfile* RegisterManager::createBankProfile(string ID, string name, string lastName,string bday, string hp, string cp,string em, string ha1, string ha2, string pc, string s, string ctz){
		BankAccountProfile* newProfile = new BankAccountProfile(ID, name, lastName);
		newProfile->setBirthDate(bday);
		newProfile->setHomePhoneNumber(hp);
		newProfile->setCellPhoneNumber(cp);
		newProfile->setEmailAddress(em);
		newProfile->setHomeAddress1(ha1);
		newProfile->setHomeAddress2(ha2);
		newProfile->setPostalCode(pc);
		newProfile->setSIN(s);
		newProfile->setStatusInCountry(ctz);
		return newProfile;

	}
	string RegisterManager::generateID() {
		srand(time(NULL));
		 
		int randomID = std::rand();
		string ss =std::to_string(randomID);
		return ss;
	}
		string RegisterManager::generateAccountNumber() {
		srand(time(NULL));
		 
		int randomID = std::rand();
		string ss =std::to_string(randomID);
		return ss;
	}

	void updateInformation(std::string name, std::string lastName, std::string bday, std::string hp, std::string cp, std::string em, std::string ha1, std::string ha2, std::string pc, std::string s, std::string ctz) {
		
		/*newProfile->setName(name);
		newProfile->setLastName(lastName);
		newProfile->setBirthDate(bday);
		newProfile->setHomePhoneNumber(hp);
		newProfile->setCellPhoneNumber(cp);
		newProfile->setEmailAddress(em);
		newProfile->setHomeAddress1(ha1);
		newProfile->setHomeAddress2(ha2);
		newProfile->setPostalCode(pc);
		newProfile->setSIN(s);
		newProfile->setStatusInCountry(ctz);*/
	}
	std::vector<std::string> getUserInfo(){
	
		/*vector<string> info;
		info.push_back(newProfile.getFirstName());
		info.push_back(newProfile.getLastName());
		info.push_back(newProfile.getBirthDate());
		info.push_back(newProfile.getHomePhoneNumber());
		info.push_back(newProfile.getCellPhoneNumber());
		info.push_back(newProfile.getEmailAddress());
		info.push_back(newProfile.getHomeAddress1());
		info.push_back(newProfile.getHomeAddress2());
		info.push_back(newProfile.getPostalCode());
		info.push_back(newProfile.getSIN());
		info.push_back(newProfile.getStatusInCountry());*/
		
	}
	

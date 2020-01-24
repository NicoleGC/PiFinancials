#include "LoginServer.h"
#include "AuthenticationToken.h"
#include "LoggedInUserFactory.h"
// #include "../users/systemUser.h"
#include "../users/ModelRegister.h"
#include "../users/Registrar.h"
#include <map>
#include <iostream>
using namespace std;

LoginServer *LoginServer::instance = NULL;

LoginServer::LoginServer()
{
	//populate list of all users currently logged in (aka nobody)
	LoggedInUsers = new map<string, AuthenticatedUser*>();
	instance = NULL;
}

LoginServer *LoginServer::getServer()
{
	if (instance == NULL)
	{
		instance = new LoginServer();
	}
	return instance;
}

int LoginServer::verifyUser(std::string ID, std::string password, std::map<std::string, systemUser *> mapInput)
{

	std::map<std::string, systemUser *>::iterator it = mapInput.find(ID);
	// for (map<std::string, systemUser *>::iterator it = mapInput.begin(); it != mapInput.end(); ++it)
	// {
	// 	systemUser *user = it->second;
	// 	string userID = it->first;
	// 	cout << "Running iteration" << endl;
	// 	cout << "User id is " << userID << " and name is " << user->firstName() << " " << user->lastName() << " and my password is " << user->password() << endl;
	// }
	if (it == mapInput.end())
	{
		// cout << "Not found in map" << endl;
		return -1;
	}

	// cout << "Pls get here" << std::endl;
	// cout << "Password is supposed to be this : " << ((mapInput.at(ID))->password());
	if ((it->second->password()).compare(password) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	// bool IDflag;
	// bool pswdFlag;

	// std::map<string, systemUser*>::iterator it = mapInput.find(ID);
	// //check for ID first
	// cout << (it->second)->firstName() << " " << (it->second)->lastName() << endl;

	// if (it != mapInput.end()){
	// 	IDflag = true;
	// 	}
	// else {
	// 	IDflag = false;
	// }
	// //if we found the user ID on our records, see if the password matches ID
	// if (IDflag == true){
	// 	if (password == (mapInput.at(ID))->password()) {
	// 		pswdFlag = 1;
	// 	}
	// }

	// //return appropriate value depending on flags
	// if ((IDflag == true) && (pswdFlag == true)) {
	// 	return 1;
	// }
	// else if (IDflag == true && pswdFlag == false) {
	// 	return -1;
	// }
	// else if (IDflag == false) {
	// 	return 0;
	// }
}
void changePswd(string changeIt){
	
}
AuthenticatedUser *LoginServer::loginUser(std::string ID, std::string password, std::map<std::string, systemUser *> mapInput)
{
	//create a factory for logged in users

	LoggedInUserFactory *loggedIn = new LoggedInUserFactory();
	map<std::string, systemUser*>::iterator finder;
	
	int check = verifyUser(ID, password, mapInput);

	// cout << "Value of check is " << check << endl;
	if (check == 0)
	{
		cout << "Incorrect Password!" << endl;
		return NULL;
	}
	else if (check == -1)
	{
		cout << "No user with that ID in the system" << endl;
		return NULL;
	}
	if (check == 1)
	{
		//cout << "Here 1" << endl;
		AuthenticationToken *generatedToken = new AuthenticationToken();
		
		//cout << "Here 2" << endl;
		generatedToken->setTokenID(ID);
		//cout << "Here 3" << endl;
		//generatedToken->setTypeOfUser(mapInput.at(ID)->getUserType());
	    finder = mapInput.find(ID);	
		generatedToken->setTypeOfUser((finder->second)->getUserType());
		// generatedToken->setTypeOfUser(ModelRegister::getInstance()->getRegisteredUser(ID)->getUserType());
		//cout << "Here 4" << endl;
		//cout << "token infor is " << generatedToken->getUserType();
		AuthenticatedUser *person = loggedIn->create(generatedToken);
		finder = mapInput.find(ID);
		string name= finder->second->firstName();
		string lastName = finder->second->lastName();
			person->setName(name);
		person->setLastName(lastName);
		if (person == NULL) {
			cout << "error creating user, factory returned null" << endl;
		}
		else {
			//cout << "the name is: " << person->getName() << endl;
			//cout << "Here 5" << endl;
			std::pair<string, AuthenticatedUser*>(ID, person);
			LoggedInUsers->insert(std::pair<string, AuthenticatedUser*>(ID, person));
			//LoggedInUsers[ID] = person;
			//cout << "Here 6" << endl;

	/*for (map<std::string, AuthenticatedUser*>::iterator iter = LoggedInUsers->begin(); iter != LoggedInUsers->end(); ++iter)
			{
			AuthenticatedUser* user = iter->second;
			string userID = iter->first;
			cout << "Running iteration" << endl;
			cout << "User id is " << userID << " and name is " << user->getName() << " " << user->getLastName() << endl;
		}*/
			return person;
	
		}
	}
}

LoginServer::~LoginServer()
{
}

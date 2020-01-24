#pragma once

#ifndef LOGIN_SERVER_H
#define LOGIN_SERVER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "AuthenticatedUser.h"
#include "../users/systemUser.h"
class LoginServer
{
private:
	//will contain a vector of all users that have a profile in our system
	// std::map<std::string, systemUser*> mapInput;
	//will contain a vector of all users that are currently logged in the system
	std::map<std::string, AuthenticatedUser*> * LoggedInUsers;
protected:
	static LoginServer* instance;
	
	//singleton constructor
	LoginServer();

public:
	static LoginServer* getServer();
	~LoginServer();
	int verifyUser(std::string ID, std::string password, std::map<std::string, systemUser*> mapInput);
	int verifyUser(std::string ID);
	AuthenticatedUser* loginUser(std::string ID, std::string password, std::map<std::string, systemUser*> mapInput);
	void changePswd(std::string changeIt);
};

#endif // !LoginServer
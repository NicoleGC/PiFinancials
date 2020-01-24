#pragma once

#ifndef LOGGEDIN_CLIENT_H
#define LOGGEDIN_CLIENT_H

#include "AuthenticatedUser.h"
#include "AuthenticationToken.h"
#include <string>
class LoggedInClient: public AuthenticatedUser
{
private:
	std::string name;
	std::string lastName;
	std::string ID;
	AuthenticationToken* theToken;
public:
	
	std::string getName();
	std::string getLastName();
	std::string getID();
	AuthenticationToken* getToken();
	void setTokenID(std::string id);
	void setName(std::string name);
	void setLastName(std::string lastName);
	void setToken(AuthenticationToken* token);

	
};

#endif // !LoggedInClient
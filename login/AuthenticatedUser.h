#pragma once

#ifndef AUTHENTICATED_USER_H
#define AUTHENTICATED_USER_H
#include <string>

#include "AuthenticationToken.h"
class AuthenticatedUser
{
public:
	 /*std::string getName() { }
	std::string getLastName{ }
	std::string getID() {  }
	void setTokenID(std::string id) { }
	void setName(std::string name) {  }
	void setLastName(std::string lastName) {}
	void setToken(AuthenticationToken* token) { }*/
	
	virtual std::string getName() = 0;
	virtual std::string getLastName() = 0;
	virtual std::string getID() = 0;
	virtual AuthenticationToken* getToken() =0;
	virtual void setTokenID(std::string id) = 0;
	virtual void setName(std::string name) = 0;
	virtual void setLastName(std::string lastName) = 0;
	virtual void setToken(AuthenticationToken* token) = 0;

};

#endif // !AuthenticatedUser
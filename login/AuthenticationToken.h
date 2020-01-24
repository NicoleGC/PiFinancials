#pragma once

#ifndef AUTHENTICATION_TOKEN_H
#define AUTHENTICATION_TOKEN_H

#include <string>

class AuthenticationToken
{
private: 
	std::string typeOfUser;
	std::string tokenID;
public:

	AuthenticationToken();
	~AuthenticationToken();
	void setTypeOfUser(std::string type);
	std::string getUserType();
	void setTokenID(std::string id);
	std::string getTokenID();

};

#endif // !AuthenticatedToken
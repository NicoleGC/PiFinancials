#include "LoggedInUserFactory.h"
#include "../users/ModelRegister.h"
#include <iostream>

using namespace std;
LoggedInUserFactory::LoggedInUserFactory()
{
}

AuthenticatedUser* LoggedInUserFactory::create(AuthenticationToken* token)
{
	if ((token->getUserType()).compare("Customer") == 0) {
		return createAuthClient(token);
	} else if ((token->getUserType()).compare("Employee") == 0) {
		return createAuthEmpl(token);
	}
	else if ((token->getUserType()).compare("Administrator") == 0) {
		return createAuthEmpl(token);
	}
	return NULL;
}

AuthenticatedUser* LoggedInUserFactory::createAuthClient(AuthenticationToken* token)
{
	AuthenticatedUser* client = new LoggedInClient();
	std::string id = token->getTokenID();
	client->setTokenID(id);
	client->setToken(token);
	//cout << "testing sup" << endl;
	
	//cout << "name is: " << name << endl;
	//client->setName(ModelRegister::getInstance()->getRegisteredUser(id)->firstName());
	//client->setLastName(ModelRegister::getInstance()->getRegisteredUser(id)->lastName());
	return client;
}

AuthenticatedUser* LoggedInUserFactory::createAuthEmpl(AuthenticationToken* token)
{
	AuthenticatedUser* employee = new LoggedInEmployee();
	std::string id = token->getTokenID();
	employee->setTokenID(id);
	employee->setToken(token);
	
	//employee->setName(ModelRegister::getInstance()->getRegisteredUser(id)->firstName());
	//employee->setLastName(ModelRegister::getInstance()->getRegisteredUser(id)->lastName());
	return employee;
}
AuthenticatedUser* LoggedInUserFactory::createAuthAdmin(AuthenticationToken* token)
{
	AuthenticatedUser* admin = new LoggedInAdmin;
	std::string id = token->getTokenID();
	admin->setTokenID(id);
	admin->setToken(token);
	
	//admin->setName(ModelRegister::getInstance()->getRegisteredUser(id)->firstName());
	//admin->setLastName(ModelRegister::getInstance()->getRegisteredUser(id)->lastName());
	return admin;
}


LoggedInUserFactory::~LoggedInUserFactory()
{
}

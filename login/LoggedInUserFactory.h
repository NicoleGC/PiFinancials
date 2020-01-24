#pragma once

#ifndef LOGGEDIN_USER_FACTORY_H
#define LOGGEDIN_USER_FACTORY_H

#include "AuthenticationToken.h"
#include "LoggedInClient.h"
#include "AuthenticatedUser.h"
#include "LoggedInEmployee.h"
#include "LoggedInAdmin.h"
class LoggedInUserFactory
{
public:
	LoggedInUserFactory();
	AuthenticatedUser* create(AuthenticationToken* token);
	AuthenticatedUser* createAuthClient(AuthenticationToken* token);
	AuthenticatedUser* createAuthEmpl(AuthenticationToken* token);
	AuthenticatedUser* createAuthAdmin(AuthenticationToken* token);
	~LoggedInUserFactory();
};

#endif // !LoggedInUserFactory
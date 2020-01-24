#include "LoggedInAdmin.h"
#include "AuthenticatedUser.h"
#include <string>

using namespace std;

string LoggedInAdmin::getName() {
	return name;
}
string LoggedInAdmin::getLastName() {
	return lastName;
}
string LoggedInAdmin::getID() {
	return ID;
}
AuthenticationToken* LoggedInAdmin::getToken() {
	
	return theToken;
}

void LoggedInAdmin::setTokenID(std::string id) {
	ID = id;
}
void LoggedInAdmin::setName(std::string name) {
	this->name = name;
}
void LoggedInAdmin::setLastName(std::string lastName) {
	this->lastName = lastName;
}
void LoggedInAdmin::setToken(AuthenticationToken* token) {
	theToken = token;
}

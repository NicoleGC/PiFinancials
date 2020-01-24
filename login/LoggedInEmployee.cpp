#include "LoggedInEmployee.h"
#include "AuthenticatedUser.h"
using namespace std;
std::string LoggedInEmployee::getName() {
	return name;
}
std::string LoggedInEmployee::getLastName() {
	return lastName;
}
std::string LoggedInEmployee::getID() {
	return ID;
}
AuthenticationToken* LoggedInEmployee::getToken(){
	return theToken;
}

void LoggedInEmployee::setTokenID(std::string id) {
	ID = id;
}
void LoggedInEmployee::setName(std::string name) {
	this->name = name;
}
void LoggedInEmployee::setLastName(std::string lastName) {
	this->lastName = lastName;
}
void LoggedInEmployee::setToken(AuthenticationToken* token) {
	theToken = token;
}

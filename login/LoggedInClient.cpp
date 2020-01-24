#include "LoggedInClient.h"
#include "AuthenticatedUser.h"
#include <string>

using namespace std;

string LoggedInClient::getName() {
	return name;
}
string LoggedInClient::getLastName() {
	return lastName;
}
string LoggedInClient::getID() {
	return ID;
}
AuthenticationToken* LoggedInClient::getToken(){
	return theToken;
}

void LoggedInClient::setTokenID(std::string id) {
	ID = id;
}
void LoggedInClient::setName(std::string name) {
	this->name = name;
}
void LoggedInClient::setLastName(std::string lastName) {
	this->lastName = lastName;
}
void LoggedInClient::setToken(AuthenticationToken* token) {
	theToken = token;
}

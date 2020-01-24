#include "AuthenticationToken.h"
using namespace std;
AuthenticationToken::AuthenticationToken() {
	typeOfUser = "/0";
	tokenID = "/0";
}
void AuthenticationToken::setTypeOfUser(string type) {
	typeOfUser = type;
}
string AuthenticationToken::getUserType() {
	return typeOfUser;
}
void AuthenticationToken::setTokenID(string id) {
	tokenID = id;
}
string AuthenticationToken::getTokenID() {
	return tokenID;
}
AuthenticationToken::~AuthenticationToken()
{

}
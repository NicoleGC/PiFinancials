#include <iostream>
#include "../login/LoginServer.h"
#include "LoginManager.h"


using namespace std;


string LoginManager::login(std::string id, std::string password,std::map<std::string, systemUser*> mapInput ) {

	LoginServer *server = LoginServer::getServer();
	AuthenticatedUser *authUser = server->loginUser(id, password, mapInput);
	string userType = (authUser->getToken())->getUserType();
	return userType; 
}
    bool LoginManager::changePassword(std::string changeIt){
	/*LoginServer *server = LoginServer::getServer();
	server->changePswd(changeIt);
	return true;*/
	
}


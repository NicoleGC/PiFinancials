#pragma once

#ifndef LOGIN_MANAGER_H
#define LOGIN_MANAGER_H

#include <string>
class LoginManager {
public:
	std::string login(std::string id, std::string password, std::map<std::string, systemUser*> mapInput);
    bool changePassword(std::string changeIt);

};



#endif

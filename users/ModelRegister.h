#pragma once

#ifndef MODEL_REGISTER_H
#define MODEL_REGISTER_H

#include "systemUser.h"
#include <map>
#include <string>

class ModelRegister 
{
    public:
        ModelRegister();
        static ModelRegister* getInstance();
		bool userAlreadyExists(std::string id, ModelRegister* reg);
        systemUser* getRegisteredUser(std::string profileID);
		std::map<std::string, systemUser*>* registrar;
	protected:
        static ModelRegister* instance;
        
};

#endif
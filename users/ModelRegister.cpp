#include "systemUser.h"
#include "ModelRegister.h"
#include <string>

using namespace std;

ModelRegister *ModelRegister::instance = NULL;

ModelRegister::ModelRegister()
{
    registrar = new map<std::string, systemUser*>();
    instance = NULL;
}

ModelRegister* ModelRegister::getInstance() 
{
    if (instance == NULL) 
    {
        instance = new ModelRegister();
    }
    return instance;
}

systemUser* ModelRegister::getRegisteredUser(string profileID)
{
	std::map<string, systemUser*>::iterator it= registrar->find(profileID);
    systemUser *userPtr = it->second;
    return userPtr;
}
bool userAlreadyExists(string id, ModelRegister* inst) {
	std::map<string, systemUser*>::iterator it;
		
		it = inst->registrar->find(id);
	if (it ==inst->registrar->end()){
		return false;
		}
	else return true;
}
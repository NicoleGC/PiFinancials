#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <string>
#include "systemUser.h"

class Registrar
{
  public:
    systemUser* admitUser(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password);
  
  protected:
    virtual systemUser* createUser(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password) = 0;
};

#endif

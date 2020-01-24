#ifndef ADMIN_REGISTRAR_H
#define ADMIN_REGISTRAR_H

#include <string>
#include "adminUser.h"

class adminRegistrar : public Registrar
{
  public:
    virtual systemUser* createUser(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password)
    {
      return new adminUser(ID, firstName, lastName, password);
    }
};

#endif


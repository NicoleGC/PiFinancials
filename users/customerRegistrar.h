#ifndef CUSTOMER_REGISTRAR_H
#define CUSTOMER_REGISTRAR_H

#include <string>
#include "customerUser.h"

class customerRegistrar : public Registrar
{
  public:
    virtual systemUser* createUser(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password)
    {
      return new customerUser(ID, firstName, lastName, password);
    }
};

#endif


#ifndef EMPLOYEE_REGISTRAR_H
#define EMPLOYEE_REGISTRAR_H

#include <string>
#include "employeeUser.h"

class employeeRegistrar : public Registrar
{
  public:
    virtual systemUser* createUser(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password)
    {
      return new employeeUser(ID, firstName, lastName, password);
    }
};

#endif


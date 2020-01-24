#ifndef EMPLOYEE_USER_H
#define EMPLOYEE_USER_H

#include <iostream>
#include <string>
#include "systemUser.h"

class employeeUser : public systemUser
{
  public:
    employeeUser(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password) : systemUser(ID, firstName, lastName, password)
    {
    }

    std::string getUserType() {
        return "Employee";
    }
};

#endif

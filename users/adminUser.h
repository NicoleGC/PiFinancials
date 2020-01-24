#ifndef ADMIN_USER_H
#define ADMIN_USER_H

#include <iostream>
#include <string>
#include "systemUser.h"

class adminUser : public systemUser
{
  public:
    adminUser(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password) : systemUser(ID, firstName, lastName, password)
    {
    }

    std::string getUserType() {
        return "Administrator";
    }
};

#endif

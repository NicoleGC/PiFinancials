#ifndef CUSTOMER_USER_H
#define CUSTOMER_USER_H

#include <iostream>
#include <string>
#include "systemUser.h"

class customerUser : public systemUser
{
  public:
    customerUser(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password) : systemUser(ID, firstName, lastName, password)
    {
    }

    std::string getUserType() {
        return "Customer";
    }
};

#endif

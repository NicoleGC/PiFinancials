#ifndef SYSTEM_USER_H
#define SYSTEM_USER_H

#include <string>

class systemUser
{
  public:
    systemUser(const std::string ID, const std::string firstName, const std::string lastName, const std::string password) : _ID(ID), _firstName(firstName), _lastName(lastName), _password(password) {}

    const std::string& ID() const { return this->_ID; }
    const std::string& firstName() const { return this->_firstName; }
    const std::string& lastName() const { return this->_lastName; }
    const std::string& password() const { return this->_password; }


    virtual std::string getUserType()=0;
    
  private:
    std::string _ID;
    std::string _firstName;
    std::string _lastName;
    std::string _password;
};

#endif

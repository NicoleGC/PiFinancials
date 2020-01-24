#include <iostream>
#include <string>
#include "Registrar.h"
#include "systemUser.h"


using std::cout;
using std::endl;
using std::string;

systemUser * Registrar::admitUser(const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& password)
{

  systemUser *s = this->createUser(ID, firstName, lastName, password);

  // cout << "Created " << s->getUserType() << " " << s->ID() << " " << s->firstName() << " " << s->lastName() << endl;
  
  // Each student type has its own admission operations
//   s->welcome();
//   s->invoiceTuition();
//   s->createTranscript();

  cout << endl;

  return s;
}

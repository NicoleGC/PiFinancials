#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "../users/Registrar.h"

#include "../users/adminRegistrar.h"
#include "../users/employeeRegistrar.h"
#include "../users/customerRegistrar.h"

#include "../users/systemUser.h"

#include "../BankAccount/AccountTransactionManager.h"
#include "../BankAccount/BankAccount.h"
#include "../BankAccount/BankAccountProfile.h"

#include "../login/LoginServer.h"
#include "../login/AuthenticationToken.h"

#include "../users/ModelRegister.h"
#include "../users/RegisterManager.h"
#include "../login/LoginManager.h"

#include "../Loans/Loan.h"
#include "../Loans/LoanList.h"


/* #include "../Database/sql.cpp" */

using namespace std;
struct data {

	string firstName, lastName, birthDate, homePhoneNum, cellPhoneNum, emailAddr, homeAddr1, homeAddr2, postalCode, SIN, statusInCountry;
};
map<std::string, systemUser *> addUsers(map<string, Registrar *> &registrars, map<std::vector<string>, string> usersToCreate, map<std::string, systemUser *> mapInput)
{
  for (map<std::vector<string>, string>::iterator it = usersToCreate.begin(); it != usersToCreate.end(); ++it)
  {
    Registrar *registrar = registrars[it->second];
    vector<string> stringList = (it->first);
    vector<string>::iterator strItr = stringList.begin();
    systemUser *userThatSaysYeet = registrar->admitUser(*strItr, (*strItr++), (*strItr++), (*strItr++));
    //mapInput[userThatSaysYeet->ID()] = userThatSaysYeet;
    std::pair<std::map<string, systemUser *>::iterator, bool> result;
    result = mapInput.insert(std::pair<std::string, systemUser *>(userThatSaysYeet->ID(), userThatSaysYeet));
  }

  return mapInput;
}

/****************Global Map******************/
map<string, Registrar *> registrars; //stores 
map<string, BankAccountProfile *> profileMap; //stores all bank profiles
map<string, systemUser *> userMap; //stores all users
map<string,AuthenticatedUser*> loggedInUsers; //stores loggedIn users
/*****************************************/



int main()
{
	LoanList loanList = LoanList();
/***************************create managers********************************/
	RegisterManager *registerManager = new RegisterManager();
	LoginManager *loginManager = new LoginManager();
	AccountTransactionManager *transactionManager = new AccountTransactionManager();
/*************************************************************************/
 
	bool letOthersLogin;


  registrars["admin"] = new adminRegistrar();
  registrars["employee"] = new employeeRegistrar();
  registrars["customer"] = new customerRegistrar();

  map<std::vector<string>, string> usersToCreate;

  std::vector<string> adminInputs;
  std::vector<string> employeeInputs;
  std::vector<string> customerInputs;

  //1 admin
  adminInputs.push_back("password");
  adminInputs.push_back("Jefferson");
  adminInputs.push_back("Jeff");
  adminInputs.push_back("001");

  //1 employee
  employeeInputs.push_back("password");
  employeeInputs.push_back("Bobberson");
  employeeInputs.push_back("Bob");
  employeeInputs.push_back("002");

  //1 customer
  customerInputs.push_back("password");
  customerInputs.push_back("Ali");
  customerInputs.push_back("Mohammad");
  customerInputs.push_back("003");

  usersToCreate[adminInputs] = "admin";
  usersToCreate[employeeInputs] = "employee";
  usersToCreate[customerInputs] = "customer";
  //addthem
  userMap = addUsers(registrars, usersToCreate, userMap);

  // -------------------------------------------------------------------------------------------------------------------------

  LoginServer *server = LoginServer::getServer();
  int  choice;
  bool status = true;
  bool logout = true;
  while (status)
  {
	
	  
		  cout << "Welcome to PiFinancials\nPress" << endl;
		  cout << "1.) Login" << endl;
		  cout << "2.) Exit" << endl;
		  cin >> choice;
	  
	  string firstName;
	  string lastName;
	  string ID;

	  if (choice == 1)
	  {
		  int option;
		  cout << "Welcome Admin" << endl;
		  string userID, password;

		  cout << "Enter id: ";
		  cin >> userID;

		  cout << "Enter password: ";
		  cin >> password;

		  string userType = loginManager->login(userID, password, userMap);
		  /*if (letOthersLogin == false && userType != "Administrator") {
			  cout << "Access denied! Admin has not started system yet" << endl;
			  break;
		  }*/
		  
		  if (userType == "Administrator")
		  {
			  logout=true;
			  while (logout){
			  cout << "**********************************" << endl;
			  cout << "        Administrator Menu        " << endl;
			  cout << "1.) Start the system" << endl;
			  cout << "2.) Stop the system" << endl;
			  cout << "3.) Create Employee Profile" << endl;
			  cout << "4.) Remove Employee Profile" << endl;
			  cout << "5.) Display all Employee Profiles" << endl;
			  cout << "6.) Edit Employee info" << endl;
			  cout << "7.) Print Employee details" << endl;
			  cout << "8.) Logout" << endl;
			  cout << "**********************************" << endl;

			  cin >> option;

			  if (option == 1)
			  {
				  // Turn on system
				  cout << "Starting System.." << endl;
				  letOthersLogin == true;

			  }
			  else if (option == 2)
			  {
				  // Turn off system
				  cout << "Stopping System.." << endl;
				  letOthersLogin = false;
			  }
			  else if (option == 3)
			  {
				  cout << "Creating Employee Profile" << endl;
				  string userID = registerManager->generateID();
				  cout << "Generated ProfileID for employee is " << userID << endl;
				  string password;
				  cout << "Set default password for employee: ";
				  cin.ignore();
				  std::getline(std::cin, password);

				  //ask the questions

				  //string firstName, lastName;
				  //string birthDate, homePhoneNum, cellPhoneNum, emailAddr, homeAddr1, homeAddr2, postalCode, SIN, statusInCountry;
				  data *d = new data;
				  cout << "Enter first name: " << endl;
				  //cin >> firstName;
				  getline(cin, d->firstName);
				  cout << "Enter last name: " << endl;
				  // cin >> lastName;
				  getline(cin, d->lastName);
				  cout << "Enter birthDate:  (mm-dd-yy)";
				  //cin >> birthDate;
				  getline(cin, d->birthDate);


				  cout << "Enter homePhoneNumber: ";
				  //cin >> homePhoneNum;
				  getline(cin, d->homePhoneNum);

				  cout << "Enter cellPhoneNumber: ";
				  //cin >> cellPhoneNum;
				  getline(cin, d->cellPhoneNum);

				  cout << "Enter emailAddress: ";
				  //cin >> emailAddr;
				  getline(cin, d->emailAddr);

				  cout << "Enter homeAddress1: ";
				  getline(cin, d->homeAddr1);

				  cout << "Enter homeAddress2: ";
				  // cin >> homeAddr2;
				  getline(cin, d->homeAddr2);

				  cout << "Enter postalCode: ";
				  //cin >> postalCode;
				  getline(cin, d->postalCode);

				  cout << "Enter SIN: ";
				  //cin >> SIN;
				  getline(cin, d->SIN);

				  cout << "Enter statusInCountry: ";
				  //cin >> statusInCountry;
				  getline(cin, d->statusInCountry);

				  //create profile and add it to the global map

				  BankAccountProfile* profile = registerManager->createBankProfile(userID, d->firstName, d->lastName, d->birthDate, d->homePhoneNum, d->cellPhoneNum, d->emailAddr, d->homeAddr1, d->homeAddr2, d->postalCode, d->SIN, d->statusInCountry);
				  Registrar *registrar = registrars["employee"];
				  string profAccountNumber = profile->getAccountNumber();
				  //profileMap.insert(userID);
				  profileMap[userID] = profile;
				  //create person and add it to global map
				  systemUser *userThatSaysYeet = registrar->admitUser(userID, firstName, lastName, password);
				  userMap[userID] = userThatSaysYeet;
			  }
			  else if (option == 4)
			  {
				  cout << "Remove Employee" << endl;
				  cout << "Enter profileID of the employee profile you wish to remove: ";
				  string inputProfileID;
				  cin >> inputProfileID;
				  systemUser* userToEdit = userMap.at(inputProfileID);
				  string checkType = userToEdit->getUserType();
				  if (checkType == "Customer") {
					  cout << "Error! Admin can only erase users of type employee" << endl;
				  }
				  else if (checkType == "Administrator") {
					  cout << "Error! Admin can only erase users ot type employee" << endl;
				  }
				  else {
					  userMap.erase(inputProfileID);
					  cout << "User deleted" << endl;
				  }
			  }
			  else if (option == 5)
			  {
				  cout << "Printing List of Employees" << endl;
				  
				  for (map<std::string, BankAccountProfile*>::iterator iter = profileMap.begin(); iter != profileMap.end(); ++iter)
				  {
					  
					  BankAccountProfile* profile= iter->second;
					  
					  string userID = iter->first;
					  systemUser * user = userMap.at(userID);
					  
					 if ((user->getUserType()) == "Employee") {
						// cout <<"user type:"<<user->getUserType();
				
						  if (profile == NULL){
							  cout <<"Error! no employees are registered in the system yet"<<endl;
						  }
						  else {
						  cout << "ID: " << userID << " First Name: " << profile->getFirstName() << " Last name: " << profile->getLastName() << endl;
						  
						  }
					  }
					  
				  }
				  
			  }
			  else if (option == 6) {
				  cout << "Enter profile ID to edit:  ";

				  string profileID;
				  cin >> profileID;
				  systemUser* userToEdit = userMap.at(profileID);
				  if (userToEdit ==NULL){
					  cout <<"No User with that ID in the system"<<endl;
				  }
				  else {
				  string checkType = userToEdit->getUserType();
				  if (checkType == "Customer") {
					  cout << "Error! Admin can only modify users of type employee" << endl;
				  }
				  else if (checkType == "Administrator") {
					  cout << "Error! Admin can only modify users ot type employee" << endl;
				  }
				  else {
					  BankAccountProfile *profile = profileMap.at(profileID);
					  cout << "**********************************" << endl;
					  cout << "        Editing Employee Info        " << endl;
					  cout << "1.) Change first name" << endl;
					  cout << "2.) Change last name" << endl;
					  cout << "3.) Change home phone number" << endl;
					  cout << "4.) Change cell phone number" << endl;
					  cout << "5.) Change email address" << endl;
					  cout << "6.) Change home address #1" << endl;
					  cout << "7.) Change home address #2" << endl;
					  cout << "8.) Change postal code" << endl;
					  cout << "9.) Change status in country" << endl;
					  cout << "10.) Logout" << endl;
					  cout << "**********************************" << endl;
					  int adminOption;
					  cin >> adminOption;
					  if (adminOption == 1)
					  {
						  string inputName;
						  cout << "Enter new first name: ";
						  //cin >> inputName;
						   std::getline(std::cin, inputName);


						  profile->setFirstName(inputName);

						  cout << "First name changed..." << endl;
					  }
					  else if (adminOption == 2)
					  {
						  string lastName;
						  cout << "Enter new last name: ";
						  //cin >> inputName;
						   std::getline(std::cin, lastName);


						  profile->setLastName(lastName);
						  cout << "Last name changed..." << endl;
					  }
					  else if (adminOption == 3)
					  {
						  string inputPhoneNumber;
						  cout << "Enter new home phone number: ";
						  //cin >> inputPhoneNumber;
							 std::getline(std::cin, inputPhoneNumber);

						  profile->setHomePhoneNumber(inputPhoneNumber);
						  cout << "Home phone number changed..." << endl;
					  }
					  else if (adminOption == 4)
					  {
						  string inputPhoneNumber;
						  cout << "Enter new cell phone number: ";
						  //cin >> inputPhoneNumber;
							 std::getline(std::cin, inputPhoneNumber);

						  profile->setCellPhoneNumber(inputPhoneNumber);
						  cout << "Cell phone number changed..." << endl;
					  }
					  else if (adminOption == 5)
					  {
						  string inputEmail;
						  cout << "Enter new email address: ";
						  //cin >> inputEmail;
							 std::getline(std::cin, inputEmail);

						  profile->setEmailAddress(inputEmail);
						  cout << "Email address changed..." << endl;
					  }
					  else if (adminOption == 6)
					  {
						  string inputHomeAddress1;
						  cout << "Enter new home address 1: ";
						  //cin >> inputHomeAddress1;
							 std::getline(std::cin, inputHomeAddress1);

						  profile->setHomeAddress1(inputHomeAddress1);
						  cout << "Home address #1 changed..." << endl;
					  }
					  else if (adminOption == 7)
					  {
						  string inputHomeAddress2;
						  cout << "Enter new home address 2: ";
						  //cin >> inputHomeAddress2;
							 std::getline(std::cin, inputHomeAddress2);

						  profile->setHomeAddress2(inputHomeAddress2);
						  cout << "Home address #2 changed..." << endl;
					  }
					  else if (adminOption == 8)
					  {
						  string inputPostalCode;
						  cout << "Enter new postal code: ";
						 // cin >> inputPostalCode;
						std::getline(std::cin, inputPostalCode);

						  profile->setPostalCode(inputPostalCode);
						  cout << "Postal code changed..." << endl;
					  }
					  else if (adminOption == 9)
					  {
						  string inputSIC;
						  cout << "Enter new status in country: ";
						 // cin >> inputSIC;
							std::getline(std::cin, inputSIC);

						  profile->setStatusInCountry(inputSIC);
						  cout << "Status in country changed..." << endl;
					  }
					  else if (adminOption == 10)
					  {
						  // Logout
						  cout << "Logging out" << endl;
						  break;
					  }
				  }
			  }
			  }
			  if (option == 7) {
				  //print user
				  cout << "Enter employee ID to print their details: " << endl;
				  string profileID;
				  cin >> profileID;
				  systemUser* userToPrint = userMap.at(profileID);
				  string checkType = userToPrint->getUserType();
				  if (checkType == "Customer") {
					  cout << "Error! Admin can only view users of type employee" << endl;
				  }
				  else if (checkType == "Administrator") {
					  cout << "Error! Admin can only view users ot type employee" << endl;
				  }

				  else {
					  BankAccountProfile *profile = profileMap.at(profileID);

					  systemUser* user = userMap.at(profileID);

					  cout << "ID: " << userID << endl;
					  cout << "First Name: " << profile->getFirstName() << endl;
					  cout << "Last name: " << profile->getLastName() << endl;
					  cout << "Birth date: " << profile->getBirthDate() << endl;
					  cout << "Home Phone Number: " << profile->getHomePhoneNumber() << endl;
					  cout << "Cell Phone Number: " << profile->getCellPhoneNumber() << endl;
					  cout << "Email Address: " << profile->getEmailAddress() << endl;
					  cout << "Home Address 1: " << profile->getHomeAddress1() << endl;
					  cout << "Home Address 2: " << profile->getHomeAddress2() << endl;
					  cout << "Postal Code: " << profile->getPostalCode() << endl;
					  cout << "Citizenship Status: " << profile->getStatusInCountry() << endl;
				  }
			  }
			  if (option == 8) {
				  // Logout
				  cout << "Logging out" << endl;
				  logout=false;
				  break;
			  }
			  }

		  }
		  
		  else if (userType == "Employee")
		  {
			  logout =true;
			  while(logout){
			  cout<< "Welcome Employee!"<<endl;
			  int selection;
			  cout << "**********************************" << endl;
			  cout << "        Employee Menu        " << endl;
			  cout << "1.) Create Customer Profile" << endl;
			  cout << "2.) Remove Customer Profile" << endl;
			  cout << "3.) Display Customer Profiles" << endl;
			  cout << "4.) Edit My Profile" << endl;
			  cout << "5.) Edit Customer Profile" << endl;
			  cout << "6.) Customer Transactions" << endl;
			  cout << "7.) Create Customer Bank Account" << endl;
			  cout << "8.) Manage Loan Requests" << endl;
			  cout << "9.) Logout" << endl;
			  cout << "**********************************" << endl;
			  cin >> selection;
			  if (selection == 1) {

				  cout << "Creating Customer Profile" << endl;
				  string userID = registerManager->generateID();
				   
				  cout << "Generated ProfileID for customer is " << userID << endl;
				  string password;
				  
				  cout << "Set default password for customer: " << endl;
				  cin.ignore();
				  std::getline(std::cin, password);

				  //ask the questions

				  //string firstName, lastName;
				  //string birthDate, homePhoneNum, cellPhoneNum, emailAddr, homeAddr1, homeAddr2, postalCode, SIN, statusInCountry;
				  data *d = new data;
				  cout << "Enter first name: " << endl;
				  //cin >> firstName;
				  getline(cin, d->firstName);
				  cout << "Enter last name: " << endl;
				  // cin >> lastName;
				  getline(cin, d->lastName);
				  cout << "Enter birthDate: (mm-dd-yy)";
				  //cin >> birthDate;
				  getline(cin, d->birthDate);


				  cout << "Enter homePhoneNumber: ";
				  //cin >> homePhoneNum;
				  getline(cin, d->homePhoneNum);

				  cout << "Enter cellPhoneNumber: ";
				  //cin >> cellPhoneNum;
				  getline(cin, d->cellPhoneNum);

				  cout << "Enter emailAddress: ";
				  //cin >> emailAddr;
				  getline(cin, d->emailAddr);

				  cout << "Enter homeAddress1: ";
				  getline(cin, d->homeAddr1);

				  cout << "Enter homeAddress2: ";
				  // cin >> homeAddr2;
				  getline(cin, d->homeAddr2);

				  cout << "Enter postalCode: ";
				  //cin >> postalCode;
				  getline(cin, d->postalCode);

				  cout << "Enter SIN: ";
				  //cin >> SIN;
				  getline(cin, d->SIN);

				  cout << "Enter statusInCountry: ";
				  //cin >> statusInCountry;
				  getline(cin, d->statusInCountry);

				  //create profile and add it to the global map

				  BankAccountProfile* profile = registerManager->createBankProfile(userID, d->firstName, d->lastName, d->birthDate, d->homePhoneNum, d->cellPhoneNum, d->emailAddr, d->homeAddr1, d->homeAddr2, d->postalCode, d->SIN, d->statusInCountry);
				  Registrar *registrar = registrars["customer"];
				  string profAccountNumber = profile->getAccountNumber();
				  //profileMap.insert(profAccountNumber);
				  profileMap[userID] = profile;
				  //create person and add it to global map
				  systemUser *userThatSaysYeet = registrar->admitUser(userID, firstName, lastName, password);
				  userMap[userID] = userThatSaysYeet;
			  }
			  else if (selection == 2)
			  {
				  cout << "Enter profileID of the customer profile you wish to remove: ";
				  string inputProfileID;
				  cin >> inputProfileID;
				  systemUser* userToEdit = userMap.at(inputProfileID);
				  if (userToEdit==NULL){
					  cout<<"No user with that ID in the system"<<endl;
					  
				  }
				  else {
				  string checkType = userToEdit->getUserType();
				  
				  if (checkType == "Employee") {
					  cout << "Error! Admin can only modify users of type employee" << endl;
				  }
				  else if (checkType == "Administrator") {
					  cout << "Error! Admin can only modify users ot type employee" << endl;
				  }
				  else {
					  userMap.erase(inputProfileID);
					  cout << "Customer deleted";
				  }
			  }
			  }
			  else if (selection == 3)
			  {
				  cout << "Printing List of Customers" << endl;
				  for (map<std::string, BankAccountProfile*>::iterator iter = profileMap.begin(); iter != profileMap.end(); ++iter)
				  {
					  BankAccountProfile* profile = iter->second;
					  string userID = iter->first;
					  systemUser * user = userMap.at(userID);
					  if ((user->getUserType()) == "customer") {
						  //BankAccountProfile *profile = profileMap.at(userID);
						  if (profile==NULL){
							  cout<<"This customer does not have a profile in the system"<<endl;
						  }
						  else
						  cout << "ID: " << userID << " First Name: " << profile->getFirstName() << " Last name: " << profile->getLastName() << endl;
					  }
				  }
			  }
			  else if (selection == 4)
			  {
				  cout << "Enter profileID of the bank account profile: ";
				  int emOpt;
				  string profileID;

				  cin >> profileID;
				  //BankAccountProfile *profile = new BankAccountProfile(); // Change later when the above line is corrected
				  systemUser* userToEdit = userMap.at(profileID);
				  if (userToEdit == NULL){
					  cout<<"No User with that ID in the system"<<endl;
				  }
				  else {
				  string checkType = userToEdit->getUserType();
				  if (checkType == "Administrator") {
					  cout << "Error! Admin can only modify users ot type employee" << endl;
				  }
				  if (checkType == "Customer") {
					  cout << "Error! ID entered belong to customer, to edit customer select option 5" << endl;
				  }
				  else {
					  cout << "**********************************" << endl;
					  cout << "        Editing Your Info        " << endl;
					  cout << "1.) Change first name" << endl;
					  cout << "2.) Change last name" << endl;
					  cout << "3.) Change home phone number" << endl;
					  cout << "4.) Change cell phone number" << endl;
					  cout << "5.) Change email address" << endl;
					  cout << "6.) Change home address #1" << endl;
					  cout << "7.) Change home address #2" << endl;
					  cout << "8.) Change postal code" << endl;
					  cout << "9.) Change status in country" << endl;
					  cout << "10.) Logout" << endl;
					  cout << "**********************************" << endl;

					  cin >> emOpt;


					  BankAccountProfile *profile = profileMap.at(profileID);


					  if (emOpt == 1)
					  {
						  string inputName;
						  cout << "Enter new first name: ";
						  //cin >> inputName;
								std::getline(std::cin, inputName);

						  profile->setFirstName(inputName);

						  cout << "First name changed..." << endl;
					  }
					  else if (emOpt == 2)
					  {
						  string inputName;
						  cout << "Enter new last name: ";
						  //cin >> inputName;
						   std::getline(std::cin, inputName);


						  profile->setLastName(inputName);
						  cout << "Last name changed..." << endl;
					  }
					  else if (emOpt == 3)
					  {
						  string inputPhoneNumber;
						  cout << "Enter new home phone number: ";
						  //cin >> inputPhoneNumber;
							std::getline(std::cin, inputPhoneNumber);

						  profile->setHomePhoneNumber(inputPhoneNumber);
						  cout << "Home phone number changed..." << endl;
					  }
					  else if (emOpt == 4)
					  {
						  string inputPhoneNumber;
						  cout << "Enter new cell phone number: ";
								//cin >> inputPhoneNumber;
								 std::getline(std::cin, inputPhoneNumber);


						  profile->setCellPhoneNumber(inputPhoneNumber);
						  cout << "Cell phone number changed..." << endl;
					  }
					  else if (emOpt == 5)
					  {
						  string inputEmail;
						  cout << "Enter new email address: ";
						  //cin >> inputEmail;
							 std::getline(std::cin, inputEmail);


						  profile->setEmailAddress(inputEmail);
						  cout << "Email address changed..." << endl;
					  }
					  else if (emOpt == 6)
					  {
						  string inputHomeAddress1;
						  cout << "Enter new home address 1: ";
						  //cin >> inputHomeAddress1;
						   std::getline(std::cin, inputHomeAddress1);


						  profile->setHomeAddress1(inputHomeAddress1);
						  cout << "Home address #1 changed..." << endl;
					  }
					  else if (emOpt == 7)
					  {
						  string inputHomeAddress2;
						  cout << "Enter new home address 2: ";
						  //cin >> inputHomeAddress2;
						   std::getline(std::cin, inputHomeAddress2);


						  profile->setHomeAddress2(inputHomeAddress2);
						  cout << "Home address #2 changed..." << endl;
					  }
					  else if (emOpt == 8)
					  {
						  string inputPostalCode;
						  cout << "Enter new postal code: ";
						  //cin >> inputPostalCode;
						   std::getline(std::cin, inputPostalCode);


						  profile->setPostalCode(inputPostalCode);
						  cout << "Postal code changed..." << endl;
					  }
					  else if (emOpt == 9)
					  {
						  string inputSIC;
						  cout << "Enter new status in country: ";
						  //cin >> inputSIC;
						   std::getline(std::cin, inputSIC);


						  profile->setStatusInCountry(inputSIC);
						  cout << "Status in country changed..." << endl;
					  }
					  else if (emOpt == 10)
					  {
						  // Logout
						  cout << "Logging out" << endl;
						  break;
					  }
				  }
				}
			  }
			  else if (selection == 5)
			  {
				  cout << "Enter profileID of the bank account profile: ";
				  int emOpt;
				  string profileID;

				  cin >> profileID;
				  //BankAccountProfile *profile = new BankAccountProfile(); // Change later when the above line is corrected
				  systemUser* userToEdit = userMap.at(profileID);
				  string checkType = userToEdit->getUserType();
				  if (checkType == "Administrator") {
					  cout << "Error! Admin can only modify users ot type employee" << endl;
				  }
				  if (checkType == "Employee") {
					  cout << "Error! ID entered belongs to employee, to edit your profile select option 4" << endl;
				  }
				  else {
					  cout << "**********************************" << endl;
					  cout << "        Editing Customer Info        " << endl;
					  cout << "1.) Change first name" << endl;
					  cout << "2.) Change last name" << endl;
					  cout << "3.) Change home phone number" << endl;
					  cout << "4.) Change cell phone number" << endl;
					  cout << "5.) Change email address" << endl;
					  cout << "6.) Change home address #1" << endl;
					  cout << "7.) Change home address #2" << endl;
					  cout << "8.) Change postal code" << endl;
					  cout << "9.) Change status in country" << endl;
					  cout << "10.) Logout" << endl;
					  cout << "**********************************" << endl;

					  cin >> emOpt;


					  BankAccountProfile *profile = profileMap.at(profileID);


					  if (emOpt == 1)
					  {
						  string inputName;
						  cout << "Enter new first name: ";
						  //cin >> inputName;
						   std::getline(std::cin, inputName);


						  profile->setFirstName(inputName);

						  cout << "First name changed..." << endl;
					  }
					  else if (emOpt == 2)
					  {
						  string inputName;
						  cout << "Enter new last name: ";
						  //cin >> inputName;
						   std::getline(std::cin, inputName);


						  profile->setLastName(inputName);
						  cout << "Last name changed..." << endl;
					  }
					  else if (emOpt == 3)
					  {
						  string inputPhoneNumber;
						  cout << "Enter new home phone number: ";
						  //cin >> inputPhoneNumber;
						   std::getline(std::cin, inputPhoneNumber);


						  profile->setHomePhoneNumber(inputPhoneNumber);
						  cout << "Home phone number changed..." << endl;
					  }
					  else if (emOpt == 4)
					  {
						  string inputPhoneNumber;
						  cout << "Enter new cell phone number: ";
						  //cin >> inputPhoneNumber;
						   std::getline(std::cin, inputPhoneNumber);


						  profile->setCellPhoneNumber(inputPhoneNumber);
						  cout << "Cell phone number changed..." << endl;
					  }
					  else if (emOpt == 5)
					  {
						  string inputEmail;
						  cout << "Enter new email address: ";
						  //cin >> inputEmail;
						   std::getline(std::cin, inputEmail);


						  profile->setEmailAddress(inputEmail);
						  cout << "Email address changed..." << endl;
					  }
					  else if (emOpt == 6)
					  {
						  string inputHomeAddress1;
						  cout << "Enter new home address 1: ";
						  //cin >> inputHomeAddress1;
						   std::getline(std::cin, inputHomeAddress1);


						  profile->setHomeAddress1(inputHomeAddress1);
						  cout << "Home address #1 changed..." << endl;
					  }
					  else if (emOpt == 7)
					  {
						  string inputHomeAddress2;
						  cout << "Enter new home address 2: ";
						 // cin >> inputHomeAddress2;
						  std::getline(std::cin, inputHomeAddress2);


						  profile->setHomeAddress2(inputHomeAddress2);
						  cout << "Home address #2 changed..." << endl;
					  }
					  else if (emOpt == 8)
					  {
						  string inputPostalCode;
						  cout << "Enter new postal code: ";
						  //cin >> inputPostalCode;
						   std::getline(std::cin, inputPostalCode);


						  profile->setPostalCode(inputPostalCode);
						  cout << "Postal code changed..." << endl;
					  }
					  else if (emOpt == 9)
					  {
						  string inputSIC;
						  cout << "Enter new status in country: ";
						  //cin >> inputSIC;
						   std::getline(std::cin, inputSIC);


						  profile->setStatusInCountry(inputSIC);
						  cout << "Status in country changed..." << endl;
					  }
					  else if (emOpt == 10)
					  {
						  // Logout
						  cout << "Logging out" << endl;
						  break;
					  }
				  }
			  }
			  else if (selection == 6) {

				  int opt;
				  cout << "**********************************" << endl;
				  cout << "        Transaction Menu        " << endl;
				  cout << "1.) Withdraw money from account" << endl;
				  cout << "2.) Deposit money in account" << endl;
				  cout << "3.) Check balance in account" << endl;
				  cout << "4.) Transfer money from one account to another" << endl;
				  cout << "5.) return" << endl;
				  cout << "**********************************" << endl;

				  AccountTransactionManager accTransactionManager;

				  cin >> opt;
				  if (opt == 1)
				  {
					  int amount;
					  string userID;
					  cout << "Enter user ID of owner: ";
					  cin >> userID;
					  cout << "Enter amount that you want to deposit: ";
					  cin >> amount;
					  BankAccountProfile* profile = profileMap.at(userID);
					  BankAccount account = profile->getListOfAccounts();
					  if ((account.getAccountNumber()) =="0") {
						  cout << "This user does not have a bank account" << endl;
					  }
					  else {

						  accTransactionManager.depositMoney(account, amount);
						  cout << amount << " deposited " << endl;
					  }
				  }
				  else if (opt == 2)
				  {
					  int amount;
					  string userID;
					  cout << "Enter user ID of owner: ";
					  cin >> userID;
					  cout << "Enter amount that you want to withdraw: ";
					  cin >> amount;
					  BankAccountProfile* profile = profileMap.at(userID);
					  BankAccount account = profile->getListOfAccounts();
					  if (account.getAccountNumber() == "0") {
						  cout << "This user does not have a bank account" << endl;
					  }
					  else {
						  accTransactionManager.withdrawMoney(account, amount);
						  cout << amount << " withdrawn " << endl;
					  }
				  }

				  else if (opt == 3)
				  {
					  cout << "Enter user ID of owner: ";
					  cin >> userID;
					  BankAccountProfile* profile = profileMap.at(userID);
					  BankAccount account = profile->getListOfAccounts();
					  if (account.getAccountNumber() == "0") {
						  cout << "This user does not have a bank account" << endl;
					  }
					  else {
						  cout << "Balance is " << accTransactionManager.checkBalance(account) << endl;
					  }
				  }
				  else if (opt == 4)
				  {
					  string toAccount;
					  int amount;
					  string id;
					  cout << "Enter owner's ID: ";
					  cin >> id;
					  BankAccountProfile* profile = profileMap.at(id);
					  BankAccount account = profile->getListOfAccounts();
					  cout << "Enter account ID of owner of account you want to transfer money to: ";
					  cin >> toAccount;
					  BankAccountProfile* profile2 = profileMap.at(toAccount);
					  BankAccount account2 = profile2->getListOfAccounts();

					  cout << "Enter amount that you want to withdraw: ";
					  cin >> amount;

					  accTransactionManager.transferMoney(account, account2, amount);
					  cout << amount << " transferred " << endl;
				  }
				  else if (opt == 5) {
					  cout << "back" << endl;
					  break;
				  }
			  }
			  else if (selection == 7) {
				  RegisterManager manager;
				   //CREATE BANK ACCOUNT
				   int bankit;
				   int balance;
				   string id;
				   cout << "**********************************" << endl;
				   cout << "        Create bank Account  " << endl;
				   cout << " Enter ID for customer: ";
				   cin >> id;
				   cout << "Enter starting balance";
				   cin >> balance;
				   string accNo = manager.generateAccountNumber();

				   BankAccount* newacc = new BankAccount(accNo);
				   newacc->deposit(balance);
				   profileMap.at(id)->setAccountNumber(accNo);
				   profileMap.at(id)->setListOfAccounts(accNo);

				   }
			  else if (selection == 8) {
				  //loans
				  // Loans
				  int option;
				  cout << "**********************************" << endl;
				  cout << "        Loan Menu        " << endl;
				  cout << "1.) Start new Loan" << endl;
				  cout << "2.) Approve Loan" << endl;
				  cout << "3.) Deny Loan" << endl;
				  cout << "**********************************" << endl;

				  cin >> option;
				  if (option == 1) {
					  std::string acctNum = "";
					  int loanAmount = 0;
					  cout << "Enter Account Number: " << endl;
					  cin >> acctNum;
					  cout << "Enter Loan Amount: " << endl;
					  cin >> loanAmount;
						
					  Loan newLoan = Loan(acctNum, int(loanAmount));
					  loanList.addLoanToList(newLoan);
					  cout << "Loan added!" << endl;
				  }
				  else if (option == 2) {
					  cout << "Outstanding Loans" << endl;
					  for (int i = 0; i < loanList.getLoans().size(); i++) {
						  cout << i << ": " << loanList.getLoans()[i].getAccountNumber() << endl;
					  }
					  cout << "Approve loan #: " << endl;
					  int loanNum = 0;
					  cin >> loanNum;
					  loanList.getLoans()[loanNum].approve();
					  cout << "Loan approved!" << endl;
				  }
				  else if (option == 3) {
					  cout << "Outstanding Loans" << endl;
					  for (int i = 0; i < loanList.getLoans().size(); i++) {
						  cout << i + ": " + std::string(loanList.getLoans()[i].getAccountNumber()) + " " << endl;
					  }
					  cout << "Deny loan #: " << endl;
					  int loanNum = 0;
					  cin >> loanNum;
					  loanList.getLoans()[loanNum].deny();
					  cout << "Loan denied!" << endl;
				  }
			  }
			  else if (selection == 9)
			  {
				  // Logout
				  cout << "Logging out. Goodbye! " << endl;
				  logout=false;
				  break;
			  }  
			  }
			}
	  
		  else if (userType == "Customer")
		  {
			  logout=true;
			  while(logout){
			  cout<<"Welcome Customer!!"<<endl;
			  cout << "**********************************" << endl;
			  cout << "        Customer Menu        " << endl;
			  cout << "1.) Edit Profile" << endl;
			  cout << "2.) Display account details" << endl;
			  cout << "3.) Transactions" << endl;
			  cout << "4.) Logout" << endl;
			  cout << "**********************************" << endl;
			  int pick;
			cin >> pick;
			string loggedInId = userID;
			if (pick == 1)
			{
				systemUser* userToEdit = userMap.at(loggedInId);
				string checkType = userToEdit->getUserType();
				int emOpt;
				if (checkType == "Administrator") {
					cout << "Error! Customer can't modify users of type admin" << endl;
				}
				if (checkType == "Employee") {
					cout << "Error! ID entered belongs to employee, can only edit your own profile" << endl;
				}
				else {
					cout << "**********************************" << endl;
					cout << "        Editing Your Info        " << endl;
					cout << "1.) Change first name" << endl;
					cout << "2.) Change last name" << endl;
					cout << "3.) Change home phone number" << endl;
					cout << "4.) Change cell phone number" << endl;
					cout << "5.) Change email address" << endl;
					cout << "6.) Change home address #1" << endl;
					cout << "7.) Change home address #2" << endl;
					cout << "8.) Change postal code" << endl;
					cout << "9.) Change status in country" << endl;
					cout << "10.) Logout" << endl;
					cout << "**********************************" << endl;

					cin >> emOpt;


					BankAccountProfile *profile = profileMap.at(loggedInId);


					if (emOpt == 1)
					{
						string inputName;
						cout << "Enter new first name: ";
						//cin >> inputName;
						 std::getline(std::cin, inputName);


						profile->setFirstName(inputName);

						cout << "First name changed..." << endl;
					}
					else if (emOpt == 2)
					{
						string inputName;
						cout << "Enter new last name: ";
						//cin >> inputName;
						 std::getline(std::cin, inputName);


						profile->setLastName(inputName);
						cout << "Last name changed..." << endl;
					}
					else if (emOpt == 3)
					{
						string inputPhoneNumber;
						cout << "Enter new home phone number: ";
						//cin >> inputPhoneNumber;
						 std::getline(std::cin, inputPhoneNumber);


						profile->setHomePhoneNumber(inputPhoneNumber);
						cout << "Home phone number changed..." << endl;
					}
					else if (emOpt == 4)
					{
						string inputPhoneNumber;
						cout << "Enter new cell phone number: ";
						//cin >> inputPhoneNumber;
						 std::getline(std::cin, inputPhoneNumber);


						profile->setCellPhoneNumber(inputPhoneNumber);
						cout << "Cell phone number changed..." << endl;
					}
					else if (emOpt == 5)
					{
						string inputEmail;
						cout << "Enter new email address: ";
						//cin >> inputEmail;
						 std::getline(std::cin, inputEmail);


						profile->setEmailAddress(inputEmail);
						cout << "Email address changed..." << endl;
					}
					else if (emOpt == 6)
					{
						string inputHomeAddress1;
						cout << "Enter new home address 1: ";
						//cin >> inputHomeAddress1;
						 std::getline(std::cin, inputHomeAddress1);


						profile->setHomeAddress1(inputHomeAddress1);
						cout << "Home address #1 changed..." << endl;
					}
					else if (emOpt == 7)
					{
						string inputHomeAddress2;
						cout << "Enter new home address 2: ";
						//cin >> inputHomeAddress2;
						 std::getline(std::cin, inputHomeAddress2);


						profile->setHomeAddress2(inputHomeAddress2);
						cout << "Home address #2 changed..." << endl;
					}
					else if (emOpt == 8)
					{
						string inputPostalCode;
						cout << "Enter new postal code: ";
						//cin >> inputPostalCode;
						 std::getline(std::cin, inputPostalCode);


						profile->setPostalCode(inputPostalCode);
						cout << "Postal code changed..." << endl;
					}
					else if (emOpt == 9)
					{
						string inputSIC;
						cout << "Enter new status in country: ";
						//cin >> inputSIC;
						 std::getline(std::cin, inputSIC);


						profile->setStatusInCountry(inputSIC);
						cout << "Status in country changed..." << endl;
					}
					else if (emOpt == 10)
					{
						// Logout
						cout << "Logging out" << endl;
						logout=false;
						break;
					}

				
				}
				}
			
			 else if (pick == 2)
			 {
				 //display account balance
				 cout << "Account Information" << endl;
				 BankAccountProfile* user = profileMap.at(loggedInId);
				 BankAccount acc = user->getListOfAccounts();
				 if (acc.getAccountNumber() == "0") {
					 cout << "Error! You have not opened a bank account yet" << endl;
				 }
				 else {
					 cout << "Account number: " << acc.getAccountNumber() << "balance: " << acc.getBalance() << endl;
				 }
			 }

			 else if (pick == 3)
			 {
				 int opt;
				 cout << "**********************************" << endl;
				 cout << "        Transaction Menu        " << endl;
				 cout << "1.) Withdraw money from account" << endl;
				 cout << "2.) Deposit money in account" << endl;
				 cout << "3.) Check balance in account" << endl;
				 cout << "4.) Transfer money from one account to another" << endl;
				 cout << "5.) return" << endl;
				 cout << "**********************************" << endl;

				 AccountTransactionManager accTransactionManager;

				 cin >> opt;
				 if (opt == 1)
				 {
					 int amount;
					 string userID;
					 cout << "Enter user ID of owner: ";
					 cin >> userID;
					 cout << "Enter amount that you want to deposit: ";
					 cin >> amount;
					 BankAccountProfile* profile = profileMap.at(userID);
					 BankAccount account = profile->getListOfAccounts();
					 if ((account.getAccountNumber()) == "0") {
						 cout << "This user does not have a bank account" << endl;
					 }
					 else {

						 accTransactionManager.depositMoney(account, amount);
						 cout << amount << " deposited " << endl;
					 }
				 }
				 else if (opt == 2)
				 {
					 int amount;
					 string userID;
					 cout << "Enter user ID of owner: ";
					 cin >> userID;
					 cout << "Enter amount that you want to withdraw: ";
					 cin >> amount;
					 BankAccountProfile* profile = profileMap.at(userID);
					 BankAccount account = profile->getListOfAccounts();
					 if (account.getAccountNumber() == "0") {
						 cout << "This user does not have a bank account" << endl;
					 }
					 else {
						 accTransactionManager.withdrawMoney(account, amount);
						 cout << amount << " withdrawn " << endl;
					 }
				 }

				 else if (opt == 3)
				 {
					 cout << "Enter user ID of owner: ";
					 cin >> userID;
					 BankAccountProfile* profile = profileMap.at(userID);
					 BankAccount account = profile->getListOfAccounts();
					 if (account.getAccountNumber() == "0") {
						 cout << "This user does not have a bank account" << endl;
					 }
					 else {
						 cout << "Balance is " << accTransactionManager.checkBalance(account) << endl;
					 }
				 }
				 else if (opt == 4)
				 {
					 string toAccount;
					 int amount;
					 string id;
					 cout << "Enter owner's ID: ";
					 cin >> id;
					 BankAccountProfile* profile = profileMap.at(id);
					 BankAccount account = profile->getListOfAccounts();
					 cout << "Enter account ID of owner of account you want to transfer money to: ";
					 cin >> toAccount;
					 BankAccountProfile* profile2 = profileMap.at(toAccount);
					 BankAccount account2 = profile2->getListOfAccounts();

					 cout << "Enter amount that you want to withdraw: ";
					 cin >> amount;

					 accTransactionManager.transferMoney(account, account2, amount);
					 cout << amount << " transferred " << endl;
				 }
				 else if (opt == 5) {
					 cout << "back" << endl;
					 break;
				 }
			 }
			 else if (pick == 4) {
				 cout << "Logging out.." << endl;
				 break;
			 }

		 
		  }
	  }
	
	  }
	  else if (choice == 2)
	  {
	 
		  cout << "Exiting..." << endl;
		  status = false;
		  return 0;
	  

		 /* string password;

		  cout << "Enter ID: " << endl;
		  cin >> ID;
		  //firstName = "003";

		  cout << "Enter password: " << endl;
		  cin >> password;
		  //password = "password";

		  AuthenticatedUser *authUser = server->loginUser(ID, password, userMap);*/

	  }

	


	  else{
		  cout << "invalid Entry, please select again" << endl;
  }
	  }
  return 0;
}

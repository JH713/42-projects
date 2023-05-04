#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <iostream>
#include <iomanip>

class Contact   
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNum;
	std::string secret;
public:
	Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNum, std::string secret);
	Contact();
	void SetContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNum, std::string secret);
	void DisplayContact(int idx) const;
};

#endif
#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNum, std::string secret)
	:firstName(firstName), lastName(lastName), nickname(nickname), phoneNum(phoneNum), secret(secret) 
{
}

Contact::Contact()
	:firstName(""), lastName(""), nickname(""), phoneNum(""), secret("")
{
}

void Contact::SetContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNum, std::string secret)
{
	this->firstName = firstName; 
	this->lastName = lastName; 
	this->nickname = nickname; 
	this->phoneNum = phoneNum; 
	this->secret = secret;
}

void Contact::DisplayContact(int idx) const
{
	std::cout << '|';
	std::cout << std::setw(10) << idx << '|';
	if (firstName.length() > 10)
		std::cout << firstName.substr(0, 9) << '.' << '|';
	else
		std::cout << std::setw(10) << firstName << '|';
	if (lastName.length() > 10)
		std::cout << lastName.substr(0, 9) << '.' << '|';
	else
		std::cout << std::setw(10) << lastName << '|';
	if (nickname.length() > 10)
		std::cout << nickname.substr(0, 9) << '.' << '|';
	else
		std::cout << std::setw(10) << nickname << '|';
	std::cout << std::endl;
}
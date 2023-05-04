#include "PhoneBook.hpp"

bool GetStr(std::string &str)
{
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << "\nEOF has been reached." << std::endl;
		exit(1);
	}
	if (str == "")
	{
		std::cout << "Contact cannot be saved. Empty fields are not allowed." << std::endl;
		return (false);
	}
	for (int i = 0; i < (int) str.length(); i++)
	{
		if (isprint(str[i]) == 0)
		{
			std::cout << "The input string contains unprintable characters." << std::endl;
			return (false);
		}
	}
	return (true);
}

PhoneBook::PhoneBook()
{
	for(int i = 0; i < 8; i++)
		contacts[i] = Contact();
	oldestIdx = 0;
	contactNum = 0;
}

void PhoneBook::AddContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNum;
	std::string secret;

	std::cout << "First name: ";
	if(!GetStr(firstName))
		return ;
	std::cout << "Last name: ";
	if(!GetStr(lastName))
		return ;
	std::cout << "Nickname: ";
	if(!GetStr(nickname))
		return ;
	std::cout << "Phone number: ";
	if(!GetStr(phoneNum))
		return ;
	std::cout << "Darkest secret: ";
	if(!GetStr(secret))
		return ;
	contacts[oldestIdx].SetContact(firstName, lastName, nickname, phoneNum, secret);
	if (oldestIdx == 7)
		oldestIdx = 0;
	else
		oldestIdx++;
	if (contactNum < 8)
		contactNum++;
}

void PhoneBook::DisplayPhoneBook() const
{
	if (contactNum == 0)
	{
		std::cout << "No contacts found." << std::endl;
		return ;
	}
	std::cout << '|';
	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << '|';
	std::cout << std::endl;
	for (int i = 0; i < contactNum; i++)
		contacts[i].DisplayContact(i);
	std::cout << "Please enter the index of the entry to display: ";
	std::string idxStr;
	int index;
	while (1)
	{  
		std::getline(std::cin, idxStr);
		if (std::cin.eof())
		{
			std::cout << "\nEOF가 입력되었습니다." << std::endl;
			exit(1);
		}
		if (idxStr == "" || idxStr.length() > 1)
		{
			std::cout << "Invalid index. Please enter a valid index: ";
			continue;
		}
		index = std::atoi(idxStr.c_str());
		if (index < 0 || index >= contactNum)
		{
			std::cout << "Index out of range. Please enter a valid index: ";
			continue;
		}
		contacts[index].DisplayContact(index);
		break;
	}
}
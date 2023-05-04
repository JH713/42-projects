#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <cstdlib>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		oldestIdx;
	int		contactNum;
public:
	PhoneBook();
	void AddContact();
	void DisplayPhoneBook() const;
};

#endif
#include "PhoneBook.hpp"

int main(void)
{
	std::string command;
	PhoneBook	phonebook;
	
	while (1)
	{
		std::cout << "Please enter a command(ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command); 
		if (std::cin.eof())
		{
			std::cout << "\nEOF가 입력되었습니다." << std::endl;
			return (1);
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phonebook.AddContact();
		else if (command == "SEARCH")
			phonebook.DisplayPhoneBook();
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}
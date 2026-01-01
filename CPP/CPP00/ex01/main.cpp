
#include <iostream>
#include "phoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string input;

	while (true)
	{
		if (!std::cin.eof())
			std::cout << "\033[33mEnter a contact option (ADD, SEARCH, EXIT): \033[0m";
			
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			phoneBook.addContact();
		}
		else if (input == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (input == "EXIT")
		{
			std::cout << "\n   Exiting program...\n" << std::endl;
			break;
		}
		else
			std::cout << "\n   Invalid option. Please try again.\n" << std::endl;
		if (std::cin.eof())
			break;
	}
	return 0;
}
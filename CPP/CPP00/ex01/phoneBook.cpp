
#include "phoneBook.hpp"
#include <iostream>
#include <cstdlib>

int	PhoneBook::readInput(std::string &input)
{
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input.empty())
			std::cout << "\nInput cannot be empty. Try again: ";
		else
			break;
	}
	return (1);
}

void	PhoneBook::displayElement(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void PhoneBook::addContact()
{
	static int i = 0;

	std::cout << "\n Enter details for contact " << i + 1 << ":\n" << std::endl;

	std::cout << " First Name: ";
	if (!readInput(contacts[i].getFirstName()))
		return;

	std::cout << " Last Name: ";
	if (!readInput(contacts[i].getLastName()))
		return;

	std::cout << " Nickname: ";
	if (!readInput(contacts[i].getNickname()))
		return;

	std::cout << " Phone Number: ";
	if (!readInput(contacts[i].getPhoneNumber()))
		return;

	std::cout << " Darkest Secret: ";
	if (!readInput(contacts[i].getDarkestSecret()))
		return;

	i = (i + 1) % 8;
	std::cout << std::endl;
}

void	PhoneBook::showMenu()
{
	std::cout << "\n Searching contacts...\n" << std::endl;
	displayElement("Index");std::cout << " | ";
	displayElement("First Name");std::cout << " | ";
	displayElement("Last Name");std::cout << " | ";
	displayElement("Nickname");
	std::cout << "\n-----------|------------|------------|----------" << std::endl;

	for (int i = 0; i < 8 && !contacts[i].getFirstName().empty(); i++)
	{
		std::cout << i+1 << "         " << " | ";
		displayElement(contacts[i].getFirstName());
		std::cout << " | ";
		displayElement(contacts[i].getLastName());
		std::cout << " | ";
		displayElement(contacts[i].getNickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::searchContact()
{
	std::string index;
	int			i;
	
	showMenu();
	std::cout << "\n Enter the index to view details: ";

	readInput(index);
	i = std::atoi(index.c_str());

	if (i < 1 || i > 8 || contacts[i - 1].getFirstName().empty())
	{
		std::cout << std::endl << "\nInvalid index. Returning.\n" << std::endl;
	}
	else
	{
		std::cout << "\n   Contact details for index " << i << ":\n" << std::endl;
		std::cout << " First Name: " << contacts[i-1].getFirstName() << std::endl;
		std::cout << " Last Name: " << contacts[i-1].getLastName() << std::endl;
		std::cout << " Nickname: " << contacts[i-1].getNickname() << std::endl;
		std::cout << " Phone Number: " << contacts[i-1].getPhoneNumber() << std::endl;
		std::cout << " Darkest Secret: " << contacts[i-1].getDarkestSecret() << std::endl << std::endl;
	}
}

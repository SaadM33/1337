

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:

		Contact contacts[8];
	
		// Helper functionalidads, hail hitler
		int		readInput(std::string &input);
		void	displayElement(std::string str);
		void	showMenu();

	public:
	
		void	addContact();
		void	searchContact();

	};

#endif
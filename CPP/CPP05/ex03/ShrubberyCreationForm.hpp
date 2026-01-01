
#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>


class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void	execute( const Bureaucrat & executor ) const;
};

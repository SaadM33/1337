
#pragma once

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void	execute( const Bureaucrat & executor ) const;
};


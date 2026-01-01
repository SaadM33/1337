
#pragma once

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern( const Intern &other );
		Intern &operator=( const Intern &other );
		~Intern();

		AForm *makeForm(std::string name, std::string target) const;
};


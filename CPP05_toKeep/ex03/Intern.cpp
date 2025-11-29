
#include "Intern.hpp"


Intern::Intern()
{
}

Intern::Intern( const Intern &other )
{
	(void)other;
}

Intern &Intern::operator=( const Intern &other )
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string name, std::string target) const
{
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm		*addrs[3] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};

	AForm *result = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			result = addrs[i];
			std::cout << "Intern creates " << name << std::endl;
		}
		else
			delete addrs[i];
	}
	if (result == NULL)
		std::cerr << "Unknown form type: " << name << std::endl;
	return result;
}

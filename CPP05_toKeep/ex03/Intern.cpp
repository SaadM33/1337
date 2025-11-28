
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
	
}

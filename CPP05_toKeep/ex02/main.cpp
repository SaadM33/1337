
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b("Akhenouch", 1);
	RobotomyRequestForm r("Target1");
	PresidentialPardonForm p("Target2");
	ShrubberyCreationForm s("Target3");

	b.signForm(r);
	b.signForm(p);
	b.signForm(s);

	b.executeForm(r);
	b.executeForm(p);
	b.executeForm(s);

	return 0;
}
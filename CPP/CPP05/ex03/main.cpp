
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm* unknown;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "Fry");
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	unknown = someRandomIntern.makeForm("free money", "Nobody");

	std::cout << std::endl;

	Bureaucrat boss("Boss", 1);

	boss.signForm(*ppf);
	boss.executeForm(*ppf);

	delete rrf;
	delete ppf;
	delete scf;
	delete unknown;

	return 0;
}
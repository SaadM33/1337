
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("robotomy", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute( const Bureaucrat & executor ) const
{
	if (!this->getSigned())
		throw RobotomyRequestForm::FormNotSignedException();

	if (executor.getGrade() > this->getGradeToExec())
		throw RobotomyRequestForm::GradeTooLowException();

	std::cout << "*drilling noises*" << std::endl;
	std::srand(time(0));
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed on " << this->target << "." << std::endl;
}

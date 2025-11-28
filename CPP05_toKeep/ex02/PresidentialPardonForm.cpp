
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("pardon", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm(other), target(other.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute( const Bureaucrat & executor ) const
{
	if (!this->getSigned())
		throw PresidentialPardonForm::FormNotSignedException();

	if (executor.getGrade() > this->getGradeToExec())
		throw PresidentialPardonForm::GradeTooLowException();

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

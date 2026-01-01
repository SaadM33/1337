
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	this->isSigned = false;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
}

std::string	AForm::getName() const
{
	return this->name;
}

bool	AForm::getSigned() const
{
	return this->isSigned;
}

int		AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int		AForm::getGradeToExec() const
{
	return this->gradeToExec;
}

void		AForm::beSigned( const Bureaucrat& bcrat )
{
	if (bcrat.getGrade() <= this->gradeToSign)
		this->isSigned = 1;
	else
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form Name: " << form.getName() << "\n";
	os << "Signed: ";
	if (form.getSigned())
		os << "Yes\n";
	else
		os << "No\n";
	os << "Grade Required to Sign: " << form.getGradeToSign() << "\n";
	os << "Grade Required to Execute: " << form.getGradeToExec() << "\n";
	return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm Exception: Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm Exception: Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "AForm Exception: Form is not signed";
}


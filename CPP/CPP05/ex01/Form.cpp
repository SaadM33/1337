
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExec) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form()
{
}

std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getSigned() const
{
	return this->isSigned;
}

int		Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int		Form::getGradeToExec() const
{
	return this->gradeToExec;
}

void		Form::beSigned( const Bureaucrat& bcrat )
{
	if (bcrat.getGrade() <= this->gradeToSign)
		this->isSigned = 1;
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
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

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Exception: Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Exception: Grade is too low";
}



#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src) : name(src.name)
{
	this->grade = src.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src )
{
	if (this != &src)
	{
		this->grade = src.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string	Bureaucrat::getName() const
{
	return  this->name;
}

int			Bureaucrat::getGrade() const
{
	return this->grade;
}

void		Bureaucrat::inc()
{
	if (this->grade -1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void		Bureaucrat::dec()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high ( < 1 )";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low ( > 150 )";
}

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name)
{
	this->grade = grade; // check execption
}

Bureaucrat::Bureaucrat( const Bureaucrat &src) : name(src.name)
{
	this->grade = src.grade; // check execption
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src )
{
	if (this != &src)
	{
		this->grade = src.grade; // check execption
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
	this->grade--; // check here
}

void		Bureaucrat::dec()
{
	this->grade++; // check here
}

std::ostream &operator<<( std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return out;
}
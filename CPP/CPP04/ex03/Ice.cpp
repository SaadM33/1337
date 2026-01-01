
#include <iostream>
#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria(other)
{
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
	AMateria *newIce = new Ice();
	return newIce;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

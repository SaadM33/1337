
#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	brain->setIdea("rough rough");
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copied" << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		brain = new Brain();
		*brain = *other.brain;
		
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "3AW 3AW!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
	delete this->brain;
}
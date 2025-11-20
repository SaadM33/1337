
#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	brain->setIdea("i love tuna");
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copied" << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		brain = new Brain();
		*brain = *other.brain;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
	delete brain;

}

void Cat::makeSound() const
{
	std::cout << "MEOW MEOW!" << std::endl;
}
#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal created" << std::endl;
	this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "AAnimal copied" << std::endl;
	this->type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destroyed" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal sound!" << std::endl;
}
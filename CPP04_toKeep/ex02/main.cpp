
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>


int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	// AAnimal test; // will not compile because AAnimal is an abstract class

	delete j;
	delete i;

	return 0;
}
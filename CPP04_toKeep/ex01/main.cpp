
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>


int main()
{
	std::cout << "Creating array of animals..." << std::endl;
	Animal *arr[6];

	for (int i = 0; i < 6 ; i++)
	{
		if (i < 3)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	std::cout << "\nTesting polymorphism:" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i]->getType() << ": ";
		arr[i]->makeSound();
	}

	Dog basic;
	{
		Dog tmp = basic;
	}
	basic.makeSound();


	std::cout << "\nCleaning up..." << std::endl;
	for (int i = 0; i < 6; i++)
	{
		delete arr[i];
	}
	
	return 0;
}

#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> Obj(5);

	std::cout << "default value: " << Obj[0] << std::endl;
	
	for (unsigned int i = 0; i < Obj.size(); i++)
		Obj[i] = 'A' + i; // implicit conversion from char to int, awdi no error

	for (unsigned int i = 0; i < Obj.size(); i++)
		std::cout << Obj[i] << std::endl;

	try
	{
		std::cout << Obj[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: Index out of bounds" << std::endl;
	}

	return 0;
}

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Alice", 42);
	std::cout << a;

	try
	{
		Bureaucrat b("maggot", 152);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		std::cout << "Caught exception for grade too low, would have crashed\n";
	}

	a.inc();
	std::cout << a;

	return 0;
}
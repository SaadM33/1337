
#include "Span.hpp"
#include <iostream>


int	main( void )
{
	Span sp(20);
	try 
	{
		sp.addNumber(10);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(6);
		sp.addNumber(22);
		sp.addNumber(1);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << "Adding a range of numbers..." << std::endl;

	std::vector<int> large_vector;
	large_vector.push_back(5);
	large_vector.push_back(10);
	large_vector.push_back(15);
	large_vector.push_back(20);
	large_vector.push_back(25);

	try
	{
		sp.addRange(large_vector.begin(), large_vector.end());
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	return 0;
}

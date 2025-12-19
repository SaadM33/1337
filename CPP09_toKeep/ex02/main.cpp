
#include "PmergeMe.hpp"


int isValidInput(const std::string &input)
{
	for (size_t i = 0; i < input.length(); ++i)
	{
		if (!isdigit(input[i]) && input[i] != ' ')
			return 0;
	}
	return 1;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " sequence" << std::endl;
		return 1;
	}
	
	std::string	line = av[1];

	if (!isValidInput(line))
	{
		std::cerr << "Error: Invalid input" << std::endl;
		return 1;
	}

	try
	{
		
	}
	catch (	std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;	
	}

	return 0;
}

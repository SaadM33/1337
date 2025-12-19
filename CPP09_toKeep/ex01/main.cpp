
#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " expression" << std::endl;
		return 1;
	}
	
	std::string	line = av[1];

	if (!isValidRPN(line))
	{
		std::cerr << "Error: Invalid RPN expression" << std::endl;
		return 1;
	}

	try
	{
		int result = evaluateRPN(line);
		std::cout <<  result << std::endl;
	}
	catch (	std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;	
	}

	return 0;
}

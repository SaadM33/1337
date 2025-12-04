
#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./scalar_converter <literal_value>" << std::endl;
		return 1;
	}
	
	ScalarConverter::convert(av[1]);
	
	return 0;
}
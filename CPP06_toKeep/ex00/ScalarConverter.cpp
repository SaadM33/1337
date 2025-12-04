
#include "ScalarConverter.hpp"

//  char
//  int
//  float
//  double

void	ScalarConverter::convert( std::string literal)
{
	// char 
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		std::cout << "Char: " << literal[0] << std::endl;
	}
	else
	{
	}
	std::cout << "Char: " << static_cast<char>(std::atof(literal.c_str())) << std::endl;


	std::cout << "Int: " << static_cast<int>(std::atof(literal.c_str())) << std::endl;
	std::cout << "Float: " << static_cast<float>(std::atof(literal.c_str())) << std::endl;
	std::cout << "Double: " << static_cast<double>(std::atof(literal.c_str())) << std::endl;
}
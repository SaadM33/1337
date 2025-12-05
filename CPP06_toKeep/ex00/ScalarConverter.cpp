
#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter& other )
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& rhs )
{
	(void)rhs;
	return *this;
}

int		is_valid_literal( std::string literal )
{
	if (literal.empty())
		return 0;
	
	if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
		literal == "nanf" || literal == "+inff" || literal == "-inff")
		return 1;
	
	if (literal.length() == 1 && !isdigit(literal[0]))
		return 1;

	char *endptr;
	std::strtod(literal.c_str(), &endptr);

	if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0'))
		return 0;

	return 1;
}

void	ScalarConverter::convert( std::string literal)
{
	if (!is_valid_literal(literal))
	{
		std::cerr << "Invalid literal" << std::endl;
		return;
	}

	double		value;
	char		c;
	int			i;
	float		f;
	double		d;

	if (literal.length() == 1 && !isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else
		value = std::atof(literal.c_str());	

	c = static_cast<char>(value);
	i = static_cast<int>(value);
	f = static_cast<float>(value);
	d = static_cast<double>(value);

	// char
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible";
	else if (!isprint(c))
		std::cout << "Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;

	// int
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << std::endl;

	// float
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	// double
	std::cout << "double: " << std::fixed <<  std::setprecision(1) << d << std::endl;
}
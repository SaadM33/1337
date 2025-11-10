
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = src.getRawBits();
}

Fixed::Fixed( const int value) : value(value)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fvalue)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(fvalue * (1 << this->width));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
	return ;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << this->width));
}

int		Fixed::toInt( void ) const
{
	return (this->value >> this->width);
}

Fixed	&Fixed::operator=( Fixed const & operand )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = operand.getRawBits();
	return *this;
}
// • A member function float toFloat( void ) const;
// that converts the fixed-point value to a floating-point value.
// • A member function int toInt( void ) const;
// that converts the fixed-point value to an integer value.
// And add the following function to the Fixed class files:
// • An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter.
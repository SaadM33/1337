
#include "Fixed.hpp"
#include <iostream>

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

Fixed	&Fixed::operator=( Fixed const & operand )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = operand.getRawBits();
	return *this;
}

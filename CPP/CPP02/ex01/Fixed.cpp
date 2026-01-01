
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
	*this = src;
}

Fixed::Fixed( const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value * (1 << this->f_bits);
}

Fixed::Fixed(const float fvalue)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(fvalue * (1 << this->f_bits));
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
	return ((float)this->value / (1 << this->f_bits));
}

int		Fixed::toInt( void ) const
{
	return (this->value / (1 << this->f_bits));
}

Fixed	&Fixed::operator=( Fixed const & operand )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = operand.value;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}


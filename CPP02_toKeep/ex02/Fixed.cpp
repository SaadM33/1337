
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : value(0)
{
	return ;
}

Fixed::Fixed( Fixed const &src)
{
	*this = src;
}

Fixed::Fixed( const int value)
{
	this->value = value * (1 << this->f_bits);
}

Fixed::Fixed(const float fvalue)
{
	this->value = roundf(fvalue * (1 << this->f_bits));
}

Fixed::~Fixed( void )
{
	return ;
}

int	Fixed::getRawBits( void ) const
{
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
	this->value = operand.value;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}

bool	Fixed::operator>( Fixed const &rhs ) const
{
	if (this->value > rhs.value)
		return true;
	else
		return false;
}

bool	Fixed::operator<( Fixed const &rhs ) const
{
	if (this->value < rhs.value)
		return true;
	else
		return false;
}

bool	Fixed::operator>=( Fixed const &rhs ) const
{
	return this->value >= rhs.value;
}

bool	Fixed::operator<=( Fixed const &rhs ) const
{
	return this->value <= rhs.value;
}

bool 	Fixed::operator==( Fixed const &rhs ) const
{
	return this->value == rhs.value;
}

bool	Fixed::operator!=( Fixed const &rhs ) const
{
	return this->value != rhs.value;
}

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	return Fixed( (this->toFloat()) * (rhs.toFloat()) );
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	return Fixed( (this->toFloat()) / (rhs.toFloat()) );
}

Fixed	&Fixed::operator++( void )
{
	this->value++;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	old = *this;
	this->value++;
	return old;
}

Fixed	&Fixed::operator--( void )
{
	this->value--;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed	old = *this;
	this->value--;
	return old;
}

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed const &Fixed::min( Fixed const &a, Fixed const &b )
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed const &Fixed::max( Fixed const &a, Fixed const &b )
{
	if (a > b)
		return a;
	else
		return b;
}


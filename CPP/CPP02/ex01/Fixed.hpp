
#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class	Fixed
{

	private:

		int					value;
		static const int	f_bits = 8;

	public:

		Fixed( void );
		Fixed( const int value);
		Fixed( const float fvalue);
		Fixed( Fixed const &src );
		~Fixed( void );

		Fixed	&operator=( Fixed const & rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream &operator<<( std::ostream & o, Fixed const & obj);

#endif
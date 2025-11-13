
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

		bool	operator>( Fixed const & rhs ) const;
		bool	operator<( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;

		Fixed	operator+( Fixed const & rhs ) const;
		Fixed	operator-( Fixed const & rhs ) const;
		Fixed	operator*( Fixed const & rhs ) const;
		Fixed	operator/( Fixed const & rhs ) const;

		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed	&min( Fixed &a, Fixed &b );
		static Fixed	const &min( Fixed const &a, Fixed const &b );
		static Fixed	&max( Fixed &a, Fixed &b );
		static Fixed	const &max( Fixed const &a, Fixed const &b );

};

std::ostream &operator<<( std::ostream & o, Fixed const & obj);

#endif
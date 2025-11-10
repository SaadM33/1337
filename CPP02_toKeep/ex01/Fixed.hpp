
#ifndef FIXED_H
#define FIXED_H

class	Fixed
{

	private:

		int					value;
		static const int	width = 8;

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

#endif
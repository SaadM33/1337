
#pragma once

template <typename T>
class Array
{
	private:
		
		T	*arr;
		unsigned int	len;
	
	public:

		Array( void );
		Array( unsigned int n );
		Array( const Array &other );
		Array &operator=( const Array &other );
		~Array( void );

		unsigned int	size( void ) const;

		T &operator[] (int index);
		const T &operator[] (int index) const;

};

#include "Array.tpp"

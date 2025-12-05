
#pragma once

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:

		Serializer( void );
		~Serializer( void );
		Serializer( Serializer const & src );
		Serializer & operator=( Serializer const & rhs );

	public:

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

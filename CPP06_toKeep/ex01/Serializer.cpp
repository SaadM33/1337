
#include "Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::~Serializer( void ) {}

Serializer::Serializer( Serializer const & src )
{
	(void)src;
}

Serializer & Serializer::operator=( Serializer const & rhs )
{
	(void)rhs;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	res = reinterpret_cast<uintptr_t>(ptr);
	return res;
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data*	res = reinterpret_cast<Data*>(raw);
	return res;
}
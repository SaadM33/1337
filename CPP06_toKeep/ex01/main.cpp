
#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main( void )
{
	Data		data;

	uintptr_t	serialized;
	Data*		deserialized;

	data.n = 42;

	serialized = Serializer::serialize(&data);
	deserialized = Serializer::deserialize(serialized);

	std::cout << "serialized: " << reinterpret_cast<Data *>(serialized) << std::endl;
	std::cout << "deserialized : " << deserialized << std::endl;

	std::cout << "data.n: " << data.n << std::endl;
	std::cout << "deserialized->n: " << deserialized->n << std::endl;
	return 0;
}
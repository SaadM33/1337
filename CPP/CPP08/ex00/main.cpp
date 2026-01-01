
#include "easyfind.hpp"

int	main( void )
{
	std::vector<int>	v;

	for (int i = 0; i < 10; i++)
		v.push_back(i + 1);
	try
	{
		easyfind(v, 5);
		easyfind(v, 30);
		easyfind(v, 100);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

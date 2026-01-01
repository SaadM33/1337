
#include "Zombie.hpp"
#include <iostream>

int	main()
{
	Zombie *horde = Zombie::zombieHorde(5, "jou7a");

	for (int i = 0; i < 5; i++)
		horde[i].announce();

	delete[] horde;
	return 0;
}

#include <iostream>
#include "Zombie.hpp"

int	main()
{
	Zombie *zoom = Zombie::newZombie("ait lmalloc");
	zoom->announce();
	delete zoom;
	
	Zombie::randomChump("bou jem3a");

	return 0;
}


#include "Zombie.hpp"

void	Zombie::randomChump(std::string name)
{
	Zombie		goon(name);
	goon.announce();
}
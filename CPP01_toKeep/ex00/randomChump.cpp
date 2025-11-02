

#include "Zombie.hpp"

void	Zombie::randomChump(std::string name)
{
	Zombie goon;
	goon.name = name;
	goon.announce();
}
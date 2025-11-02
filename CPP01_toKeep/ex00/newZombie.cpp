
#include "Zombie.hpp"


Zombie*	Zombie::newZombie(std::string name)
{
	Zombie *zomdier = new Zombie;
	zomdier->name = name;
	return zomdier;
}

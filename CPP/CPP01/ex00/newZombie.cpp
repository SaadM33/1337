
#include "Zombie.hpp"


Zombie*	Zombie::newZombie(std::string name)
{
	Zombie *zomdier = new Zombie(name);
	return zomdier;
}

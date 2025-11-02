
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string str)
{
	name = str;
	weapon = NULL;
}

void	HumanB::setWeapon(Weapon &weap)
{
	weapon = &weap;
}

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
	else
		std::cout << name << " is maidenless" << std::endl;
}

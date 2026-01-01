
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weap) : weapon(weap)
{
	this->name = name;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}
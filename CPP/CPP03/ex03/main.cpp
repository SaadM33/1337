
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

int main( void )
{
	DiamondTrap diamond("RADAHN");
	
	std::cout << "DiamondTrap Stats -- HP: " << diamond.hp << ", FP: " << diamond.fp << ", ATK: " << diamond.atk << std::endl;

	diamond.attack("MALLENIA");
	diamond.takeDamage(30);
	diamond.beRepaired(15);
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();

	std::cout << "DiamondTrap Stats -- HP: " << diamond.hp << ", FP: " << diamond.fp << ", ATK: " << diamond.atk << std::endl;
	
	return 0;
}